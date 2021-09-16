//16.2

#include <stdio.h>
#include <unistd.h>

void PrintIpInfo(int number){
	printf("pid is %d\n",getpid());
	printf("This is No.%d process\n\n",number);
}
int main(){
	int ipid=0;
	ipid=getpid();
	for(int ii=0;ii<10;ii++){
	if(ipid==getpid()&&fork()>0){
			 //PrintIpInfo(ii);
			 usleep(10);
		}
	 else if(ipid!=getpid()){
			 PrintIpInfo(ii);
			 break;
	}
	}
	sleep(30);
}
