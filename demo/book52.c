//用指针操控变量的值
#include <stdio.h>
int main(){
  int ii=10;
  int *pii=0;
  pii=&ii;
  *pii=32452346;
  printf("变量:ii的内容是%d\n",ii);
  printf("变量ii的地址是:%p\n",pii);
  return 0;
}
