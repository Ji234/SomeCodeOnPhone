//演示c语言结构体的访问
#include <stdio.h>
#include <string.h>
#pragma pack(1)//可以使内存对齐,不会在内存之中产生空隙
struct st_girl{
  char name[50];
  int age;
};
int main(){
  struct st_girl *pst,queen;
  //初始化结构体
  memset(&queen,0,sizeof(struct st_girl));
  pst=&queen;
  //给结构体成员赋值
  strcpy(pst->name,"武则天");
  pst->age=28;
  printf("name:%s\n",queen.name);
  printf("age:%d\n",queen.age);
  printf("name:%s\n",pst->name);
  printf("age:%d\n",pst->age);
  return 0;
}
