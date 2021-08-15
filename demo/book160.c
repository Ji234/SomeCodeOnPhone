//演示全局errno变量和strerror函数

#include <stdio.h>
#include <errno.h>

int main(){
  FILE *fp=0;
  if((fp=fopen("book","r"))==0){
    printf("打开文件失败(%d:%s)\n",errno,strerror(errno));
    return -1;
  }
  if(fp!=0)
  fclose(fp);
}
