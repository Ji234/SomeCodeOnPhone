//编写一个函数,获取操作系统时间,函数声明如下:
#include <stdio.h>
#include <time.h>
void LocalTime(const char *in_fmt,const int in_interval){
  time_t tt;
  tt=time(0);
  tt=tt+in_interval;
  struct tm sttm;
  memset(&sttm,0,sizeof(sttm));
  sttm=*localtime(&tt);
  if(strlen(in_fmt)==21) printf("%04d-%02d-%02d %02d:%02d:%02d\n",sttm.tm_year+1900,sttm.tm_mon+1,sttm.tm_mday,sttm.tm_hour,sttm.tm_min,sttm.tm_sec);
  else if(strlen(in_fmt)==16) printf("%04d%02d%02d%02d%02d%02d\n",sttm.tm_year+1900,sttm.tm_mon+1,sttm.tm_mday,sttm.tm_hour,sttm.tm_min,sttm.tm_sec);
  else if(strlen(in_fmt)==10&&in_fmt[0]=='y') printf("%04d-%02d-%02d\n",sttm.tm_year+1900,sttm.tm_mon+1,sttm.tm_mday);
  else if(strlen(in_fmt)==8&&in_fmt[0]=='y') printf("%04d%02d%02d\n",sttm.tm_year+1900,sttm.tm_mon+1,sttm.tm_mday);
  else if(strlen(in_fmt)==10&&in_fmt[0]=='h') printf("%02d:%02d:%02d\n",sttm.tm_hour,sttm.tm_min,sttm.tm_sec);
  else if(strlen(in_fmt)==8&&in_fmt[0]=='h') printf("%02d%02d%02d\n",sttm.tm_hour,sttm.tm_min,sttm.tm_sec);
  else if(strlen(in_fmt)==7) printf("%02d:%02d\n",sttm.tm_hour,sttm.tm_min);
  else if(strlen(in_fmt)==6) printf("%02d%02d\n",sttm.tm_hour,sttm.tm_min);
  else if(strlen(in_fmt)==4) printf("%02d\n",sttm.tm_hour);
  else if(strlen(in_fmt)==2) printf("%02d\n",sttm.tm_min);
}

int main(){
 LocalTime("yyyy-mm-dd hh24:mi:ss",5*60);
}
