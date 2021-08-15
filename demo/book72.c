//测试浮点数精确情况
#include <stdio.h>
int main(){
  float ff2=9.9;
  printf("ff2=%f\n",ff2);
  if(ff2==9.9) printf("ff2=%f",ff2);

  float ff5=99.999;
  printf("ff5=%f\n",ff5);
  if(ff2==99.999) printf("ff5=%f",ff5);

  float ff6=999.999;
  printf("ff6=%f\n",ff6);
  if(ff2==999.999) printf("ff6=%f",ff6);
  float ff7=9999.999;
  printf("ff7=%f\n",ff7);
  if(ff2==9999.999) printf("ff7=%f",ff7);
  float ff8=99999.999;
  printf("ff8=%f\n",ff8);
  if(ff2==99999.999) printf("ff8=%f",ff8);
  float ff9=999999.999;
  printf("ff9=%f\n",ff9);
  if(ff2==999999.999) printf("ff9=%f",ff9);
}
//结论float不精准
