//编写获取文件大小的函数
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>


off_t getsize(char *pathname){
	struct stat ststat;
	if(stat(pathname,&ststat)!=0) printf("发生错误");
	return ststat.st_size;
}

int main(int argc,char *argv[]){
	if(argc!=2){ printf("输入文件目录名");return -1; }
	if(access(argv[1],F_OK)!=0) {printf("文件或者目录不存在");return -1;}
	long  filesize;
	filesize=getsize(argv[1]);
	printf("%ld\n",filesize);
}
