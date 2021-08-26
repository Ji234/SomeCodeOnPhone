#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc ,char *argv[]){
		if(argc!=2) {printf("输入文件或者目录名");return -1;}//判断时候输入文件名
		char strfilename[150][31];//存储文件名
		memset(strfilename,0,sizeof(strfilename));//初始化0
  FILE *fp;//打开文件
		DIR *dir;
		struct dirent *stdinfo;//存放目录中的文件信息
		int i=0;
		if((dir=opendir(argv[1]))==0) {printf("打开目录失败");return -1;}
		if((fp=fopen("makefile","w"))==0) {printf("打开文件失败");return -1;}
		fprintf(fp,"all:");
		while(1){
				//读出目录里的文件来
				if((stdinfo=readdir(dir))==0) break;
				if((stdinfo->d_type==8)&&strcmp(stdinfo->d_name+(strlen(stdinfo->d_name)-2),".c")==0){
				strncpy(strfilename[i],stdinfo->d_name,strlen(stdinfo->d_name)-2);
				fprintf(fp,"%s ",strfilename[i]);
				i++;
				}
		}
		fprintf(fp,"\n\n");
		for(i=0;i<150;i++){
				if(strfilename[i][0]==0) break;
				fprintf(fp,"%s:\n",strfilename[i]);
				fprintf(fp,"\tgcc -o %s %s.c\n",strfilename[i],strfilename[i]);
		}
		fprintf(fp,"clean:\n\trm -f ");
				for(i=0;i<150;i++){
				if(strfilename[i][0]==0) break;
				fprintf(fp,"%s ",strfilename[i]);
		}
		closedir(dir);
		fclose(fp);
}
