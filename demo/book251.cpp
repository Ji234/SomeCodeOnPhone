//multiprogramming

#include <stdio.h>
#include <unistd.h>

int main(){
	printf("this process pid is %d \n",getpid());
	sleep(30);
}
