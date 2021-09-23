#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main(){
	int shmid;
	if((shmid=shmget((key_t)0x5005,4,0660|IPC_CREAT))==-1){
		perror("getshm");
		return -1;
	}
	int  *pshm=0;
	pshm=(int *)shmat(shmid,0,0);
	printf("before change shara memory the pid is:%d\n",*pshm);
	*pshm=getpid();
	printf("after change shara memory the pid is:%d\n",*pshm);
	shmdt(pshm);
}
