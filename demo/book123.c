//读取文件目录下面文件名信息
#include <stdio.h>
#include <dirent.h>

int main (int argc,char *argv[]){
 if (argc!=2){ printf("请指目录名\n"); return -1;}
 DIR *dir;//定义目录指针
 //
 //打开目录
 if((dir=opendir(argv[1]))==0) return -1;
 struct dirent *stdinfo;

 while(1){
 //读取一条记录并显示到屏幕
 if((stdinfo =readdir(dir))==0) break;
 printf("%-20s,%-5d\n",stdinfo->d_name,stdinfo->d_type);
 }
 closedir(dir);
}
