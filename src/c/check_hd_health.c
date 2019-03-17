#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <atasmart.h>  /* libatasmart */

void usage(const char *command) {
  printf("Usage: %s DEVICE\n", command);
}

int get_hd_health(const char *disk) {
  int ret = -1;
  SkDisk *skdisk;
  SkBool smart_available = 0;
  SkBool disk_awake = 0;
  SkBool disk_status = 0;
  uint64_t disk_temp = 0;
  uint64_t disk_ontime = 0;

  if (sk_disk_open(disk, &skdisk) < 0) {
    fprintf(stderr, "Failed to open disk %s: %s(%d)\n", disk, strerror(errno), errno);
    return -1;
  }

  if (sk_disk_smart_is_available(skdisk, &smart_available) < 0) {
    fprintf(stderr, "Failed to query whether SMART is available %s: %s(%d)\n", disk, strerror(errno), errno);
    goto done;
  }
  if (!smart_available) {
    fprintf(stderr, "%s is not support SMART\n", disk);
    goto done;
  }

  if (sk_disk_smart_read_data(skdisk) < 0) {
    fprintf(stderr, "Failed to read SMART data %s: %s(%d)\n", disk, strerror(errno), errno);
    goto done;
  }

  if (sk_disk_check_sleep_mode(skdisk, &disk_awake) < 0) {
    fprintf(stderr, "Failed to get sleep mode\n");
  } else {
    printf("drive is %s\n", disk_awake ? "active" : "sleep");
  }

  ret = 0;
  if (sk_disk_smart_get_temperature(skdisk, &disk_temp) == 0) {
    uint64_t celsius = (disk_temp - 273150) / 1000;  /* convert milli kelvin to celsius */
    printf("drive temperture: %zu C\n", celsius);
  }

  if (sk_disk_smart_get_power_on(skdisk, &disk_ontime) == 0) {
    unsigned long long onhour = disk_ontime / 1000 / 3600;
    printf("drive power on hour: %llu h\n", onhour);
  }

  if (sk_disk_smart_status(skdisk, &disk_status) == 0) {
    printf("drive status: %s\n", disk_status ? "GOOD" : "BAD");
  }

done:
  sk_disk_free(skdisk);

  return ret;
}

int main(int argc, char *argv[]) {
  int ret;

  if (argc <= 1) {
    usage(argv[0]);
    return 1;
  }

  ret = get_hd_health(argv[1]);

  return ret;
}
