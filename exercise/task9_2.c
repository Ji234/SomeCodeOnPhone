//编写几个库函数
#include <stdio.h>

//判断是不是字母
int ISALPHA(int ch){
  if((ch>=65&&ch<=(65+25))||(ch>=97&&ch<=(97+25))) return 1;
  else return 0;
}

//判断是不是字母或者数字
int ISALNUM(int ch){
  if((ch>=65&&ch<=(65+25))||(ch>=97&&ch<=(97+25))||(ch>=48&&ch<=48+9)) return 1;
  else return 0;
}

//判断是不是数字
int ISDIGIT(int ch){
  if(ch>=48&&ch<=48+9) return 1;
  else return 0;
}
//判断是不是大写字母
int ISUPPER(int ch){
  if(ch>=65&&ch<=(65+25)) return 1;
  else return 0;
}
//判断是不是小写字母
int ISLOWE(int ch){
  if((ch>=97&&ch<=(97+25))) return 1;
  else return 0;
}

//大写字母返回小写字母
char TOLOWER(int ch){
  if(ch>=65&&ch<=(65+25)) return ch+(97-65);
  else return ch;
}

//小写字母返回大写
char TOUPPER(int ch){
  if(ch>=97&&ch<=(97+25)) return ch-97+65;
  else return ch;
}
int main(){
  char cy='a';
  char cn='2';
  printf("cy is char %d\n",ISALPHA(cy));
  printf("cn is char %d\n",ISALPHA(cn));
  printf("---------------------------\n");
  printf("cy is char or int %d\n",ISALNUM(cy));
  printf("cn is char or int %d\n",ISALNUM(cn));
  printf("---------------------------\n");
  printf("cy is lower char %d\n",ISLOWE(cy));
  printf("cn is lower char %d\n",ISLOWE(cn));
  printf("---------------------------\n");
  printf("cy to upper %c\n",TOUPPER(cy));
  printf("---------------------------\n");
return 0;
}
