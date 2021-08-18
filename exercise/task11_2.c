//丰富您的库函数,增加STRCPY,STRNCPY,STRCAT,STRNCAT四个安全函数,弥补数据库的缺陷,解决dest的初始化和内存越界的问题,函数的声明如下:

#include<stdio.h>
char *STRCPY(char *dest,const size_t destsize,const char*src);
char *STRNCPY(char *dest ,const size_t destsize,const char *src,size_t n );
char *STRCAT(char *dest ,const size_t destsize,const char *src);
char *STRNCAT(char *dest ,const size_t destsize,const char *src,size_t n );

int main(){
 char sname[10];
 memset(sname,0,sizeof(sname));
 strcpy(sname,"abc");
 printf("%s\n\n",STRCPY(sname,10,"0123456789aa"));
 strcpy(sname,"abc");
 printf("%s\n\n",STRNCPY(sname,10,"0123456789aa",5));
 strcpy(sname,"abc");
 printf("%s\n\n",STRCAT(sname,10,"0123456789aa"));
 strcpy(sname,"abc");
 printf("%s\n\n",STRNCAT(sname,10,"0123456789aa",5));
}
char *STRCPY(char *dest,const size_t destsize,const char *src){     
  char *r=dest;
  int i=0;
  int len1;
  sizeof(src)< destsize/sizeof(char)?(len1=sizeof(src)): (len1=destsize/sizeof(char));
  while((*r++=*src++)&&i<len1) i++;
  return dest;
}
char *STRNCPY(char *dest ,const size_t destsize,const char *src,size_t n ){
  char *r=dest;
  int i=0;
  int len1;
  sizeof(src)< destsize/sizeof(char)?(len1=sizeof(src)): (len1=destsize/sizeof(char));
  while((*r++=*src++)&&(i<len1)&&(i<n)) {i++;}
  dest[i]=0;
  return dest;
}

char *STRCAT(char *dest ,const size_t destsize,const char *src)
{
  int slen=0;
  int i=0;
  while(dest[slen]!='\0') slen++;
  char *r=dest+slen;
  int len1;
  sizeof(src)< destsize/sizeof(char)?(len1=sizeof(src)): (len1=destsize/sizeof(char));
  while((*r++=*src++)&&(i<destsize-slen)) i++;
  dest[i-1+slen]=0;
  return dest;
}
char *STRNCAT(char *dest ,const size_t destsize,const char *src,size_t n )
{
  int slen=0;
  int i=0;
  while(dest[slen]!='\0') slen++;
  char *r=dest+slen;
  int len1;
  sizeof(src)< destsize/sizeof(char)?(len1=sizeof(src)): (len1=destsize/sizeof(char));
  while((*r++=*src++)&&(i<destsize-slen)&&(i<n)) i++;
  dest[i+slen]=0;
  return dest;
}
