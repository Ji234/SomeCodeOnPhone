//演示c语言结构体的复制
#include <stdio.h>
#include <string.h>
#pragma pack(1)//可以使内存对齐,不会在内存之中产生空隙
struct st_girl{
  char name[50];
  int age;
};
int main(){
  struct st_girl *pst,queen,girl1;
  //初始化结构体
  memset(&queen,0,sizeof(struct st_girl));
  pst=&queen;
  strcpy(pst->name,"武则天");
  pst->age=28;
  memcpy(&girl1,pst,sizeof(struct st_girl));
  //给结构体成员赋值
  printf("name:%s\n",girl1.name);
  printf("age:%d\n",girl1.age);
  return 0;
}
