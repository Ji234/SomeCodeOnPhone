//演示c语言结构体的访问
#include <stdio.h>
#include <string.h>
#pragma pack(1)//可以使内存对齐,不会在内存之中产生空隙
struct st_girl{
  char name[50];
  char sc[30];//身材,火辣,普通,飞机场
  char yz[30];//颜值,漂亮,一般,外瓜裂枣
  int age,height;
};
int main(){
  struct st_girl queen;
  //初始化结构体
  memset(&queen,0,sizeof(struct st_girl));
  //给结构体成员赋值
  strcpy(queen.name,"武则天");
  queen.age=28;
  queen.height=170;
  strcpy(queen.sc,"火辣");
  strcpy(queen.yz,"漂亮");

  printf("name:%s\n",queen.name);
  printf("age:%d\n",queen.age);
  printf("height:%d\n",queen.height);
  printf("sc:%s\n",queen.sc);
  printf("yz:%s\n",queen.yz);
  return 0;
}


















































