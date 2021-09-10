//socket conmunincate server :q

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include<netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc ,char *agrv[]){
	if(argc!=2 ) {
		printf("Using:./server port\nExample:./server 5005\n\n");
		return -1;
	}

	//first:creat a server of socket
	int listenfd;
	if((listenfd =socket(AF_INET,SOCK_STREAM,0))==-1) {
		perror("socket");return -1;
	}

	//second: band the server address and port on socket
	struct sockaddr_in servaddr;//server port address data constraction
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET; //agreement on the socket can only AF_INET
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY); //random the ip address
	//servaddr.sin_addr.s_addr=inet_addr("19"); //sure the ip address
	servaddr.sin_port=htons(atoi(agrv[1]));
	if(bind(listenfd ,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0){
		perror("bind");
		close(listenfd);
		return -1;
	}

	//thrid:set socket on listen schema
	if(listen(listenfd,5)!=0){
		perror("listen");
		close(listenfd );
		return -1;
	}

	//forth: receive client connect
	int clientfd;//client's connect
	int socklen=sizeof(struct sockaddr_in);//struct sockaddr_in's size
	struct sockaddr_in clientaddr; //client's address information
	clientfd=accept(listenfd ,(struct sockaddr *)&clientaddr,(socklen_t *)&socklen);
	printf("client(%s) had been connected\n",inet_ntoa(clientaddr.sin_addr));


	//fifth:recvie the massage send by client and reply "ok"
	char buffer[1024];
	while(1){
		int iret;
		memset(buffer,0,sizeof(buffer));
		if((iret=recv(clientfd,buffer,sizeof(buffer),0))<=0){//receive client's massage
			printf("iret=%d\n",iret);
			break;
		}
		printf("received: %s\n",buffer);
		
		strcpy(buffer,"ok");
		if(iret=send(clientfd,buffer,strlen(buffer),0)<=0)//send to server the end of send
		{perror("senf");break;}
		printf("send:%s\n",buffer);
	}
	//sixth:close the socket,free resource
	close(listenfd);
	close(clientfd);
}




















