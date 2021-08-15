//演示cahr 和unsigned char 超过范围的后果
#include <stdio.h>
int main(){
  char chr;
  chr=258;
  unsigned char uchr;
  uchr=-1;
  printf("c %d\n",chr);
  printf("c %c\n",chr);
  printf("uc %d\n",uchr);
  printf("uc %c\n",uchr);
}
