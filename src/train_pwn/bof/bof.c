#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
	char buf[100];
	printf("buf = %p\n",buf);
	strcpy(buf,argv[1]);
	puts(buf);
	return 0;
}
