//演示向文件输出数据

#include <stdio.h>
int main(){
  int ii=0;
  FILE *fp=0;
  char ffname[50]="file";
  if((fp=fopen(ffname,"w"))==0){
    printf("%s打开失败",ffname);
    return -1;
  }
  int i=0;
  for(i=0;i<6;i++){
    fprintf(fp,"向文件中写入第%d行数据\n",i);
  }
return 0;
}
