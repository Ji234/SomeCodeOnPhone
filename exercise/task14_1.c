//编写一个函数,把整数的时间转换成字符串格式的的时间,格式如"2019-02-08 12:05:08"
//成功返回0,失败返回-1
//函数的声明如下
#include <stdio.h>

int timeetostr(const time_t ti,char *strtime){
  char tmp[3]={'0'};
  int i=0;
  char itmp[5][3];
  time_t r=ti;
  ++r;
  while(i<5){
    strcpy(itmp[i],tmp);
  }
  for(i=0;i<5;i++){
    if(r[i]<10) itmp[i][1]=r[i];
	else 
  }
  sprint(strtime,"%d-%s-%s %s:%s:%s",ti.tm_year+1900,itmp[0][],itmp[1],itmp[2],itmp[3],itmp[4]);

}
