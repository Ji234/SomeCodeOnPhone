//16.3

#include <stdio.h>
#include <unistd.h>

int ii=0;
void PrintIpInfo(int number){
	printf("pid is %d\n",getpid());
	printf("This is No.%d process\n\n",number);
}

int main(){
	fork();
	ii++;
	fork();
	ii++;
	fork();
	ii++;
	fork();
	ii++;
	fork();
	ii++;
	fork();
	ii++;
	fork();
	ii++;
	fork();
	ii++;
	fork();
	ii++;
	fork();
	ii++;
	PrintIpInfo(ii);
}
