#include<stdio.h>
#include<stdlib.h>
#include<math.h>

	double f(double t, double pi);
	double scal (double* F, double* G, int N);

int main(){
	double* F;
	double* G;
	int N;
	int n;
	double dt;
	int i;
	double pi;
	double* coef;
	double max;


	N = 1024;
	pi = 4.*atan(1.);
	dt = 1./N;
		
	coef = (double*)malloc((N+1)*sizeof(double));
	F = (double*)malloc((N+1)*sizeof(double));
	G = (double*)malloc((N+1)*sizeof(double));
	coef = (double*)malloc((N+1)*sizeof(double));
		if (F == NULL)
			return 0;
		if (G == NULL)
			return 0;
		if (coef == NULL)
			return 0;
			
	printf("111\n");
	for (n=1; n<N; n++){
	for (i=0; i<= N; i++){
		F[0]=F[N]=0;
		F[i]=f(i*dt, pi);
		G[i]=sin(pi*n*(double)i/N);
	}
			coef[n] = scal (F, G, N)/scal(G, G, N);
		printf ("%lf\n", coef [n]);

	}
	
	max = fabs(coef[1]);
	for (n=1; n < N; n++){
		if (fabs(coef[n])> max)
			max = fabs(coef[n]);
}
	printf("%lf", max);
	
	for (n=1; n<N; n++){
		if (((F[n]-(coef[n]*G[n]))/(F[n]))*100 < 1){
		coef[n]= 0;
		printf ("%d", n);}
}
}

double f(double t, double pi){
	pi = 4.*atan(1.);
	return (10*sin(pi*t)/(25*pi*pi*t*t + 1));
}

double scal (double* F, double* G, int N){
		int i;
		double k = 0.0;
	for (i=0; i<=N; i++){
	k = k + F[i]*G[i];
	}
	return k;
}

