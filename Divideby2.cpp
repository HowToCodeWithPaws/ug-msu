#include<stdio.h>

const double x_eps = 1e-15;
const double y_eps = 0.001;

double f(double x) {
	return x*x + 2;
}

int main (){
	double a = 0;
	double b = 10;
	double c = (a+b)/2;
	int i = 0;
	
	while(i < 1000) {
		c = (a+b)/2;
		if (f(c - x_eps)*f(c + x_eps) < 0) {
			break;
		}
		
		if (f(c)*f(a) < 0) {
			b = c;
		} else {
			a = c;
		}
		
		i++;
	}
	
	if (i == 1000) {
		printf("roots? nah");
	} else {
		printf("hey, i've found ur root %.16g. in %d steps", c, i);
	}
	
}
