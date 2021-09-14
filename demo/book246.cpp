//packaging the socket of the server

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>

int conecttoclient(int port){
	int socketfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(port);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(socketfd,(struct sockaddr*)&servaddr,sizeof(servaddr))!=0){
		perror("bind");
		close(socketfd);
		return -1;
	}
	if(listen(socketfd,5)!=0){
		perror("listen");
		close(socketfd);
		return -1;
	}
	return socketfd;
}

int main(int argc,char *argv[]){
	if(argc!=2){printf("please input a part like 5005\n");return -1;}
	
	int socketfd=conecttoclient(atoi(argv[1]));
	if(socketfd<0) printf("init failed had been exit\n");
	int clientfd;
	//struct sockaddr_in clientaddr;
	//int socklen=sizeof(clientaddr);
	if((clientfd=accept(socketfd,0,0))<=0){printf("failed to accpet the clientfd\n");close(socketfd);return -1;}
	printf("client had been conected.\n");
	
	char buffer[1024];

	while(1){
		memset(buffer,0,sizeof(buffer));
		if((recv(clientfd,buffer,sizeof(buffer),0))<=0){break;}
		printf("receive:%s \n",buffer);
		memset(buffer,0,sizeof(buffer));
		strcpy(buffer,"ok");
		if((send(clientfd,buffer,sizeof(buffer),0))<=0){break;}
	}
	close(socketfd);
	close(clientfd);
}










