#include<stdio.h>
#include<math.h>

double x;
double h;
	
double f(double x){
	return exp(x)*(sin(x) + x*(cos(x) + sin(x)));
}

double g(double x, double y, double h){
	return y + f(x)*h;
}

double y(double x){
	return x*sin(x)*exp(x);
}
	
	int main(){
	int i;
	double a, b;
	int N;
	
	scanf("%lf%lf%d", &a, &b, &N);
	
	h = (b - a)/(double)N;
	
	for (i=1; i<= N; i++)
	printf("%lf %lf %lf\n", x+(double)i*h, g(x +(double)(i-1)*h, y(x+(double)i*h), h), y(x+(double)i*h));
}
