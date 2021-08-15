//从文件中取出数据
#include <stdio.h>
#define fname "file"
int main(){
  FILE *fp=0;
  char txt[500];
  if((fp=fopen(fname ,"r"))==0){
    printf("打开文件--%s--失败",fname);
    return -1;
  }
  while(1){
    memset(txt,0,sizeof(txt));
    if(fgets(txt,sizeof(txt),fp)==0) break;
    printf("%s",txt);
  }
return 0;
}
