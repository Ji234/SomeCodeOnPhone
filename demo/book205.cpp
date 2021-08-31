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
		Cgirl girl;
		girl.age=10;
		girl.heigth=10;
		strcpy(girl.sc,"火辣");
		strcpy(girl.yz,"漂亮");
		girl.show();
}
