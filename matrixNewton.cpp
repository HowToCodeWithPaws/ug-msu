#include <stdio.h>
#include <math.h>
#include<stdlib.h>

const double der_eps = 0.001;
const double root_eps = 1e-15;

double f1 (double x1, double x2) {
	return ((x1)*(x1)+(x2)*(x2) - 1.);
}

double f2 (double x1, double x2) {
	return (x1 - x2);
}

double derivative1 (double (*function)(double x1, double x2), double x0, double x2) {
	return (function(x0 + der_eps, x2) - function(x0 - der_eps, x2))/(2*der_eps);
}

double derivative2 (double (*function)(double x1, double x2), double x1, double x0) {
	return (function(x1, x0 + der_eps) - function(x1, x0 - der_eps))/(2.*der_eps);
}


void move(int n, int m, double *a, int N, double *b, int i)
{
	double c;
	int j;
	
	for(j=0;j<N;j++)	{
		c=a[n*N+j];
		a[n*N+j]=a[N*i+n*N+j];
		a[N*i+n*N+j]=c;
	}
	
	c=b[n];
	b[n]=b[n+i];
	b[n+i]=c;
	return;
}

void prove(int n, int m, double *a, int N, double *b)
{
	int i;
	int remi;
	double max=0;
	
	for(i=0;i<N-n;i++){
		if(a[N*i+m+n*N]>max) {
		max=a[N*i+m+n*N];remi=i;
		}
	}
	move(n, m, a, N, b, remi);
	return;
}

int gauss(int n, int m, double *a, int N, double *b)
{
	int i,j;
	
	if(a[m+n*N]==0.) 
	prove(n,m,a,N,b);
	
	double c=a[m+n*N];
	if(c==0.) return 0;
	for(i=0;i<N;i++) a[n*N+i]/=c;
	b[n]/=c;
	for(i=1;i<N-n;i++)	{
		c=a[n*N+m+i*N];
		if(c==0.) break;
		for(j=0;j<N;j++)	{
			a[n*N+i*N+j]-=a[n*N+j]*c;//0
		}
		b[n+i]-=b[n]*c;
	}
	return 0;
}

void roots(double *a, int N, double *b, double *x)
{
	int i,j;
	double c;
	
	for(i=N-1;i>=0;i--)	{
		c=0.;
		
		for(j=N-1;j>i;j--){
			c+=x[j]*a[j+i*N];
		}
		x[i]=(b[i]-c)/a[i*N+i];
	
	}
}

int main(){

	double *a, *b, *x;
	double x1, x2, h1, h2;
	double r1, r2;
	int n,m;
	int N = 2;
	
	scanf("%lf %lf", &x1, &x2);
		
	a=(double*)malloc(N*N*sizeof(double));
	b=(double*)malloc(N*sizeof(double));
	x=(double*)malloc(N*sizeof(double));
	
	r1 = x1;
	r2 = x2;
		x[0]=10000.;
		x[1] = 100000.;
	while(fabs(x[0])>root_eps && fabs(x[1])>root_eps){	
	
	a[0]= derivative1(f1, x1, x2);
	a[1]= derivative2(f1, x1, x2);
	a[2]= derivative1(f2, x1, x2);
	a[3]= derivative2(f2, x1, x2);
	
	x[0] = h1;//
	x[1] = h2;//
	
	b[0] = f1(x1, x2);
	b[1] = f2(x1, x2);
	
	
	m=0;
	
	for(n=0;n<N;n++)	{
		gauss(n,m,a,N,b);
		m++;
	}



	roots(a,N,b,x);
	
	for (n=1;n<=N;n++) {
		printf("h%d = %lf\n", n, x[n-1]);
	}
	
		printf("x1 = %lf x2 = %lf\n", x1, x2);

	r1 = fabs(x1- x[0]);
	r2 = fabs(x2 - x[1]);
	
	x1 = r1;
	x2 = r2;
}

	printf("r1 = %lf r2 = %lf\n", r1, r2);
	
	return 0;

}
