#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int t,  x, T=100, L=10;
	double ta, h;
	double U[T+1][L+1];
	h = 1./L;
	ta = h*h/2.;
	FILE* out;

	out = fopen("testheating.txt", "w");
	
	for(x=0; x<L; x++){
	U[0][x] = exp(x*h);
}
	
	for (t=0; t<T; t++){
		for(x=1; x<L; x++){
	
		U[t+1][x] = U[t][x] + ta/h/h*5*(U[t][x+1]-2*U[t][x]+U[t][x-1])+ ta*sin(x*h)*exp(t);	
	}
		U[t+1][0] = sin(t);
		U[t+1][L] = cos(t);
	}
	
	for (t=0; t<=T; t++){
		for(x=0; x<L; x++){
			fprintf(out, "%d %d %lf\n", t, x, U[t][x]);
			printf("%d %d %lf\n", t, x, U[t][x]);
			
}
}
}
