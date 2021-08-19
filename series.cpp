#include<stdio.h>
#include<math.h>

int main(){
	int i;
	double s1, s2, sN, d1, d2;
	s1 = 0.0;
	s2 = 0.0;
	sN = (double)16.695311365859851815399118939540451;
 
	for (i = 1; i <= 10000000; i++)
	s1+= 1./(double)i;
	
	for (i = 10000000; i > 0; i--)
	s2+= 1./(double)i;
	
	d1 = sN - s1;
	d2 = sN - s2;
	
	printf("%.15lf\n", sN); 
	printf("%.15lf %.15lf\n%.15lf %.15lf\n", s1, d1, s2, d2);
	
	if (fabs(d1)>=fabs(d2))
		printf("2");
	
	else
		printf("1");	
}
