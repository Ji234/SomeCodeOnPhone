//signal to notice the background application exit

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void Exit(int sgl){
	printf("recviveed:signal info %d,the application will eixt\n",sgl);
	exit(0);
}
int main(){
	for(int ii=0;ii<100;ii++) signal(ii,SIG_IGN);//ignore all signal notice
	signal(SIGINT,Exit);//ctrl+c
	signal(SIGTERM,Exit);//kill appname
	signal(SIGKILL,Exit);//kill -9 appname,but it cant run the application will dead sudden

	while(1){
		sleep(10);
	}

}
