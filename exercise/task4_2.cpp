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

void level(Cgirl someone){
		if((someone.age>18&&someone.age<25)&&(someone.heigth>165&&someone.heigth<178)&&(strcmp(someone.sc,"火辣")==0)&&(strcmp(someone.yz,"漂亮")==0))
				printf("妃子\n");
		if((someone.age>18&&someone.age<30)&&(someone.heigth>165&&someone.heigth<165)&&(strcmp(someone.sc,"普通")==0||strcmp(someone.sc,"火辣")==0)&&(strcmp(someone.yz,"一般")==0))
				printf("宫女\n");
		if((someone.age>35&&someone.age<40)&&(someone.heigth>155&&someone.heigth<165)&&(strcmp(someone.sc,"普通")==0||strcmp(someone.sc,"飞机场")==0)&&(strcmp(someone.yz,"一般")==0))
				printf("杂役\n");
}
int main(){
		Cgirl girl;
		girl.age=19;
		girl.heigth=177;
		strcpy(girl.sc,"火辣");
		strcpy(girl.yz,"漂亮");
		girl.show();
		level(girl);

}
