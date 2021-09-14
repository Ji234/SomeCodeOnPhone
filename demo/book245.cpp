//packaging the socket client by c language

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int connecttoserver(const char *serverip,const int port){
	int sockfd =socket(AF_INET,SOCK_STREAM,0);
	struct hostent* h;

	if((h=gethostbyname(serverip))==0){
		perror("gethostbyname");
		close(sockfd);
		return -1;
	}
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(port);
	memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);

	if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0){
		perror("connect");
		close(sockfd);
		return -1;
	}
	return sockfd;
}
int main(int argc,char* argv[]){
	if(argc!=3){
		printf("please input like 127.0.0.1 5005");
		return -1;
	}
	int socketfd;
	socketfd=connecttoserver(argv[1],atoi(argv[2]));
	int iret;
	char buffer[1024];
	for(int i=0;i<5;i++){
		memset(buffer,0,sizeof(buffer));
		sprintf(buffer,"this is No.%d massage",i);
		if((iret=send(socketfd,buffer,sizeof(buffer),0))<=0) break;
		printf("this is No.%s massage\n",buffer);

		memset(buffer,0,sizeof(buffer));
		if(iret=recv(socketfd,buffer,sizeof(buffer),0)<=0) break;
		printf("received:%s\n",buffer);
	}
	close(socketfd);
}
























