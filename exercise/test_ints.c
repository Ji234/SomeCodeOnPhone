//此段代码用来实验各种数据类型的占用内存大小
#include<stdio.h>
int main(){
  short si;
  int ii;
  long li;
  float ff;
  double df;
  unsigned int uii;
  printf("short %lu\n",sizeof(si));
  printf("int %lu\n",sizeof(ii));
  printf("long %lu\n",sizeof(li));
  printf("float %lu\n",sizeof(ff));
  printf("double %lu\n",sizeof(df));
  printf("unsigned int %lu\n",sizeof(uii));
  return 0;
}
