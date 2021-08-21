//演示utime结构体的使用,修改文件的修改时间

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <utime.h>
#include <sys/types.h>
//程序运行需要一个参数
int main(int argc,char *argv[]){
  struct utimbuf stutimbuf;
	stutimbuf.actime=stutimbuf.modtime=1589805561;
	utime("aa",&stutimbuf);
  return 0;
  //这里程序已经结束,后面的代码没有用!




	if(argc !=2) {printf("请输入文件或者目录名\n");return -1;}//判断是否输入文件
	//判断文件是否存在
	if(access(argv[1],F_OK)!=0) {printf("文件或者目录%s不存在\n",argv[1]);return -1;}
	struct stat ststat;//用来存储目录或文件信息
	//获取文件信息
	if(stat(argv[1],&ststat)!=0) return -1;
	if(S_ISREG(ststat.st_mode)) printf("%s是一个文件\n",argv[1]);
	if(S_ISDIR(ststat.st_mode))
		printf("%s是一个目录\n",argv[1]);


}
