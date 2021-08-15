//练习吧字符串里面的数字加起来
#include<stdio.h>
int main(){
  char str[20]="48654546";
  int i,num;
  i=num=0;
  for(i=0;i<20;i++){
  if(str[i]>=48&&str[i]<=57)
  num+=(str[i]-48);
  }
  printf("%d\n",num);
  return 0;
}
