1.52. Найдите количество элементов последовательности равных трем, 
количество равных пяти и количество равных семи.

#include<stdio.h>

int main(){
	FILE * f;
	f = fopen("input.txt", "r");
	if (f == NULL) { 
		printf("Fatal error, what's wrong with the file?\n");
		return -1;
	} 
	else {
		int count3 = 0, count5 = 0, count7 = 0, in;
		
		while (fscanf(f, "%d", &in) != 0) {
			if (in == 3) count3++;
			if (in == 5) count5++;
			if (in == 7) count7++;
		}
		
		printf("There are %d numbers equal to 3, %d numbers equal to 5, %d numbers equal to 7",count3, count5, count7);
		}

	fclose(f);
}
