#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

int count(double x0, double eps);

int main(){ 
	double x0, eps; 
	int N;
	N = 0; 

scanf("%lf%lf", &x0, &eps); 

N = count(x0,eps); 

return 0; 
} 

int count(double x0, double eps){ 
	int N, k;
	double n, f, S;
	N = 1;
	k = 0;
	n = 2.;
	f = x0;
	S = x0;
 
while(fabs(S-sin(x0))>eps){ 
f*=((x0*x0)/((n)*(n+1))); 
k++; 
if(k%2!=0) 
	S-= f; 
else 
	S+= f;
//printf("%lf", S);
n+= 2; 
N++; 
} 
printf("%lf %d\n", S, N); 
}

