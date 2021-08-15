//演示#ifdef 的条件编译

#define LINUX

int main(){
  #ifdef LINUX
    printf("这是linux操作系统\n");
  #else 
    printf("这是未知操作系统");
  #endif
}
