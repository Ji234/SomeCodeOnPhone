//使用fseek,ftell,rewind

#include <stdio.h>
int main(){
  FILE *fp;
  char sxml[1000];
  if((fp=fopen("file","r"))==0)
  {
    printf("打开文件失败");
	return -1;
  }
  fseek(fp,-100L,2);//文件内部指针放在离文件尾前面100字节的位置
  int f;
  f=ftell(fp);//告诉我们离文件首的位置有多少字节
  printf("%d\n",f);
  rewind(fp);//将文件内部指针放在文件首
  f=ftell(fp);
  printf("%d\n",f);
  fread(sxml,1,sizeof(sxml),fp);//读取文件内容,fgets是读取一行
  printf("%s",sxml);
  fclose(fp);
}
