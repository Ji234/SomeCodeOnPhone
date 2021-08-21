//演示strerror的使用

#include <stdio.h>
#include <string.h>


int main(){
	int errorno;
	for(errorno=0;errorno<135;errorno++){
		printf("%d:%s\n",errorno,strerror(errorno));
	}
}
