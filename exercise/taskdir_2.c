//change dir
//use chdir() to change work  dir
#include <stdio.h>

int main(){
  char  dirname[301];
  getcwd(dirname,300);
  printf("local directory is: %s\n",dirname);
  chdir("..");
  getcwd(dirname,300);
  printf("local directory is: %s\n",dirname);
}
