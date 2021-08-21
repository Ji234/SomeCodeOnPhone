//演示c语言预处理
//#define是直接进行复制
//C语言预处理不进行语法判断,预处理代码是gcc -E -o filename srefilename
#define PI 3.1415926

int main(){
  #ifdef PI
  printf("PI is %lf\n",PI);
	#else 
	printf("no a define called PI\n");
  #endif
  #undef PI
	printf("after undef---------------\n");
	#ifdef PI
  printf("PI is %lf\n",PI);
	#else 
	printf("no a define called PI\n");
	#endif
}
