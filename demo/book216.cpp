//show the c++ string point change

#include <stdio.h>
#include <string>

int main(){
		std::string str;
		str="www";
		printf("%p\n",str.c_str());
		str+="wwwwwwwwwwwwwwwwwwwwwww";
		printf("%p\n",str.c_str());
		str+="wwwwwwwwwwwwwwwwwwwwwwwwwwwww";
		printf("%p\n",str.c_str());
		printf("%s\n",str.c_str());
}
//by this function you can fing that the string's point had changed
//because the string find it cant put all char it while free the memory and alloc new memory to save the new string
