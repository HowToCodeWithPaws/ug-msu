#include<stdio.h>
#include<stdlib.h>
#include<math.h>

	double f(double t);
	double scal (double* F, double* G, int N);


int main(){
	FILE * out;
	double* F;
	double* G;
	int N = 10;
	int n;
	double dt = 1./(int)N;
	int i;
	double m ;
	m = 3.14;
	
	out = fopen("data.txt", "w");
	F = (double*)malloc((N+1)*sizeof(double));
	G = (double*)malloc((N+1)*sizeof(double));
		if (F == NULL)
			return 0;
		if (G == NULL)
			return 0;
			
	for (n=1; n<N; n++){
	for (i=0; i<= N; i++){
		F[i]=f(i*dt);
		G[i]=sin(m*n*(double)i/N);
	}}
		
	for (i=0; i<= N; i++)	
//	printf ("%lf %lf\n", dt*i, F[i]);
	
	printf ("%lf", scal (F, G, N)/scal(G, G, N));
}

double f(double t){
	return t*(1-t);
}

double scal (double* F, double* G, int N){
		int i;
		double k = 0.0;
	for (i=0; i<=N; i++){
	k = k + F[i]*G[i];
	}
	return k;
}
