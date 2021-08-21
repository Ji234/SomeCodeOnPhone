//获取目录下面的所有文件和文件夹

#include <stdio.h>
#include <dirent.h>

int ReadDir(char *strpathname){
	DIR *dir;
	char strdirpath[256];
	struct dirent *stdinfo;
	if((dir=opendir(strpathname))==0) return -1;
	while(1){
	  if((stdinfo=readdir(dir))==0) break;
		if(strncmp(stdinfo->d_name,".",1)==0) continue;//以.开始的文件不读
    if(stdinfo->d_type==8){
			printf("name=%s/%s\n=n",strpathname,stdinfo->d_name);
		}
    if(stdinfo->d_type==4){
			sprintf(strdirpath,"%s/%s",strpathname,stdinfo->d_name);
			ReadDir(strdirpath);
		}
	}
		closedir(dir);
		return 0;
}
int  main(int argc,char *argv[]){
  if(argc!=2){printf("请输入目录名");return -1; }
   ReadDir(argv[1]);
}
