//book202.cpp此程序用来演示c++结构体的新特征
#include <stdio.h>
#include <string.h>

class Cgirl{
public:
		int age;//年龄
		int heigth;//身高
		char sc[30];//身材:火辣,一般,飞机场
		char yz[30];//颜值:漂亮,一般,歪瓜裂枣
		int show();
};
int Cgirl::show(){
		printf("年龄:%d\n身高:%d\n身材:%s\n颜值:%s\n", age, heigth, sc, yz);
		return 0;
}

int main(){
		Cgirl girl[10];
		for(int i;i<10;i++){
		girl[i].age=10;
		girl[i].heigth=10;
		strcpy(girl[i].sc,"火辣");
		strcpy(girl[i].yz,"漂亮");
		girl[i].show();
		printf("%d\n\n",i);
		}
		//girl.show();
		//这地方就像数组一样,不能直接调用
		//放在循环里面要加编号
}
