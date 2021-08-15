//重写库函数POW
#include <stdio.h>
int POW(unsigned int x,unsigned int y){
    int i,temp;
    temp=x;
    if(y==0) return 1;
    else{
    for(i=0;i<y-1;i++){
      temp*=x;
    }
    return temp;
  }
}
int main(){
 printf("POW(2,12)结果是%d\n",POW(2,12));
return 0;
}
