//演示获取操作系统时间
#include <stdio.h>
#include<time.h>

int main(int argc,char *argv[]){
  time_t tnow;
  tnow=time(0);//获取当前时间
  printf("tnow=%lu\n",tnow);//输出整数表示的时间
  struct tm *sttm;
  sttm=localtime(&tnow);//把时间转换成struct tm时间
  //yyyy-mm-dd hh24:mi:ss格式输出,此格式用得最多
  printf("%04u-%02u-%02u %02u:%02u:%02u\n",sttm->tm_year+1900,sttm->tm_mon+1,sttm->tm_mday,sttm->tm_hour,sttm->tm_min,sttm->tm_sec);
}
