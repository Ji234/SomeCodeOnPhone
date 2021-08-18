//增加函数freecplus框架中的函数

//删除字符串左边指定的的字符

#include <stdio.h>
void DelectLChar(char * str,const char in_char){
  int i=0;
  int slen=0;
  while(str[slen]!=0) ++slen;
  printf("%d\n",slen);
  for(i=0;i<slen;i++){
    if(str[i]==in_char){
       for(;i<slen-1;i++){
		 if(i==slen-1) str[i]=0;
		 else str[i]=str[i+1];
	   }
	   str[slen-1]=0;
	   break;
      }
  }

}
//删除字符串右边的指定字符
void DelectRChar(char *str,const char in_char);
//删除字符串两边的指定字符
void DelectLRChar(char *str,const char in_char);
//删除字符串中间的字符串
void DelectMstr(char *str,const char in_char);
//在字符串的右边补字符到指定长度
void LPad(char *str,const char in_char,unsigned int in_len);
//在字符串的左边补字符到指定长度
void RPad(char *str,const char in_char,unsigned int int_len);
//把小写换成大写,忽略不是字母的字符
void ToUpper(char *str);
//把大写换成小写,忽略不是字母的字符
void ToLower(char *str);
//判断内容是不是全部是数字
int IsDigit(const char *str);
//判断内容是不是全部是大写字母
int IsUpper(const char *str);
//判断内容是不是全部是小写字母
int IsLower(const char *str);
//判断内容是不是全部是ASCII字符
int IsASCII(const char *str);

int main(){
  char sname[31];
  memset(sname,0,sizeof(sname));
  strcpy(sname,"0123456789");
  DelectLChar(sname,'7');
  printf("%s\n",sname);
}

