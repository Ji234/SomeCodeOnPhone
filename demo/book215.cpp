//demo of c++ string class

#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
		char str1[31];
		memset(str1,0,sizeof(str1));//string of c
		strcpy(str1,"西施");
		
		string str2;
		str2="沉鱼";//give a value to str2

		printf("str2=%s\n",str2.c_str());

		if(str2!=str1) printf("str1=%sstr2=%sdont equal\n",str1,str2.c_str());

		strcpy(str1,str2.c_str());//copy the c++ string style to c string
		printf("str1=%s\n",str1);
}

