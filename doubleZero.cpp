#include<stdio.h>

int main (){
double E;
int n;
E = 1.;
n = 0 ;

while (E/2. != 0.) {
	E = E * (1./2.) ;
	n= n+1;
	};
printf("%e\n", E);
printf("%d", n);
}
