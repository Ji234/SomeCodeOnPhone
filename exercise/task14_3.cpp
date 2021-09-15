//见前面的代码修改一下,能修改的都可以修改一下
#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc ,char *argv[]){
	if(argc!=2) {printf("please input a port like as 5005");return -1;}

	int listenfd;;
	if((listenfd=socket(AF_INET,SOCK_STREAM,0))==-1){perror("socket");return-1;}
	
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	//i changed 
	servaddr.sin_addr.s_addr =inet_addr("192.168.1.7");
	//servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(atoi(argv[1]));
	if(bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0){
		perror("bind");
		close(listenfd);
		return -1;
	}

	if(listen(listenfd,5)!=0){
		perror("listen");
		close(listenfd);
		return -1;
	}
	
	int clientfd;
	int sockle=sizeof(struct sockaddr_in);
	struct sockaddr_in clientaddr;
	clientfd=accept(listenfd,(struct sockaddr*) &clientaddr,(socklen_t *)&sockle);
	printf("client(%s) had been connect\n",inet_ntoa(clientaddr.sin_addr));

	char buffer[1024];
	while(1)
	{
		int iret;
		memset(buffer,0,sizeof(buffer));
		if((iret=recv(clientfd,buffer,sizeof(buffer),0))<=0){
			printf("iret=%d\n",iret);
			break;
		}
		printf("receive:%s\n",buffer);

		strcpy(buffer,"ok");
		if((iret=send(clientfd,buffer,strlen(buffer),0))<=0){
			perror("send");
			break;
		}
		printf("send:%s\n",buffer);
	}
	close(clientfd);
	close(listenfd);

}


















