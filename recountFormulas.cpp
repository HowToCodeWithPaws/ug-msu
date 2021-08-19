#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
int N;
double xn, yn, zn, x0, y0, z0;
double t;
double h;
FILE* outx;
FILE* outy;
FILE* outz;
t = 0;
x0 = 0;
y0 = 0;
z0 = 1;

outx = fopen("x.txt", "w");
outy = fopen("y.txt", "w");
outz = fopen("z.txt", "w");

scanf("%d%lf", &N, &h);


while(t<(double)N){
xn = x0*h + exp(t)*z0 + x0;
yn = z0*h +y0;
zn = -y0*h +z0;
fprintf(outx, "%lf %lf\n", t, xn);
fprintf(outy, "%lf %lf\n", t, yn);
fprintf(outz, "%lf %lf\n", t, zn);

printf("%lf %lf\n", t, xn);
printf("%lf %lf\n", t, yn);
printf("%lf %lf\n", t, zn);

x0 = xn;
y0 = yn;
z0 = zn;

t = t + h;
}

return 0;
}
