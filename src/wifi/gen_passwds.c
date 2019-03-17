#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

#define N 16

int buf[N];
char cbuf[N];

void print_perm(int n);
void perm_sub(int n,int m);
void repeat_perm(int n);

int main(int argc,char *argv[]){
	FILE *fp;
	fp=fopen("./pass.lst","w+");
	//fwrite("aaaa",1,4,fp);
	//fclose(fp);
	int i,j,k;
	char *pass=(char *)malloc(0);
	//for(i=1;i<5+1;i++){
	//	pass=(char *)realloc(pass,i);
	//	for(j=0;j<pow(10,i);j++){
	//		fprintf(fp,"%c\n",0x30+j);
	//	}
	//}
	//for(i=0;i<10;i++){
	//	for(j=0;j<10;j++){
	//		for(k=0;k<10;k++){
	//			fprintf(fp,"%c%c%c\n",0x30+i,0x30+j,0x30+k);
	//		}
	//	}
	//}
	//char *s;
	//s=(char *)malloc(4);
	//strcat(s,"B");
	//printf("%s\n",s);
	for(i=5;i<6;i++){
		repeat_perm(i);
	}
	fclose(fp);
	return 0;
}

void print_perm(int n){
	int i;
	for(i=0;i<n;i++){
		printf("%c",cbuf[i]);
	}
	printf("\n");
}

void perm_sub(int n,int m){
	if(n==m){
		print_perm(n);
	}else{
		int i;
		/*for(i=0;i<=9;i++){
			buf[m]=i;
			perm_sub(n,m+1);
		}*/
		for(i=0x41;i<0x61+26;i++){
			if(i==0x41+26){
				i=0x61;
			}
			cbuf[m]=(char)i;
			perm_sub(n,m+1);
		}
	}
}

void repeat_perm(int n){
	if(n>0 || n<N) perm_sub(n,0);
}


