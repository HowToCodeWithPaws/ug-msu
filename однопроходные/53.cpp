1.53. Ќайдите количество нечетных элементов последовательности, 
значени€ которых больше нул€, а также пор€дковый номер последнего такого
элемента.

#include<stdio.h>

int main(){
	FILE * f;
	f = fopen("input.txt", "r");
	if (f == NULL) { 
		printf("Fatal error, what's wrong with the file?\n");
		return -1;
	} 
	else {
		int count_all = 0, countO = 0, n, in;		
		while (fscanf(f, "%d", &in) != 0) {
			count_all++;
			if (((in % 2) > 0) && (in > 0)){
				countO++;
				n = count_all;
			} 
		}
		
		printf("There are %d odd numbers, the last of them has index %d in the array", countO, n);
		}

	fclose(f);
}
