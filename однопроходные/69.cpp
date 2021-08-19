1.69. Определите величину наибольшего отклонения элементов последовательности от их 
среднего арифметического.

#include<stdio.h>
#include<math.h>

int main(){
	FILE * f;
	f = fopen("input.txt", "r");
	if (f == NULL) { 
		printf("Fatal error, what's wrong with the file?\n");
		return -1;
	} 
	else {
		int count_all = 0, s = 0, max, min, in, flag1 = -1, flag2 = -1;	
		double av, ans, d1, d2;
			
		while (fscanf(f, "%d", &in) != 0) {
			
			count_all++;
			s = s + in;
			
			if (flag1 == -1){
				min = in;
				flag1 = 1;
				}
			else {
				if(in < min) min = in;
				}
				
			if (flag2 == -1){
				max = in;
				flag2 = 1;
				}
			else {
				if(in > max) max = in;
				}
			}
			
		av = (double)s/(double)count_all;
		d1 = fabs((double)min - av);
		d2 = fabs((double)max - av);
		
		if(d1<d2) ans = d2;
		else ans = d1;
		
		printf("The biggest difference from the average is %lf", ans);
		}

	fclose(f);
}
