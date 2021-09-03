//show reference as a function return 
#include <stdio.h>
int value;

int func1(int i){
		value=i+10;
		return value;
}

int &func2(int i){
		//int this way you can find reference equal the noumenon(本体)
		value=i+20;
		return value;
}

int main(){
		int aa,bb;
		aa=func1(10);
		bb=func2(20);
		int cc=func2(20);
		printf("aa=%d\n",aa);
		printf("bb=%d\n",bb);
		printf("cc=%d\n",cc);
}
//notice:
//cannt use the function parameter(参数) as the return 
//cannt use the mallac memory,or else you cannt free memory
