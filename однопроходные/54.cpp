1.54. Ќайдите количество элементов последовательности кратных трем,
значени€ которых меньше ста, а также пор€дковый номер первого такого
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
		int count_all = 0, count3 = 0, n, in;		
		while (fscanf(f, "%d", &in) != 0) {
			count_all++;
			if (((in % 3) == 0) && (in < 100)){
				count3++;
				if(count3 == 1) n = count_all;
			} 
		}
		
		printf("There are %d suitable numbers, the first of them has index %d in the array", count3, n);
		}

	fclose(f);
}
