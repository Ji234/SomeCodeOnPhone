//演示strerror函数的使用
#include <stdio.h>
#include <string.h>

int main(){
  int errorno;
  for(errorno=0;errorno<132;errorno++) 
    printf("%d:%s\n",errorno,strerror(errorno));

}
