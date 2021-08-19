#include<stdio.h>

int main (){
double E;
int n;
n = 0;
E = 1.;

while ((1. + E) != 1.) {
	E = E * (1./2.) ;
	n = n+1;
	printf("%25.18lf\n", E);
	};

printf("%d", n);
}
