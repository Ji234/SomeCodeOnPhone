//test construction function reload
#include <stdio.h>

class Test{
public:
		int ii;
		Test();
		Test(int input);
};
Test::Test(){
				ii=0;
				printf("%d\n",ii);
		}
Test::Test(int input){
				ii=input;
				printf("%d\n",ii);
		}
int main(){

		Test ts1(40);
		Test ts;
		printf("ts=%d\n",ts.ii);
		printf("ts1=%d\n",ts1.ii);
}
