//multiprogramming

#include <unistd.h>
#include <stdio.h>

void fatherfunction(){
	printf("i am father progame\n");
}
void childfuction(){
	printf("i am  child  progame\n");
}

int main(){
	if(fork()>0){
	//when the progame run the fork,the data and progame commond copyed in another process it also alloc memory to save it  
	//but dont run the fork 
		fatherfunction();
	}
	else childfuction();

	printf("father and child function all will come to there\n");
}
