1.55. Найдите количество элементов последовательности делящихся на
пять и имеющих в записи более трех цифр, а также номер последнего такого
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
		int count_all = 0, count5 = 0, n, in;		
		while (fscanf(f, "%d", &in) != 0) {
			count_all++;
			if (((in % 5) == 0) && (in >= 100)){
				count5++;
				n = count_all;
			} 
		}
		
		printf("There are %d suitable numbers, the last of them has index %d in the array", count5, n);
		}

	fclose(f);
}
