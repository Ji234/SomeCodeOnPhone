//编写一个可以向上mkdir的函数,使得输入的目录成功被创建
//正常的话只能创建当前工作目录下的目录

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int MKDIR(const char *pathname){
	int i=1;
	char dirname[256];
	memset(dirname,0,sizeof(dirname));
	struct stat dirstat;

	//printf("%lu\n",strlen(pathname));
	for(i=1;i<strlen(pathname);i++)  if(pathname[i]=='/') break;
	//printf("%d\n",i);
	strncpy(dirname,pathname,i);//将最上面的目录复制到dirname里面
	//printf("%s\n",pathname+i+1);
	//如果是空的目录的话直接创建目录
	if(access(dirname,F_OK)!=0) {
		mkdir(dirname,0755);
		if(i!=(strlen(pathname))){
			printf("%d,%d\n",i,strlen(pathname));
			chdir(dirname);
			printf("ch成功");
			MKDIR(pathname+i+1);
			return 0;
		}
		else return 0;
	}
	else {
		if(stat(dirname,&dirstat)!=0) { printf("获取文件状态错误\n");return -1;}
		if(S_ISREG(dirstat.st_mode)){printf("输入的路径有文件不能创建文件夹\n");return -1;}
		else if(S_ISDIR(dirstat.st_mode)) {
			chdir(dirname);
			MKDIR(pathname+i+1);
		}
	}
	return 0;
}
int main(int argc,char *argv[]){
	if(argc!=2){printf("请输入要创建的文件夹\n");return -1;}
	MKDIR(argv[1]);
}

