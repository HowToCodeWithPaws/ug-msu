1.50. Ќайдите количество четных элементов последовательности, 
значени€ которых больше дес€ти и не превосход€т ста, а также их процент (с
точностью до дес€тых долей) от общего числа элементов.

#include<stdio.h>

int main(){
	FILE * f;
	f = fopen("input.txt", "r");
	if (f == NULL) { 
		printf("Fatal error, what's wrong with the file?\n");
		return -1;
	} else {
		int count1 = 0, count2 = 0, in;
		
		while (fscanf(f, "%d", &in) != 0) {
			count2++;
			if (((in % 2) == 0) && (in > 10) && (in <= 100)) {
				count1++;
			}
		}
		
		printf("There are %d suitable numbers and they make %.2f percent of the total amount of numbers", count1, (double) 100*count1/count2);
	}

	fclose(f);
}
