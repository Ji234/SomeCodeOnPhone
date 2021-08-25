//编写获取文件时间的函数
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

time_t gettime1(const char *pathname){
	struct stat ststat;
	if(stat(pathname,&ststat)!=0); 
		printf("%ld\n",ststat.st_mtime);
	return ststat.st_mtime;

}
int main(int argc,char *argv[]){
	if(argc!=2){printf("请输入文件路径");return -1;}
	if(access(argv[1],F_OK)!=0) {printf("文件不存在");return -1;}
	time_t dirtimeint;
	dirtimeint=gettime1(argv[1]);
	struct tm *dirtime;
	dirtime=localtime(&dirtimeint);
	printf("%04d-%02d-%02d %02d:%02d:%02d",dirtime->tm_year+1900,dirtime->tm_mon+1,dirtime->tm_mday,dirtime->tm_hour,dirtime->tm_min,dirtime->tm_sec);
}
