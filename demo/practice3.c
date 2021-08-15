#include <stdio.h>
int main(){
	float fahr,celsius;
	float lower,upper,step;

	lower=0;
	upper=300;
	step=20;
	fahr=lower;
	printf("transformed fahr to celsius\n");
	while(fahr<=upper){
		celsius=5*(fahr-32)/9;
		printf("%3.0f%8.2f\n",fahr,celsius);
		fahr=fahr+step;
	}
}

