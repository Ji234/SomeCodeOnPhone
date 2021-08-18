//输入五名超女结构体,存放在struct st_girl数据结构数组中,然后把结构体数组放在二进制文件中
#include <stdio.h>

struct st_girl
{
  char name[51];//姓名
  int age;      //年龄
  int height;   //身高,单位cm
  double weight;//体重kg
  char sc[31];  //身材,火辣,普通,飞机场
  char yz[31];  //颜值,漂亮,一般,外瓜裂枣
};
char *toxml( char * str, struct st_girl *girl,size_t n){
   int i=0;
   char temp[200];
   for(i=0;i<n;i++){
   sprintf(temp,"<age>%d</age><height>%d</height><weight>%f</weigth><name>%s</name></sc>%s<sc><yz>%s</yz>\n\n",girl[i].age,girl[i].height,girl[i].weight,girl[i].name,girl[i].sc,girl[i].yz);
   strcat(str,temp);
   }
   return str;
}
int main(){
  struct st_girl someone;
  struct st_girl girls[6];
  memset(&girls,0,sizeof(girls));//初始化结构体
  char sxml[1000];//放置转换好的xml字符串
  int i;
  FILE *fp;
  if((fp=fopen("file","w"))==0){
    printf("打开文件file失败");
	return -1;
  }
  //赋值
  strcpy(someone.name,"aaa");
  someone.age=20;
  someone.height=170;
  someone.weight=60;
  strcpy(someone.yz,"漂亮");
  strcpy(someone.sc,"火辣");
  //把someone赋值到girls的每一个空间
  for(i=0;i<sizeof(girls)/sizeof(someone);i++) memcpy(girls+i,&someone,sizeof(someone));
  toxml(sxml,girls,sizeof(girls)/sizeof(someone));                                                                      
  fwrite(&girls,1,sizeof(girls),fp);
  printf("%s\n",sxml);
}

