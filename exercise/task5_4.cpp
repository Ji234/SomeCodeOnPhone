//wirte a function that can do same of printf sprintf snprintf
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int Myprintf(const char *format,...){
		va_list arg;
		va_start(arg,format);
		vprintf(format,arg);
		va_end(arg);
		return 0;
}

int Mysprintf(char *str,const char *format,...){

}

int Mysnprintf(char *str,size_t size ,const char *format,...){
}

int main(){
		Myprintf("test this function\n");
}

