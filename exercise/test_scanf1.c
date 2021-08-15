// scanf练习
#include <stdio.h>
int main(){
  char name[20];
  int age;
  char sex;
  float weight;
  printf("请输入姓名,年龄,性别(m,w),体重");
  scanf("%s %d %c %f",name,&age,&sex,&weight);//这里name不用加&,字符串数组本来就是一个地址
  printf("`姓名:%s,年龄%d,性别%c,体重%f\n",name,age,sex,weight);
}
