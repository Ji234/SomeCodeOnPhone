//找出menset和bzero的特点和区别
#include <stdio.h>
#include <string.h>
int main(){
  char chr1[20];
  char chr2[20];
  int i1[20];
  int i2[20];
  memset(chr1,'a',sizeof(chr1));
  bzero(chr2,sizeof(chr2));  
  memset(i1,1,sizeof(i1));//其按字节进行赋值
  bzero(i2,sizeof(i2));  
  printf("%s\n",chr1);
  printf("%s\n",chr2);
  printf("%d\n",i1[1]);
  printf("%d\n",i2[1]);
}
