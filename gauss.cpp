#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
	FILE*f;
	f=fopen("gauss.txt","r");
	double *a, *b, *x;
	int n,m;
	int N;
	
	fscanf(f, "%d", &N);
	
	a=(double*)malloc(N*N*sizeof(double));
	b=(double*)malloc(N*sizeof(double));
	x=(double*)malloc(N*sizeof(double));
	
	for(n=0;n<N;n++){
		for(m=0;m<N;m++)
			fscanf(f, "%lf", &a[m+n*N]);
		fscanf(f, "%lf", &b[n]);
	}
	
	m=0;
	
	for(n=0;n<N;n++)	{
		gauss(n,m,a,N,b);
		m++;
	}

	for(n=0;n<N;n++)	{
		for(m=0;m<N;m++)
			printf("%lf ", a[m+n*N]);
		printf("%lf\n", b[n]);
	}

	roots(a,N,b,x);
	
	for(n=1;n<=N;n++)	{
		printf("x%d = %lf\n", n, x[n-1]);
	}
	return 0;
}