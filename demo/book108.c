//演示文件的打开和关闭
#include <stdio.h>
int main(){
  FILE *fp=0;//定义文件指针变量,和初始化
  //以只读的方式打开文件file,注意这里的r必须加双引号,你想一想,如果有两个字符的话就违反了c语言标准了
  if((fp=fopen("file","r"))==0)
  {
    printf("打开文件file失败\n");
    return -1;
  }
  printf("fp=%p\n",fp);
  fclose(fp);

return 0;
}
