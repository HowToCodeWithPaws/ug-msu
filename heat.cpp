#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const double PI = 22./7.;

int main(){
	int n, m, M=20, N=500;
	double h, ta;
	double U[M+1][N+1];
	h = 1./M;
	ta = 1./N;
	FILE* out;
	N=500;
	ta = h*h/2.;
	
	out = fopen("heat.txt", "w");
	
	for(m=0; m<=M; m++)
	U[m][0] = sin(PI*m*h);
	
	for (n=0; n<N; n++){
		for(m=1; m<M; m++){
	
		U[m][n+1] = U[m][n] + ta/h/h*(U[m+1][n]-2*U[m][n]+U[m-1][n])+ ta*sin(5.*PI*m*h);	
	}
		U[0][n+1] = 0;
		U[M][n+1] = 0;
	}
	
	for (n=0; n<=N; n++){
		for(m=0; m<=M; m++){
			fprintf(out, "%d %d %lf\n", m, n, U[m][n]);
			printf("%d %d %lf\n", m, n, U[m][n]);
			
}
}
}
