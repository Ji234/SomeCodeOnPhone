//随机生成52个随机数,范围1-52,不许重复,分到4个人手里
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(){
  srand(time(0));//随机种子

  int result[52];
  memset(result,0,sizeof(result));
  int ii=0;
  int pos=0;//已经生成的随机数个数
  for(ii=0;pos<52;ii++){
    int irand=rand()%52+1;
    int jj=0;
    for(jj=0;jj<52;jj++)
       if(irand==result[jj])break;//现在生成的数与以前生成的数相等就break一下

    if(jj<52) continue;//当然break之后就会让jj小雨52,导致之后的代码不被执行
    result[pos]=irand;
    pos++;
  }
  int man_0[12];
  int man_1[12];
  int man_2[12];
  int man_3[12];
  for(ii=0;ii<12;ii++){
    man_0[ii]=result[ii*4+0];
    man_1[ii]=result[ii*4+1];
    man_2[ii]=result[ii*4+2];
    man_3[ii]=result[ii*4+3];
  }
  for(ii=0;ii<12;ii++){
    printf("man0 ----是  %d\n",man_0[ii]);
  }
  for(ii=0;ii<12;ii++){
    printf("man1 ----是  %d\n",man_1[ii]);
  }
  for(ii=0;ii<12;ii++){
    printf("man2 ----是  %d\n",man_2[ii]);
  }
  for(ii=0;ii<12;ii++){
    printf("man3 ----是  %d\n",man_3[ii]);
  }
return 0;
}
