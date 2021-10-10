#include <stdio.h>
#include <string.h>
int main(){
	FILE *fp=0;
	fp=fopen("test.txt","r+");
	if(fp==0){
		printf("打开文件失败");
		return -1;
	}
	char str[301];
	int i=0;
	printf("%d\n",ftell(fp));	
	while(i<10){
		memset(str,0,sizeof(str));
		//if(fscanf(fp,"%s",&str)==0) break;
		if(fgets(str,301,fp)==0) break;
		fseek(fp,-1,1); 
		fwrite("  8\n",1,4,fp);
		fseek(fp,2,1); 
		printf("%d\n",ftell(fp));
		printf("%s",str);
		i++;
	}
	//printf("%ld\n",ftell(fp));
	fclose(fp);
}

