//浮点数与整数的转换
#include <stdio.h>
int main(){
  int ii=3;
  int jj=4;
  double dd;

  dd=ii;//可以
  printf("%lf\n",dd);

  dd=ii/jj;//can't
  printf("%lf\n",dd);

  dd=(double)ii/jj;//can
  printf("%lf\n",dd);
return 0;
}
