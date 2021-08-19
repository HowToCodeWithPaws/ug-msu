1.66. Определите номер первого и последнего минимального элемента последовательности

#include<stdio.h>

int main(){
	FILE * f;
	f = fopen("input.txt", "r");
	if (f == NULL) { 
		printf("Fatal error, what's wrong with the file?\n");
		return -1;
	} 
	else {
		int count_all = 0, first = 0, last = 0, in, min, flag = -1;	
		while (fscanf(f, "%d", &in) != 0) {
			count_all++;
			if (flag == -1)	{
				min = in;
				flag = 1;
				first = count_all;
				}
			else {
				if(in < min) {
					min = in;
					first = count_all;
					last = count_all;
				}
				else { 
					if(in == min){
						last = count_all;
					}
				}
			}	
		}
		
		if(last == 0) last=first;
		
		printf("The smallest number first appears with the index %d and last appears with the index %d", first, last);
		}

	fclose(f);
}
