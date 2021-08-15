//字符转换成为数字
#include <stdio.h>

int ctoi(char chr){
  switch(chr){
  case '0' :return 0;
  case '1' :return 1;
  case '2' :return 2;
  case '3' :return 3;
  case '4' :return 4;
  case '5' :return 5;
  case '6' :return 6;
  case '7' :return 7;
  case '8' :return 8;
  case '9' :return 9;break;
  default:printf("error");
 }
  return -1;
}
int main(){
  char c='5';
  int i;
  i=ctoi(c);
  printf("%lu\n",sizeof(i));
  return 0;
}
