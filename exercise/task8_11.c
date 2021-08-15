//atoi,atol库函数重写,实现字符串转换成为数字
#include <stdio.h>
int ato(char *p);
int atol(char *p);
int main(){
  char str[20]="465456613";
  int num=0;
  num=ato(str);
  printf("%d\n",num);
  return 0;
}

int ato(char *p){
  int length=0,num=0,i;
  for(;*p>=48&&*p<=57;p++){
	  length++;
  }
  printf("%d\n",length);
  for(i=length;i>0;i--){
    printf("%d\n",num);
    num*=10;
    num+=(*(p-i)-48);
    }
  return num;
}
