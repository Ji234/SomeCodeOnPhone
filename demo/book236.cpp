//book236.cpp 类的多态
#include <stdio.h>
#include <string.h>

class CGirl{
		public:
		char m_name[50];//name
		int m_age;//age
		int m_heigth;//heigth
		int show(){
		printf("name:%s\nage:%d\nheigth:%d\n",m_name,m_age,m_heigth);
		return 0;
		}
};

class CKCon:public CGirl{
		public:
				char m_ch[50];//nickname
				char m_palace[50];//house palace
				int m_sal;//salary
				int show(){
						printf("name:%s\nnickname:%s\npalace:%s\nsalary:%d\nage:%d\nheigth:%d\n",m_name,m_ch,m_palace,m_sal,m_age,m_heigth);
						return 0;
				}
};
int main(){
	CKCon KCon;//实例化一个对象
	strcpy(KCon.m_name,"Tom");
	KCon.m_age=28;
	KCon.m_heigth=170;
	strcpy(KCon.m_palace,"somewhere");
	strcpy(KCon.m_ch,"baby");
	KCon.m_sal=170;
	CGirl *pGirl;
	CKCon *pKCon;
	pGirl=pKCon =&KCon;
	pGirl->show();
	pKCon->show();
}

