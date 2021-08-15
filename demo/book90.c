//演示c语言结构体占用内存的情况
#include <stdio.h>
#pragma pack(1)//可以使内存对齐,不会在内存之中产生空隙
struct st_girl{
  char name[50];
  char sc[30];//身材,火辣,普通,飞机场
  char yz[30];//颜值,漂亮,一般,外瓜裂枣
  int age,height;
};
int main(){
  struct st_girl queen;
  printf("sizeof(struct st_girl)  %lu\n",sizeof(struct st_girl));
  printf("sizeof(queen)  %lu\n",sizeof(queen));
  return 0;
}


















































