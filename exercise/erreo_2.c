//演示strerror的使用
//库函数是errno.h,,直接使用变量errno
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(){
	FILE *fp;
	if((fp=fopen("a","r"))==0){
		printf("%d:%s\n",errno,strerror(errno));
		perror("可以自己添加");
		printf("打开文件失败\n");
		return -1;
	}
	fclose(fp);
}

