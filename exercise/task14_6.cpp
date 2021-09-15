#include <stdio.h>
#include<sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc,char *argv[]){
	if(argc!=3){
		printf("please input args like 127.0.0.1  5005");
		return -1;
	}
	int sockfd;
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
		perror("socket:");
		return -1;
	}
	struct hostent* h;
	if((h=gethostbyname(argv[1]))==0){
		printf("gethostname failed.\n");
		close(sockfd);
		return -1;
	}
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(atoi(argv[2]));
	memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);
	if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0){
		perror("connect:");
		close(sockfd);
		return -1;
	}
	
	char buffer[1024];
	int jj=0;
	while(1){
		int iret;
		memset(&servaddr,0,sizeof(servaddr));
		//sprintf(buffer,"this is NO.%d girl num:%d\n",ii+1,ii+1);
		scanf("%s",buffer);
		//sprintf(buffer,"%d",jj);
		//jj++;
		if((iret=send(sockfd,buffer,strlen(buffer),0))<0){
			perror("send:");
			break;
		}
		if(strcmp(buffer,"bye")==0) break;
		//printf("send:%s\n",buffer);
		memset(buffer,0,sizeof(buffer));

		if((iret=recv(sockfd,buffer,sizeof(buffer),0))<0){
			perror("recv:");
			break;
		}
		printf("receive:%s\n",buffer);
		//printf("iret=%d\n",iret); 
	}
	close(sockfd);
}








