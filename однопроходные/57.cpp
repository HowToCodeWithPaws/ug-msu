1.57. Ќайдите количество элементов последовательности, дл€ которых
остаток от делени€ на 3 равен остатку от делени€ на 5, а также значение
последнего такого элемента.

#include<stdio.h>

int main(){
	FILE * f;
	f = fopen("input.txt", "r");
	if (f == NULL) { 
		printf("Fatal error, what's wrong with the file?\n");
		return -1;
	} 
	else {
		int count = 0, n, in;		
		while (fscanf(f, "%d", &in) != 0) {
			if ((in % 3) == (in % 5)){
				count++;
				n = in;
			} 
		}
		
		printf("There are %d suitable numbers and the last of them equals %d", count, n);
		}

	fclose(f);
}
