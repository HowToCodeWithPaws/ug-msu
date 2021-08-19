#include <stdio.h>
#include <math.h>

const double der_eps = 0.001;
const double root_eps = 1e-15;

double my_f (double x) {
	return x*x + 2;
}

double derivative (double (*function)(double x), double x0) {
	return (function(x0 + der_eps) - function(x0 - der_eps))/(2*der_eps);
}

int main (){
	double x = 42;
	double x_prev = 0;
	int i = 0;
	
	while ((fabs(x - x_prev) > root_eps) && (i < 1000)) {
		x_prev = x;
		x -= my_f(x)/derivative(my_f, x);
		i++;
	}
	
	if (i < 1000) {
		printf("da answer is %.16g, in %d steps", x, i);
	} else {
		printf("i've got no roots, but my home was never on the ground _-_-");
	}
	return 0;
}

	
