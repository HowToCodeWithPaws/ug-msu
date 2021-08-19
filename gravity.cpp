#include<stdio.h>
#include<math.h>
#include<stdlib.h>



double dt, M, G;
double x;
double y;
double v;
double d;


double dist(double x, double y){
	return fabs(sqrt(x*x + y*y));
	}

double speed(double v, double x, double d){
	return v - dt*G*M*x/(d*d*d);
}

double coord(double x, double v){
	return x + dt*v;
}

int main (){
	FILE* out;
	int k, i;
	double T;
	double *R, *x, *y, *v1, *v2;
	
	out = fopen ("data.txt", "w");

	printf("Input: k, T, M, G\n");
	scanf(" %d%lf%lf%lf", &k, &T, &M, &G);
	printf("%d %lf %lf %lf\n", k, T, M, G);
	
	if (k == 0)
		printf("error");
	else 
		dt = T/(double)k;

	printf ("%lf\n", dt);


	R = (double*)malloc(k*sizeof(double));
	x = (double*)malloc(k*sizeof(double));
	y = (double*)malloc(k*sizeof(double));	
	v1 = (double*)malloc(k*sizeof(double));	
	v2 = (double*)malloc(k*sizeof(double));
	
		if (R == NULL)
			printf("error");
		if (x == NULL)
			printf("error");
		if (y == NULL)
			printf("error");
		if (v1 == NULL)
			printf("error");
		if (v2 == NULL)
			printf("error");
	
	printf("Input: x[0], y[0], v1[0], v2[0]\n");
	scanf(" %lf%lf%lf%lf", &x[0], &y[0], &v1[0], &v2[0]);
	printf("%lf %lf %lf %lf\n", x[0], y[0], v1[0], v2[0]);

	for(i=0; i<k; i++){
	
		R[i] = dist(x[i], y[i]);
		
		v1[i+1] = speed (v1[i], x[i], R[i]);
		x[i+1] = coord (x[i], v1[i]);
		
		v2[i+1] = speed (v2[i], y[i], R[i]);
		y[i+1] = coord (y[i], v2[i]);
	}
	
	for (i=0; i<k; i++){
		
		fprintf(out, "%lf %lf\n", x[i], y[i]);
		printf("%lf %lf\n", x[i], y[i]);

	}
}
