1.59. Ќайдите количество нечетных элементов последовательности, дл€
которых остаток от делени€ на п€ть не более чем на два отличаетс€ от
остатка при делении на 7, а также номер последнего такого элемента

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
			count_all++;
			if (((in % 2) > 0) && (abs((in % 5)-(in % 7)) <= 2)){
				count++;
				n = count_all;
			} 
		}
		
		printf("There are %d suitable numbers, the last of them has index %d in the array", count, n);
		}

	fclose(f);
}
