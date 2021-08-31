//演示对象数组,对象指针,对象作为函数参数的用法
#include <stdio.h>
class Person{
public:
		int p_age;//年龄
		int p_heigth;//身高
		int p_weigth;//体重
		char p_xl[20];//学历:小学,初中,高中,大学
		char p_ck[30];//存款:1万,10万,100万,1000万
		char p_yz[30];//颜值:漂亮,一般,差劲
		int show();
};
int Person::show(){
		printf("age:%d\nheigth%d\nweigth%d\nxl:%s\nck:%s\nyz:%s\n",p_age,p_heigth,p_weigth,p_xl,p_ck,p_yz);
		return 0;
}
void rich_ok(Person someone){
		if(someone.p_heigth>80)
				printf("这个人是胖子\n");
		else printf("这个人不是胖子\n");
}
int main(){
		Person pinroom[10];
		Person *aman=&pinroom[0];
		pinroom[0].p_age=10;
		pinroom[0].p_heigth=150;
		pinroom[0].p_weigth=50;
		strcpy(pinroom[0].p_xl,"小学");
		strcpy(pinroom[0].p_ck,"1万");
		strcpy(pinroom[0].p_yz,"一般");
		pinroom[0].show();
		rich_ok(pinroom[0]);
		printf("这个人的年纪是%d岁\n",aman->p_age);
}
