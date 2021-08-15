//读取文件目录下面目录及其子目录下全部的文件
#include <stdio.h>
#include <dirent.h>

int ReadDir(const char *strpathname);

int main (int argc,char *argv[]){
 if (argc!=2){ printf("请指目录名\n"); return -1;}
 DIR *dir;//定义目录指针
 ReadDir(argv[1]);
}
int ReadDir(const char *strpathname){
  DIR *dir;//定义目录指针
  char strchdpath[256]; //子目录的全路径

  if((dir=opendir(strpathname))==0) return -1;//打开目录
  struct dirent *stdinfo;
  while(1){
    //读取一条记录并显示到屏幕
    if((stdinfo =readdir(dir))==0) break;
    if(strncmp(stdinfo->d_name,".",1)==0) continue;//以.开始的文件不读
    //如果是文件,就显示出来
    if(stdinfo->d_type==8)
    printf("name=%s/%s\n",strpathname,stdinfo->d_name);//这里用/可以将文件的路径连接起来
    //如果是目录,就再调用一次ReadDir()
    if(stdinfo->d_type==4){
       sprintf(strchdpath,"%s/%s",strpathname,stdinfo->d_name);
       ReadDir(strchdpath);
    }
  }
  closedir(dir);//关闭指针
  return 0;
}
