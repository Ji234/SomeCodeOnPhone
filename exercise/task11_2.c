//丰富您的库函数,增加STRCPY,STRNCPY,STRCAT,STRNCAT四个安全函数,弥补数据库的缺陷,解决dest的初始化和内存越界的问题,函数的声明如下:

char *STRCPY(char *dest,const size_t destsize,const char *src);
char *STRNCPY(char *dest ,const size_t destsize,const char *src,size_t n );
char *STRCAT(char *dest ,const size_t destsize,const char *src,const char * src);
char *STRNCAT(char *dest ,const size_t destsize,const char *src,size_t n );

