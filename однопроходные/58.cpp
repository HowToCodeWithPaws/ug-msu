1.58. Найдите количество четных элементов последовательности, 
для которых остаток от деления на пять ровно на единицу отличается от остатка
при делении на 7, а также значение последнего такого элемента.

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
		int count_all = 0, count = 0, n, in;		
		while (fscanf(f, "%d", &in) != 0) {
			if (((in % 2) == 0) && (abs((in % 5)-(in % 7)) == 1)){
				count++;
				n = in;
			} 
		}
		
		printf("There are %d suitable numbers and the last of them equals %d", count, n);
		}

	fclose(f);
}
