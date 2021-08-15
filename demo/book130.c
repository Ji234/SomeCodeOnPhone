//演示mktime库函数
#include <stdio.h>
#include<time.h>

int main(int argc,char *argv[]){
  struct tm sttm;
  memset(&sttm,0,sizeof(sttm));
  sttm.tm_year=2019-1900;//注意要减1900
  sttm.tm_mon=12-1;//注意要减去1
  sttm.tm_mday=25;
  sttm.tm_hour=15;
  sttm.tm_min=5;
  sttm.tm_sec=3;
  sttm.tm_isdst=0;
  printf("%lu\n",mktime(&sttm));

}
