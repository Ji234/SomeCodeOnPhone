//packaging the client of socket by cpp
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include<sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class CTcpClient{
	public:
	int m_socketfd;

	CTcpClient();
	~CTcpClient();
	bool Connect(const char* serverip,const int port);
	int Send(const void *buf,int buflen);
	int Recv(void *buf,int buflen); 
};

CTcpClient::CTcpClient(){
	m_socketfd=0;
}

CTcpClient::~CTcpClient(){
	if(m_socketfd!=0)close(m_socketfd);
}
bool CTcpClient::Connect(const char* serverip,const int port){
	m_socketfd=socket(AF_INET,SOCK_STREAM,0);
	struct hostent* h;
	if((h=gethostbyname(serverip))==0){ close(m_socketfd);m_socketfd=0;return	false;printf("gethostbyname");}
	struct sockaddr_in clientaddr;
	
	memset(&clientaddr,0,sizeof(clientaddr));
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(port);
	memcpy(&clientaddr.sin_addr,h->h_addr,h->h_length);

	if(connect(m_socketfd,(struct sockaddr*)&clientaddr,sizeof(clientaddr))!=0){
		close(m_socketfd);
		m_socketfd=0;printf("connect");
		return false;
	}
	return true;
}
int CTcpClient::Send(const void *buf,int buflen){
	return send(m_socketfd,buf,buflen,0);
}

int CTcpClient::Recv( void *buf,int buflen){	
	return recv(m_socketfd,buf,buflen,0);
}

int main(){
	CTcpClient TcpClient;
	if(TcpClient.Connect("127.0.0.1",5005)==false){
		printf("connect had been failed,exit\n");return -1;
	}
	char buffer[1024];

	for(int i=0;i<5;i++){
		memset(buffer,0,sizeof(buffer));
		sprintf(buffer,"this is NO.%d massage",i);
		if(TcpClient.Send(buffer,sizeof(buffer))<=0) break;
		memset(buffer,0,sizeof(buffer));
		if(TcpClient.Recv(buffer,sizeof(buffer))<=0) break;
		printf("recvive:%s\n",buffer);

	}
	printf("connect had been break");
}


















