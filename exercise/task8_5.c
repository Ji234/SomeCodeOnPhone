//c语言技术网作业8-5
#include <stdio.h>
int main (){
  long long int test_inteager,test;
  test=0;
  int i;
  long long int max,min,temp;
  max=min=temp=1;
  printf("%lu\n",sizeof(test_inteager));
  for(i=0;i<63;i++){
  temp=temp*(-2);
  if(temp>max) max=temp;
  else min=temp;
  }
  printf("%lld\n",max);	
  //这样应该就可以算出最小值是-9223372036854775808
  //当然最大值就是他的正数减1
  min++;
  printf("%lld\n",min);	
  return 0;
}

