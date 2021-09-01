//test class number variable visit permision 
#include <stdio.h>

class Test{
private:
//		int pri;
public:
		int pub;
};
int main(){
		Test ts;
//		ts.pri=10;
//		error
		ts.pub=20;
		printf("%d\n",ts.pub);
}
