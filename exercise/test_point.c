//指针前面加*表示指向相应的内存,而不加*表示只想存有指针数据的内存
#include<stdio.h>
int main(){
 char *pstr="西施";
  printf("pstr=%p\n",pstr);
  printf("pstr=%s\n",pstr);  // 不会出现段错误（Core dump）
  strcpy(pstr,"杨玉");  // 会出现段错误（Core dump）
  return 0;
}
