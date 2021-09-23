//给共享内存加锁

#include <stdio.h>
#include <string.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>

class CLSHM{
private:
	int sem_id;
	union semun{
		int val;//it is the signal
		struct semid_ds *buf;
		unsigned short *arry;
	};
public:
	int init(key_t key);
	bool wait();
	bool post();
	bool destory();
}
int CLSHM::init(key_t key){
	
}

int main(){
	
}
