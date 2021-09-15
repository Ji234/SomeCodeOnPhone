//multiprogramming

#include <unistd.h>
#include <stdio.h>
int main(){
	printf("this program's pid is %d\n",getpid());
	int ipid=fork();

	sleep(1);

	printf("ipid id %d\n",ipid);
	if(ipid!=0)printf("father's pid is %d\n",getpid());
	else printf("son's pid is %d\n",getpid());
	sleep(30);
}
