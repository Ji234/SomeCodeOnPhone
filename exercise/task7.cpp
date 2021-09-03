//show the operator reload 
#include <stdio.h>
#include <string.h>

class CGirl{
		public:
		char m_name[50];//name
		char m_sc[30];//stature
		bool operator !=(const CGirl &Girl);//reload string
};

bool CGirl:: operator!=(const CGirl &Girl){
		if(strcmp(m_name,Girl.m_name)!=0)	return true;
		return false;
} 
int main(){
		CGirl Girl1,Girl2;
		strcpy(Girl1.m_name,"张三");
		strcpy(Girl2.m_name,"李四");
		if(Girl1!=Girl2) printf("Girl1 and Girl2 not is a man\n");
		else printf("Girl1 and Girl2 is a man\n");
}
