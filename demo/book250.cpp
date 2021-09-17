// multiprograming socket commuicyation

#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <signal.h>
#include <arpa/inet.h>
class CMultiTcpServer{
	public:
	int m_listenfd;
	int m_clientfd;
	CMultiTcpServer();
	~CMultiTcpServer();
	bool InitServer(int port);//init server
	bool Accept();//weit to client connect
	int Send(const void *buf,const int bufln);
	int Recv(void *buf,const int bufln);

	void CloseClient();//to close the client socket
	void CloseListen();//close the listen stdio
};
CMultiTcpServer::CMultiTcpServer(){
	m_listenfd=m_clientfd=0;
}

CMultiTcpServer::~CMultiTcpServer(){
	if(m_listenfd>0)close(m_listenfd);
	if(m_listenfd>0)close(m_clientfd);
}
bool CMultiTcpServer::InitServer(int port){
	if(m_listenfd!=0){close(m_listenfd);m_listenfd=0;}
	m_listenfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serveraddr;
	memset(&serveraddr,0,sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(port);
	serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);

	if(bind(m_listenfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))!=0){
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
bool CMultiTcpServer::Accept(){
	if((m_clientfd=accept(m_listenfd,0,0))<=0){
			return false;
	}
	return true;
}
int CMultiTcpServer::Send(const void *buf,const int bufln){
	return send(m_clientfd,buf,bufln,0);
}
int CMultiTcpServer::Recv(void *buf,const int bufln){
	return recv(m_clientfd,buf,bufln,0);
}

void CMultiTcpServer:: CloseClient(){
	if(m_clientfd>0){
		close(m_clientfd);
		m_clientfd=0;
	}
}//to close the client socket
void CMultiTcpServer::CloseListen(){
	if(m_listenfd>0){
		close(m_listenfd);
		m_listenfd=0;
	}
	
}//close the listen stdio
int main(){
	signal(SIGCHLD,SIG_IGN);//忽略子进程产生的退出信号,避免产生僵尸进程
	CMultiTcpServer MultiTcpServer;	
	if(MultiTcpServer.InitServer(5051)==false){
		printf("servers init failed\n");
		return -1;
	}
	while(1){
		if(MultiTcpServer.Accept()==false)	continue;
		if(fork()>0){
			MultiTcpServer.CloseClient();
			continue;
		}
	MultiTcpServer.CloseListen();
	printf("client had been connect\n");
	
	char buffer[1024];
	while(1){
		memset(buffer,0,sizeof(buffer));
		if(MultiTcpServer.Recv(buffer,sizeof(buffer))<=0) break;
		printf("recvive:%s\n",buffer);
		memset(buffer,0,sizeof(buffer));
		strcpy(buffer,"ok");
		if(MultiTcpServer.Send(buffer,sizeof(buffer))<=0) break;
		printf("send:%s\n",buffer);
	}
	sleep(10);
	printf("client had been break\n");
	exit(0);
	}
}
