// book201.c 此程序用来演示c++函数缺省
#include <stdio.h>
#include <string.h>
//我们可以看到当dest=1时候不用传参数也不会报错
//而且结果得到的是按照程序原定的结果得到打印结果
char  *strcpy(char *dest,char *src,int destsize=1 ){
		int i=0;
		for(i=0;i<destsize;i++){
				if(src[i]=='\0') break;
				dest[i]=src[i];
		}
		dest[i]=0;
		return dest;
}

int main(){
		char teststr[]="abcdefghijklmnopqr";
		char deststr[50];
		memset(deststr,0,sizeof(deststr));
		strcpy(deststr,teststr);
		printf("1.%s\n",deststr);
		strcpy(deststr,teststr,10);
		printf("2.%s\n",deststr);

}
