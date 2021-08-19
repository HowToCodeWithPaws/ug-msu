#include<stdio.h>
#include<math.h>

int main(){
	double a, b, c;
	double d, x1, x2;
	
	scanf("%lf%lf%lf", &a, &b, &c);
	b = b/a;
	c = c/a;
	a = 1.0;
	d = b*b - 4.0*a*c;
	printf("%lf\n", d);
	if (d<0.) return 0;
	
	if(b>=0.) {
		x1 = ((-b - sqrt(d))/(2.*a));
		}
	else {
		x1 = ((-b + sqrt(d)))/(2.*a);
}
		x2 = c/(a*x1);
	printf("%lf %lf\n", x1, x2);
	printf("%lf %lf\n", (a*x1*x1+b*x1+c), (a*x2*x2+b*x2+c));
}

