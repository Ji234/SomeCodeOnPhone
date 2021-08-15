//随机数生成
#include <time.h>
#include <stdio.h>
#include<stdlib.h>
int main(){
 srand(time(0));
 int i ;
 for (i=0;i<5;i++){
 printf("%d\n",rand()%30);
 //产生一定范围的随机数
 printf("%d\n",rand());
 }
}
