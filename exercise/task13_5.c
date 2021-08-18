//文本文件用fgets和fprint读写?二进制文件用fread和fwrite读写?用fread和fwrite读写文本文件是什么效果


#include <stdio.h>
int main(){
  FILE *fp;
  char sxml[1000];
  if((fp=fopen("file","r"))==0)
  {
    printf("打开文件失败");
	return -1;
  }
  fread(sxml,1,sizeof(sxml),fp);
  printf("%s",sxml);

}
