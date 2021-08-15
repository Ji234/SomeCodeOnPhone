//演示地址的加减
#include <stdio.h>
int main(){
  int ii[4];
  char cc[4];
  double dd[4];
  printf("%p %p %p %p \n",ii,ii+1,ii+2,ii+3);
  printf("%p %p %p %p \n",cc,cc+1,cc+2,cc+3);
  printf("%p %p %p %p \n",dd,dd+1,dd+2,dd+3);
  return 0;
}
