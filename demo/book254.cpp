//multiprogramming to show multiprogramming have alone memory to save data

#include <unistd.h>
#include <stdio.h>

int ii=0;
void fatherfunction(){
	//printf("i am father progame\n");
	ii+=20;
	printf("am father ");
}
void childfuction(){
	//printf("i am  child  progame\n");
	ii+=10;
	printf("am child ");
}

int main(){
	if(fork()>0){
	//when the progame run the fork,the data and progame commond copyed in another process it also alloc memory to save it  
	//but dont run the fork 
		fatherfunction();
	}
	else childfuction();
	printf("ii=%d\n",ii);
	//printf("father and child function all will come to there\n");
}
