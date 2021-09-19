//semaphore(信号量)

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/sem.h>

class CSEM{
	private:
	union semun{	//it be use to contral
	int val;
	struct semid_ds *buf;
	unsigned short *arry;
	};
	int sem_id;
	public:
	bool init(key_t key);
	bool wait();
	bool post();
	bool destroy();
};

bool CSEM::init(key_t key){
	if((sem_id=semget(key,1,0640))==-1){
		//if semaphore is not exist build it 
		if (errno==2){
			if((sem_id=semget(key,1,0640|IPC_CREAT))==-1){
				perror("init 1 semget()\n");
				return false;}
				//after build,it must init to useful
				union semun sem_union;
				sem_union.val=1;
				if(semctl(sem_id,0,SETVAL,sem_union)<0){
					perror("init semctl()\n");
					return false;}
				}
			else {perror("init 2 semget()\n");
			return false;
			}
		}
	return true;
}


bool CSEM::destroy(){
	if(semctl(sem_id,0,IPC_RMID)==-1){
		perror("destroy semctl()");
		return false;
	}
	return true;
}

bool CSEM::wait(){
	struct sembuf sem_b;
	sem_b.sem_num=0;
	sem_b.sem_op=-1;
	sem_b.sem_flg=SEM_UNDO;
	if(semop(sem_id,&sem_b,1)==-1){
		perror("wait semop()");
	}
	return true;
}

bool CSEM::post(){
	struct sembuf sem_b;
	sem_b.sem_num=0;
	sem_b.sem_op=-1;
	sem_b.sem_flg=SEM_UNDO;
	if(semop(sem_id,&sem_b,1)==-1){
		perror("post semop()");
	}
	return true;
}

int main(){
	CSEM sem;
	//int signal
	if(sem.init(0x5000)==false){
		printf("sem init failed\n");
		return -1;
	}
	printf("sem init succese\n");
	//wait the signal seccese it will hod the lock
	if(sem.wait()==false){
		printf("sem.wait is failed\n");
		return -1;
	}
	printf("sem wait succese\n");
	sleep(2);//at the sleep time we can run other 259 application
//	if(sem.destroy()==false){
//		printf("sem.destroy failed\n");
//		return -1;
//	}
//	printf("sem.destroy succese\n");
}

