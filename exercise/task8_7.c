//重写ABS和LABS库函数
#include <stdio.h>
int ABS(int num){
 if(num>=0)num=num;
 else num=-num;
 return num;
}

long LABS(long int num){
 if(num>=0)num=num;
 else num=-num;
 return num;
}
int main(){
  int i=-3;
  long int li=-3892251689;
  i= ABS(i);
  li=LABS(li);
  printf("abs int=%d,abs long int =%ld\n",i,li);
}
