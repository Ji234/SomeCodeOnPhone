//演示数组的地址
#include <stdio.h>
int main(){
  char array[50];
  char *p;
  p=array;
  strcpy(array,"whsg your are handsome");
  while(*p){
	  printf("地址%p,地址里面的值%c\n",p,*p);
	  p++;
  }
  return 0;
}
//可以明显的看到内存里面的内容和内存的地址
