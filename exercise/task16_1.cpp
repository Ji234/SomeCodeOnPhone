//work 16.1

#include <stdio.h>
#include <unistd.h>

int main(){
	int ii=0;

	if(fork()>0){
		printf("i am father ");
		ii=200;
	}
	else {
		printf("i am child");
		ii=100;
	}
	printf("ii=%d\n",ii);
}

//we can see the output that hava double print ii 
