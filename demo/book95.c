//演示c语言结构体作为函数参数传递
#include <stdio.h>
#include <string.h>
#pragma pack(1)//可以使内存对齐,不会在内存之中产生空隙
struct st_girl{
  char name[50];
  int age;
};

void setvalue(struct st_girl *pst);
int main(){
  struct st_girl *pst,queen,girl1;
  //初始化结构体
  memset(&queen,0,sizeof(struct st_girl));
  setvalue(&queen);
  return 0;
}

void setvalue(struct st_girl *pst){
  strcpy(pst->name,"武则天");
  pst->age=28;
  //给结构体成员赋值
  printf("name:%s\n",pst->name);
  printf("age:%d\n",pst->age);

}
