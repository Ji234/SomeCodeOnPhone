//字符串相关作业
//字符串常用的库函数功能,函数的声明如下

#include <stdio.h>

size_t strlen1(const char *str); //实现strlen函数的功能
char *strcpy1(char *dest,const char *src);//实现strcpy函数,下同
char *strncpy1(char *dest,const char *src,size_t n);
char *strcat1(char *dest,const char *src);
char *strchr1( char *s,const int c);
char *strrchr1( char *s,const int c);

//难度较大
int strcmp1(const char *str1,const char *str2);
int strncmp1(const char *str1,const char *str2,const size_t n);
char *strstr1(const char * str, const char *substr);

int main(){ 
 char strname[5];
 strname[0]=0;
 //printf("%d\n",strlen1(" "));
 //printf("%d\n",strlen1("wwwww"));
  
 //strcpy1(strname,"www");
 //printf("%s\n",strname);
 //strncpy1(strname,"wwwww",3);
 //printf("%s\n",strname);
 //strcat1(strname,"w");
 //strcat1(strname,"www");
 //printf("%s\n",strname);
 //printf("%p,%s",strchr("113322",'a'),strchr("113322",'a'));
 
}



size_t strlen1(const char *str){ //实现strlen函数的功能
  size_t ii=0;
  while (str[ii]!='\0') ii++;
  return ii;
}


char *strcpy1(char *dest,const char *src){
  size_t ii=0;
  while(src[ii]!='\0') {
    dest[ii]=src[ii];
    ii++;
  }
  dest[ii]=0;
  return dest;
}//实现strcpy函数,下同
char *strncpy1(char *dest,const char *src,size_t n){
  size_t ii=0;
  for(;src[ii]!='\0'&&ii<=n-1;ii++) {
    dest[ii]=src[ii];
  }
  dest[ii]=0;
  return dest;
  
}
char *strcat1(char *dest,const char *src){
  size_t ii,jj;
  ii=jj=0;
  while(dest[ii]!=0) ii++;
  while(src[jj]!=0){ dest[ii]=src[jj];ii++;jj++;}
  dest[ii]=0;
  return dest;
}
char *strchr1( char *s,const int c){
  size_t ii=0;
  for(ii=0;ii<=strlen1(s);ii++){
    if (s[ii]==c) return s+ii;
  }
  return 0;
}
char *strrchr1( char *s,const int c){
   size_t ii=0;
  for(ii=strlen1(s)-1;ii>=0;ii--){
    if (s[ii]==c) return s+ii;
  }
  return 0;
}

int strcmp1(const char *str1,const char *str2){
  int i=0;
  int clen=0;//字符串的较短那个的长度
  if(strlen1(str1)>strlen1(str2)) clen=strlen1(str2);
  else clen=strlen1(str1);
  for(i=0;i<clen;i++){
    if(str1[i]==str2[i]) continue;
    else break;
  }
  if(str1[i]>str2[i]) return 1;
  else if(str1[i]<str2[i]&&strlen1(str1)==strlen1(str2)) return 0;
  else return -1;
}
int strncmp1(const char *str1,const char *str2,const size_t n){
  int i=0;
  for(i=0;i<n;i++){
    if(str1[i]==str2[i]) continue;
    else break;
  }
  if(str1[i]>str2[i]) return 1;
  if(i==(n-1)) return 0;
  return -1;
}
char *strstr1(const char * str, const char *substr){
  char *pos=(char *)str;//待搜索字符串的位置
  char *pos1=0;
  while(1){
    if(pos[0]==0) break;//后面已经没有字符串了
    pos1=strchr1(pos,substr[0]);//在pos中查找字符串的首字母
    if(pos1==0) return 0;
    if(strncpy1(pos1,substr,strlen1(substr))==0) return pos1;
    pos++;
  }
 return 0;
}


