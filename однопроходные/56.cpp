1.56. Найдите количество элементов последовательности заканчивающихся нулем,
 значения которых меньше тысячи, а также номер первого такого
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
		int count_all = 0, count0 = 0, n, in;		
		while (fscanf(f, "%d", &in) != 0) {
			count_all++;
			if (((in % 10) == 0) && (in < 1000)){
				count0++;
			if(count0 == 1) n = count_all;
			} 
		}
		
		printf("There are %d suitable numbers, the first of them has index %d in the array", count0, n);
		}

	fclose(f);
}
