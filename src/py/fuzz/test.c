#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc,char *argv[]){
	printf("%d %d %d\n",PROT_READ,PROT_WRITE,PROT_EXEC);
	return 0;
}
