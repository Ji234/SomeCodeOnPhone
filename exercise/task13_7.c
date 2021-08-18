//测试文件缓冲函数fflush的使用
//fflush()的作用是用来刷新缓冲区，fflush(stdin)刷新标准输入缓冲区，把输入缓冲区里的东西丢弃； fflush(stdout)刷新标准输出缓冲区，把输出缓冲区里的东西强制打印到标准输出设备上。
//      fflush(stdin)不太常用，在有些编译器中是错误的用法，可以用以下方法替代：while(getchar()!='/n');
//      fflush(stdout)在单进程程序中作用不大，但在多进程程序中很有用。程序的输出内容一般不会立即输出，而是在程序结束后再输出。fflush(stdout)会强制每次printf()都立即显示在标准输出设备上。
//
//
 #include<stdio.h>  
 #include<unistd.h> 
int main()
{
     printf("hello");
     fflush(stdout);
     fork();            //父子进程共享同样的文件位置和内容
     return 0;
 }
