#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void handle_client(int c){
	char buf[100];
	snprintf(buf, sizeof(buf), "fd of client socket = %d\n",c);
	send(c, buf, strlen(buf), 0);
}

int main(int argc,char *argv[]){
	int s,c;
	struct sockaddr_in addr;
	int port;
	int pid;

	port = atoi(argv[1]);

	s = socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	bind(s, (struct sockaddr *)&addr,sizeof(addr));

	listen(s,5);

	while(1){
		c = accept(s, NULL, NULL);
		pid = fork();
		if(pid == -1){
			exit(1);
		}else if(pid==0){
			close(s);
			handle_client(c);
			close(c);
			return 0;
		}else{
			close(c);
			waitpid(pid, NULL, 0);
		}
	}
}
