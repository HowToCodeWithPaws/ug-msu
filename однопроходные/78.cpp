1.78. Определите, сколько раз во входной последовательности встречается
подпоследовательность 1, 2, 3, . . . , 100.

#include<stdio.h>

int main(){
	FILE * f;
	f = fopen("input.txt", "r");
	if (f == NULL) { 
		printf("Fatal error, what's wrong with the file?\n");
		return -1;
	} else {
		int count = 0, k=1, in, n = -1;
		
		while (fscanf(f, "%d", &in) != 0) {
			k = 1;
			while(in == k){
				fscanf(f, "%d", &in);
				k++;
				if(k == 10){
					count++;
					k = 1;
					break;
				}
				
			}

		}
		
			
		printf("The subarray 1, 2, 3...10 appears in the main array %d times", count);
	}

	fclose(f);
}
