//获取目录
//打开目录
//DIR opendir(const char *pathname);
//读取目录的函数
//struct dirent *readdir(DIR *dirp);
//关闭函数
//int closedir(DIR *dirp);
//struct dirent{
//long d_ino;
////文件索引
//off_t d_off;
////在目录文件中的偏移
//unsigned short d_reclen;
////文件名长
//unsigned char d_type;
////文件类型
//char d_name{NAME_MAX+1];
////文件名,最长255字符
//}

#include <stdio.h>
#include <dirent.h>
int main(int argc,char *argv[]){
  if(argc!=2) {printf("请输入目录名\n");return -1;}
  DIR *dir;//定义目录指针
  //打开目录
  if((dir=opendir(argv[1]))==0) return -1;
  //存放从目录中读取到的文件和目录
  struct dirent *stdinfo;
  while(1){
    //读取一条记录显示到屏幕
	if((stdinfo=readdir(dir))==0) break;
	printf("文件类型:%d 文件名:%s\n",stdinfo->d_type,stdinfo->d_name);
  }
  closedir(dir);//关闭文件指针
}
