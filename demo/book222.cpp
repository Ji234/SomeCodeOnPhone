//c++ vector reserve string data

#include <stdio.h>
#include <vector>
#include <algorithm> //this head file include sort()
#include <string>
int main(){
		char str[50];
		std::vector <std::string> vname ;
		while(true){
				printf("please input name(input 0 to end):");
				scanf("%s",str);
				if(strcmp(str,"0")==0) break;
				vname.push_back(str);
		}
		for(int i=0;i<vname.size();i++){
				printf("vname[%d]=%s\n",i,vname[i].c_str());
		}
}
