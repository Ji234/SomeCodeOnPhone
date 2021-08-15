//char 数字转化成为 int ,必须用ascii码进行运算
#include  <stdio.h>
int ato(char chr){
  chr-=48;
  return chr;
}
int main(){
  char ch='2';
  printf("%d\n",ato(ch));
  return 0;
}
