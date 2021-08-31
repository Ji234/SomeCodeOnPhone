// book201.c 此程序用来演示c++函数重载
#include <stdio.h>
#include <string.h>
char  *strcpy(char *dest,char *src,int destsize ){
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
		//这里调用了两个不同的strcpy函数
		//函数重载
		strcpy(deststr,teststr);
		printf("1.%s\n",deststr);
		strcpy(deststr,teststr,10);
		printf("2.%s\n",deststr);

}
