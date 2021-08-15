#include <stdio.h>
//重写库函数
#define PRF printf("\n\n")
double FABS(const double x);//求双精度数的绝对值
double ROUND(const double x);//double的四舍五入
double CELL(const double x);//double向上取整
double FLOOR(const double x);//double的向下取整
double MODF( double val,double *ip);//把双精度数分解成两部分,整数部分放在ip指针里面,返回小数部分

int main(){
  double  dd=3.64892457243,*temp;
 printf("%lf\n",FABS(dd));
 printf("%lf\n",ROUND(dd));
 printf("%lf\n",CELL(dd));
 printf("%lf\n",FLOOR(dd));
 printf("%lf\n",MODF(dd,temp));
}

double FABS(const double x){
  PRF;
  if(x>=0) return x;
  else return -x;
}
double ROUND(const double x){
  PRF;
  long ll;
  ll=x;
  if((x-ll)>0.5) return (double)ll+1;
  else return (double)ll;
}
double CELL(const double x){
  PRF;
  long ll;
  ll=x;
  return (double)ll;
}
double FLOOR(const double x){
  PRF;
  long ll;
  ll=x;
  return (double)ll++;
}
double MODF( double val,double *ip){
  PRF;
  long ll;
  double fnum;
  ll=val;
  *ip=ll;
  fnum=val-ll;
  printf("%lf\n",*ip);
  return fnum;
}
