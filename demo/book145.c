// 演示文件和目录存储权限和状态信息
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

//本程序运行要带一个参数,即文件名或目录名
int main(int argc,char *argv[]){
  if(argc!=2){
    printf("请输入文件或目录名\n");
    return -1;
  }
  if(access(argv[1],F_OK))
  {
    printf("文件或者目录%s不存在\n",argv[1]);
    return -1;
  }
  struct stat statat;
  //获取文件的状态信息
  if(stat(argv[1],&statat)!=0) return -1;

  if(S_ISREG(statat.st_mode)) printf("%s是一个文件\n",argv[1]);
  if(S_ISDIR(statat.st_mode)) printf("%s是一个目录\n",argv[1]);

}
