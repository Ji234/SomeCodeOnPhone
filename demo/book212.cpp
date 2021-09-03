//show the reference feature 
#include <stdio.h>

void func(int *a){
		*a=20;
}

void func(int &ra){
		//by this way you can change data int function
		//the function can reload too.
		ra=40;
}

int main(){
		int i=0;
		func(i);//reference
		printf("reference i=%d\n",i);
		func(&i);//point
		printf("point i=%d\n",i);
}
