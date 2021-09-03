//test the c++ class string's number function

#include <stdio.h>
#include <string>

int main(){
		std:: string str;
		str="This is a string";
		printf("%s\n",str.c_str());
		printf("%lu\n",str.size());
		printf("%lu\n",str.length());
		str.clear();
		printf("%s\n",str.c_str());
}
