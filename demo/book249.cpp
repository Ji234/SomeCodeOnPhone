// multiprograming socket commuicyation

#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
class CMultiTcpClient{
	public:
	int m_sockfd;
	CMultiTcpClient();
	~CMultiTcpClient();
	bool ConnectToServer(char * serverip,int port);//init server
	int Send(const void *buf,const int bufln);
	int Recv(void *buf,const int bufln);
};

CMultiTcpClient::CMultiTcpClient(){
	m_sockfd=0;
}

bool CMultiTcpClient::ConnectToServer(char* serverip,int port){
	m_sockfd=socket(AF_INET,SOCK_STREAM,0);
	struct hostent *h;
	if((h=gethostbyname(serverip))==0){
		close(m_sockfd);
		m_sockfd=0;
		return false;
	}

	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(port);
	memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);

	if(connect(m_sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))!=0){
		close(m_sockfd);
		m_sockfd=0;
		return false;
	}
	return true;
}

CMultiTcpClient::~CMultiTcpClient(){
	if(m_sockfd>0)close(m_sockfd);
}
int CMultiTcpClient::Send(const void *buf,const int bufln){
	return send(m_sockfd,buf,bufln,0);
}
int CMultiTcpClient::Recv(void *buf,const int bufln){
	return recv(m_sockfd,buf,bufln,0);
}

	
//close the listen stdio
int main(){
	//signa(SIGCHLD,SIG_IGN);//忽略子进程产生的退出信号,避免产生僵尸进程
	CMultiTcpClient MultiTcpClient;;	
	if(MultiTcpClient.ConnectToServer("127.0.0.1",5051)==false){
		printf("MultiTcpClient.ConnectToServer(127.0.0.1,5051) is faild");
		return -1;
	}
	char buffer[1024];
	for(int ii=0;ii<20;ii++){
		memset(buffer,0,sizeof(buffer));
		strcpy(buffer,"ok");
		if(MultiTcpClient.Send(buffer,sizeof(buffer))<=0) break;
		printf("send:%s\n",buffer);
		memset(buffer,0,sizeof(buffer));
		if(MultiTcpClient.Recv(buffer,sizeof(buffer))<=0) break;
		printf("recvive:%s\n",buffer);
	}
	printf("server had been break");
	exit(0);
}

