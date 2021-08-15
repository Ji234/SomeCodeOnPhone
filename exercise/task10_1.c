//从10开始浮点数作业
//一些demo 将其做成函数
//1.测试float,double,long double占用的内存
//2.测试float浮点数的精度,当浮点数太长的时候会出现不精确
//3.测试double浮点数的精度,当浮点数太长的时候会出现不精确
//4.浮点数与整数的转换时其中的规律
//5.测试浮点数据的科学计数法
//
//以函数的形式呈现
#include <stdio.h>
#define ffpp printf("\n\n");
void test1();
void test2();
void test3();
void test4();
void test5();



int main(){
   test1();
   test2();
   test3();
   test4();
   test5();
}

void test1(){
 float ff;
 double dd;
 long double ld;
 printf("float: %lu\n",sizeof(float));
 printf("float: %lu\n",sizeof(double));
 printf("float: %lu\n",sizeof(long double));
}

void test2(){
  ffpp;
  float ff2=9.9;
  float ff5=999.99;
  float ff6=999.999;
  float ff7=9999.999;
  float ff8=99999.999;
  float ff9=999999.999;
  printf("%.4lf\n",ff2);
  printf("%.4lf\n",ff5);
  printf("%.4lf\n",ff6);
  printf("%.4lf\n",ff7);
  printf("%.4lf\n",ff8);
  printf("%.4lf\n",ff9);
}
void test3(){
  ffpp;
  double  ff2=9.9;
  double  ff5=999.99;
  double  ff6=999.999;
  double  ff7=9999.999;
  double  ff8=99999.999;
  double  ff9=999999.999;
  printf("%.4lf\n",ff2);
  printf("%.4lf\n",ff5);
  printf("%.4lf\n",ff6);
  printf("%.4lf\n",ff7);
  printf("%.4lf\n",ff8);
  printf("%.4lf\n",ff9);
}
void test4(){
  ffpp;
  int i3=3,i4=4;
  float ff;
  ff=i3/i4;
  printf(" ff=i3/i4 中的ff 为:%f\n",ff);
  ff=(float)i3/i4;
  printf(" ff=(float)i3/i4  中的ff 为:%f\n",ff);
  ff=i3/(float)i4;
  printf("ff=i3/(float)i4 中的ff 为: %f\n",ff);
}
void test5(){
  ffpp;
  float fsc=3.14E10;
  printf("3.14E10= %f\n",fsc);
  printf("科学计数法表示3.14E10---->%e\n",fsc);
}
