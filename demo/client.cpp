//socket conmunincate client

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include<netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc ,char *argv[]){
	if(argc!=3 ) {
		printf("Using:./client ip port\nExample:./client 127.0.01 5005\n\n");
		return -1;
	}

	//first:creat a client of socket
	int sockfd;
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) {
		perror("socket");return -1;
	}

	//second:send a requset to server
	//
	struct hostent *h;
	if((h=gethostbyname(argv[1]))==0)//sure the ip address
	{
		printf("gethostbyname failed.\n");
		close(sockfd);
		return -1;
	}
	struct sockaddr_in servaddr;//server port address data constraction
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET; //agreement on the socket can only AF_INET
	servaddr.sin_port=htons(atoi(argv[2]));
	memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);
	if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0){
		//send a request to server
		perror("connect");
		close(sockfd);
		return -1;
	}

	char buffer[1024];
	//thrid:send a massage after wait to receive
	for(int ii=0;ii<3;ii++){
		int iret;
		memset(buffer,0,sizeof(buffer));
		sprintf(buffer,"this No.%d girl ,num:%03d.",ii+1,ii+1);
		if((iret=send(sockfd,buffer,strlen(buffer),0))<=0)//send a request
		{perror("send");break;}
		printf("send:%s\n",buffer);

		memset(buffer,0,sizeof(buffer));
		if((iret=recv(sockfd,buffer,sizeof(buffer),0))<=0){
			printf("iret=%d\n",iret);break;
		}
		printf("receive:%s\n",buffer);
	}
	close(sockfd);
}
