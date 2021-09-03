//c++ vector reserve integer data

#include <stdio.h>
#include <vector>
#include <algorithm> //this head file include sort()

int main(){
		int heigth=0;
		std::vector <int> vheigth;//a vector to reseve heigth
		while(true){
				printf("please input heigth(input 0 to end):");
				scanf("%d",&heigth);//input a number simple of heigth
				if(heigth==0) break;//input 0 to break 
				vheigth.push_back(heigth);
		}
		for(int i=0;i<vheigth.size();i++){
				printf("vheigth[%d]=%d\n",i,vheigth[i]);
		}
		sort(vheigth.begin(),vheigth.end());//sort item in the vheigth
		printf("after sort data\n\n");
		for(int i=0;i<vheigth.size();i++)
		{
				printf("vheigth[%d]=%d\n",i,vheigth[i]);
		}
		vheigth.clear();
		printf("after clear data\n\n");
		for(int i=0;i<vheigth.size();i++)
		{
				printf("vheigth[%d]=%d\n",i,vheigth[i]);
		}

}
