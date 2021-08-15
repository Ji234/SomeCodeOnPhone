//测试浮点数精确情况
#include <stdio.h>
int main(){
  double ff2=9.9;
  printf("ff2=%lf\n",ff2);
  if(ff2==9.9) printf("ff2=%f\n",ff2);

  double ff5=99.999;
  printf("ff5=%lf\n",ff5);
  if(ff2==99.999) printf("ff5=%f\n",ff5);

  double ff6=999.999;
  printf("ff6=%lf\n",ff6);
  if(ff2==999.999) printf("ff6=%f\n",ff6);

  double ff7=9999.999;
  printf("ff7=%lf\n",ff7);
  if(ff2==9999.999) printf("ff7=%f\n",ff7);

  double ff8=99999.999;
  printf("ff8=%lf\n",ff8);
  if(ff2==99999.999) printf("ff8=%f\n",ff8);

  double ff9=999999.999;
  printf("ff9=%lf\n",ff9);
  if(ff2==999999.999) printf("ff9=%f\n",ff9);

}
//在我的机子上面double也不准啊
