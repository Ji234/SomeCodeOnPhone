//fork lots of process and let linux dead
#include <unistd.h>
#include <stdio.h>

int main(){
	int i=0;
	while(i<15000&&fork()){
		i++;
	}
	sleep(20);
}
