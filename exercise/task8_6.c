//测试超出赋值范围的后果
#include <stdio.h>
int main(){
  short srt;
  srt=32768;
  printf("%d",srt);
  return 0;
}
//得出结论如果超出赋值的话会在最大负数和最大正数之间转化
