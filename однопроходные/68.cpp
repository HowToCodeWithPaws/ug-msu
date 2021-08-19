1.68. Среди элементов последовательности найдите такую пару, что их
порядковые номера отличаются не менее, чем на три, а их сумма среди
подобных пар имеет максимальное значение


#include<stdio.h>

int main(){
	FILE * f;
	f = fopen("input.txt", "r");
	if (f == NULL) { 
		printf("Fatal error, what's wrong with the file?\n");
		return -1;
	} 
	else {
		int a[3], amax, smax, k, in, first, second;	
		
		for(k=0; k<3; k++){
			fscanf(f, "%d", &a[k]);
		}
		
		amax = a[0];
		smax = a[0];
		
		while (fscanf(f, "%d", &in) != 0) {
			if(in + a[0] > smax) {
				smax = in + a[0];
				first = a[0];
				second = in;	
			}
			if(in + amax > smax){
				smax = in + amax;
				first = amax;
				second = in;	
			} 
			
			if(a[0] > amax) amax = a[0];
			
			for(k=0; k<2; k++){
				a[k] = a[k+1];
			}
			
			a[2] = in;
		}
					
		printf("The suitable pair with the biggest sum is %d and %d", first, second);
		}

	fclose(f);
}
