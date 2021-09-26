//此程序演示精确到微秒的计时器

#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(){
  struct timeval begin,end;//存放开始和结束的时间
  gettimeofday(&begin,0);//计时器开始
  long i,temp;//计算一下后面的这个程序运行了多长时间
  for(i=0;i<1000000000;i++){
  temp+=i;
  }
  printf("%ld\n",temp);
  printf("begin time(0)=%d,tv_sec=%ld,tv_usec=%ld\n",time(0),begin.tv_sec,begin.tv_usec);
  gettimeofday(&end,0);
  printf("begin time(0)=%d,tv_sec=%ld,tv_usec=%ld\n",time(0),end.tv_sec,end.tv_usec);
  printf("计时过去了%ld微秒\n",(end.tv_sec-begin.tv_sec)*1000000+end.tv_usec-begin.tv_usec);
  
}
