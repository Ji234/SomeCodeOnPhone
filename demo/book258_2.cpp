#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
	int shmid;
	if((shmid=shmget((key_t)0x5005,1024,0660|IPC_CREAT))==-1){
		perror("shmget");
		return -1;
	}
	char *pshm;
	pshm=(char *)shmat(shmid,0,0);
	printf("before is %s\n",pshm);
	sprintf(pshm ,"%d",getpid());
	printf("after is %s\n",pshm);
}

