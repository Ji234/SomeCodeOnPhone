//获取dir pwd

#include <stdio.h>

int main(){
  char dirname[300];
  memset(dirname,0,sizeof(dirname));
  getcwd(dirname,300);
  printf("当前工作目录是%s\n",dirname);
}
