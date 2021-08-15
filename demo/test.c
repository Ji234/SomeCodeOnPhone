#include <stdio.h>
int main(){
  int temp=0x12345678;
  int age=0x40;
  long long *p;
  p=(long long*)&age;
  printf("%llx\n",*p);
  return 0;
}
