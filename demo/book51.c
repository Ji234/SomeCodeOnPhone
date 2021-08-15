//演示获取变量的地址
#include <stdio.h>
int main(){
  int ii=10;
  char cc='A';
  double dd =100.56;
  int *pii=0;
  char*pcc=0;
  double  *pdd =0;
  pii=&ii;
  pcc=&cc;
  pdd=&dd;
  printf("变量pii的地址是:%p\n",&pii);
  printf("变量pcc的地址是:%p\n",&pcc);
  printf("变量pdd的地址是:%p\n",&pdd);
  printf("变量ii的地址是:%p\n",pii);
  printf("变量cc的地址是:%p\n",pcc);
  printf("变量dd的地址是:%p\n",pdd);
  return 0;
}
