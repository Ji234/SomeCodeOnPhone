//编写一个函数,把整数的时间转换成字符串格式的的时间,格式如"2019-02-08 12:05:08"
//成功返回0,失败返回-1
//函数的声明如下
#include <stdio.h>
#include <time.h>
int timeetostr(const time_t ti,char *strtime){
  if(sizeof(ti)!=8) return -1;
  struct tm *sttm;
  sttm=localtime(&ti);
  sprintf(strtime,"%4d-%02d-%02d %02d:%02d:%02d",sttm->tm_year+1900,sttm->tm_mon+1,sttm->tm_mday,sttm->tm_hour,sttm->tm_min,sttm->tm_sec);
  return 0;
}

int main(){
  time_t tnow;
  tnow=time(0);
  printf("%ld\n",tnow);
  char timestr[100];
  timeetostr(tnow,timestr);
  printf("%s\n",timestr);
}


//有一些需要注意的地方
//1.day的变量名是mday
//2.要加上1900才是正确的结果
//3.mon要加上1
