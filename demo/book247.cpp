//packaging socket server by cpp
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include<sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

class CTcpServer{
	public:
	int m_socketfd;
	int m_listenfd;
	CTcpServer();
	bool InitServer(int port);
	bool Accept();

	int Send(const void *buf,const int buflen);
	int Recv(void *buf,const int buflen);
	~CTcpServer();
};

//construction function
CTcpServer::CTcpServer(){
	m_listenfd=m_socketfd=0;
}
CTcpServer::~CTcpServer(){
	//close the socket
	if(m_socketfd!=0) close(m_socketfd);
	if(m_listenfd!=0) close(m_listenfd);
}
bool CTcpServer::InitServer(int port){
	m_listenfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr;
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(port);
	if(bind(m_listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr))!=0){
		close(m_listenfd);
		m_listenfd=0;
		return false;
	}
	if(listen(m_listenfd,5)!=0){
		close(m_listenfd);
		m_listenfd=0;
		return false;
	}
	return true;
}

bool CTcpServer::Accept(){
	if((m_socketfd=accept(m_listenfd,0,0))<=0) return false;
	return true;
}

int CTcpServer::Send(const void *buf,const int buflen){
	return send(m_socketfd,buf,buflen,0);
}

int CTcpServer::Recv(void *buf,const int buflen){
	return recv(m_socketfd,buf,buflen,0);
}

int main(){
	CTcpServer TcpServer;
	if(TcpServer.InitServer(5005)==false){
		printf("TcpServer.InitServer had been failed,exit\n");return -1;
	}
	if(TcpServer.Accept()==false){
		printf("Accept had been failed,exit\n");return -1;
	}
	printf("cilent had been connect\n");

	char buffer[1024];

	while(1){
		memset(buffer,0,sizeof(buffer));
		if((TcpServer.Recv(buffer,sizeof(buffer)))<=0)break;
		printf("recvive:%s\n",buffer);
		memset(buffer,0,sizeof(buffer));
		strcpy(buffer,"ok");
		if(TcpServer.Send(buffer,sizeof(buffer))<=0) break;
		printf("send %s\n",buffer);
	}
	printf("client had been break");
}






