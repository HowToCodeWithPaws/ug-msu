#include <stdio.h>
#include <math.h>
#include<stdlib.h>

const double der_eps = 0.001;
const double root_eps = 1e-15;

double f1 (double x, double y, double z) {
	return (10.*(y-x));
}

double f2 (double x, double y, double z) {
	return (28.*x-y-x*z);
}

double f3 (double x, double y, double z) {
	return (x*y - 8./3.*z);
}

double derivativeX (double (*function)(double x, double y, double z), double x0, double y, double z) {
	return (function(x0 + der_eps, y, z) - function(x0 - der_eps, y, z))/(2.*der_eps);
}

double derivativeY (double (*function)(double x, double y, double z), double x, double y0, double z) {
	return (function(x, y0 + der_eps, z) - function(x, y0 - der_eps, z))/(2.*der_eps);
}

double derivativeZ (double (*function)(double x, double y, double z), double x, double y, double z0) {
	return (function(x, y, z0 + der_eps) - function(x, y, z0 - der_eps))/(2.*der_eps);
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

	double *a, *b, *x0;
	double x, y, z, hx, hy, hz;
	double rx, ry, rz;
	int n,m;
	int N = 3;
	
	scanf("%lf %lf %lf", &x, &y, &z);
		
	a=(double*)malloc(N*N*sizeof(double));
	b=(double*)malloc(N*sizeof(double));
	x0=(double*)malloc(N*sizeof(double));
	
	rx = x;
	ry = y;
	rz = z;
	
	x0[0] = 10000.;
	x0[1] = 10000.;
	x0[2] = 10000.;
	
	while(fabs(x0[0])>root_eps && fabs(x0[1])>root_eps && fabs(x0[2])>root_eps){	
	
	a[0]= derivativeX(f1, x, y, z);
	a[1]= derivativeY(f1, x, y, z);
	a[2]= derivativeZ(f1, x, y, z);
	a[3]= derivativeX(f2, x, y, z);
	a[4]= derivativeY(f2, x, y, z);
	a[5]= derivativeZ(f2, x, y, z);
	a[6]= derivativeX(f3, x, y, z);
	a[7]= derivativeY(f3, x, y, z);
	a[8]= derivativeZ(f3, x, y, z);	

	b[0] = f1(x, y, z);
	b[1] = f2(x, y, z);
	b[2] = f3(x, y, z);
	
	
	m=0;
	
	for(n=0;n<N;n++)	{
		gauss(n,m,a,N,b);
		m++;
	}



	roots(a,N,b,x0);
	
	for (n=1;n<=N;n++) {
		printf("h%d = %lf\n", n, x0[n-1]);
	}
	
		printf("x = %lf y = %lf z = %lf\n", x, y, z);

	rx = fabs(x - x0[0]);
	ry = fabs(y - x0[1]);
	rz = fabs(z - x0[2]);
	
	x = rx;
	y = ry;
	z = rz;
}

	printf("rx = %lf ry = %lf rz = %lf\n", rx, ry, rz);
	
	return 0;

}
