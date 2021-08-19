#include<stdio.h>

int main (){
double E;
int n;
E = 1.;
n = 0 ;

for (E=1.; E != 0.; E = E*1./2.) {
	n= n+1;
	printf("%e\n", E);
	};
//printf("%25.18lf", E);
printf("%d", n);
}
