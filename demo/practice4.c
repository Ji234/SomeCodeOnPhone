#include <stdio.h>
int main(){
	float fahr,celsius;
	float lower,upper,step;

	lower=0;
	upper=300;
	step=20;
	celsius=lower;
	printf("transformed celsius to fahr\n");
	while(celsius<=upper){
		fahr=9*celsius/5+32.0;
		printf("%3.0f%8.2f\n",celsius,fahr);
		celsius=celsius+step;
	}
}

