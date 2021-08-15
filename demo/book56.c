//演示空指针引起程序崩溃
#include <stdio.h>
int main(){
  int *p=0;
  printf("p的值是%p\n",p);
  *p=10;//对空指针进行赋值,必然崩溃
  return 0;
}
