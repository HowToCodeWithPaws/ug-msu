#include<stdio.h>
#include<math.h>

int main(){
	int i;
	double y[6];
	FILE* reout;
	FILE* anout;
		
	y[0] = 1.;
	y[1] = 2.;
		
	for(i = 2; i<6; i++){
		y[i] = 3./2.*y[i-1]+y[i-2];
	}
		
	reout = fopen ("reout.txt", "w");
	anout = fopen ("anout.txt", "w");
	
	for(i = 0; i<6; i++){
		printf("%d %lf %lf\n", i, y[i], pow(2., (double)i) );
		fprintf(reout, "%d %lf\n", i, y[i]);
		fprintf(anout, "%d %lf\n", i, pow(2., (double)i));
	}
}
