//演示函数参数的传递和指针
#include <stdio.h>
void funcld(int *p);
int main(){
  int a=10;
  printf("位置一:a是一个变量,变量的地址是%p,a的值是%d\n",&a,a);
  funcld(&a);//调用函数,传递函数
  printf("位置二:a是一个变量,变量的地址是%p,a的值是%d\n",&a,a);
  return 0;
}
void funcld(int *p){
  printf("位置三:p是一个指针%p,指针指向的是变量%d\n",p,*p);
  *p =20;
  printf("位置四:p是一个指针%p,指针指向的是变量%d\n",p,*p);
}
