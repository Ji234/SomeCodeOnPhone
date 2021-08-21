//演示strerror的使用
//库函数是errno.h,,直接使用变量errno
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(){
	FILE *fp;
	if((fp=fopen("a","r"))==0){
		printf("%d:%s\n",errno,strerror(errno));
		//直接输出最近一次的错误
		perror("可以自己添加");
		return -1;
		//errno不会被置0当然之后可能会在之后继续被输出错误
		errno=0;
	}
	if(fp!=0)
	fclose(fp);
	return 0;
}
