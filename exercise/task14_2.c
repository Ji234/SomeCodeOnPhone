//把字符串格式的时间转换成整数时间
//函数声明如下
#include <stdio.h>
#include <time.h>
int strtotime(const char *strtime,time_t *ti){
  if(strlen(strtime)!=19) return -1;
  struct tm sttm;
  int year,mon,day,hour,min,sec;
  char temp[5];
  strncpy(temp,strtime,4);
  temp[4]=0;
  printf("%s\n",temp);
  year=atoi(temp);
  strncpy(temp,strtime+5,2);
  temp[2]=0;
  printf("%s\n",temp);
  mon=atoi(temp);
  strncpy(temp,strtime+8,2);
  temp[2]=0;
  printf("%s\n",temp);
  day=atoi(temp);
  strncpy(temp,strtime+11,2);
  temp[2]=0;
  printf("%s\n",temp);
  hour=atoi(temp);
  strncpy(temp,strtime+14,2);
  temp[2]=0;
  printf("%s\n",temp);
  min=atoi(temp);
  strncpy(temp,strtime+17,2);
  temp[2]=0;
  printf("%s\n",temp);
  sec=atoi(temp);
  
  sttm.tm_year=year-1900;
  sttm.tm_mon=mon-1;
  sttm.tm_mday=day;
  sttm.tm_hour=hour;
  sttm.tm_min=min;
  sttm.tm_sec=sec;
  sttm.tm_isdst=0;//注意这里一定要加上这一句,看来默认isdst=1.我刚刚没加就出错了

  *ti=mktime(&sttm);
  return 0;
}

int main(){
  char strtime[20]={"2021-08-18 23:29:07"};
  time_t tt;
  strtotime(strtime,&tt);
  printf("%ld\n",tt);

}
