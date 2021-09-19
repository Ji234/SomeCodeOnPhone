//demo of shara memory
#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main(){
	int shmid;//shara memory id
	if((shmid=shmget((key_t)0x5005,1024,0640|IPC_CREAT))==-1){
		//1024 is the memory size ,0640 is the file permission
		printf("shmat(0x5005) failed");
		return -1;
	}
	char *ptext=0;//it well point some memory which is shara memory
	ptext=(char *)shmat(shmid,0,0);
	printf("before write:%s\n",ptext);
	sprintf(ptext,"the ipd of  application is %d",getpid());
	printf("after write:%s\n",ptext);
	shmdt(ptext);

	//if(shmctl(shmid,IPC_RMID,0)==-1){
	//printf("shmid(shmid,IPC_RMID,0) is failed");return -1;
	//}
}
