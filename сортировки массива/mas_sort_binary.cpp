#include <stdio.h>
#include <stdlib.h>

int BinarySearch (int * mas, int start, int end, int in) {
	int i = start, j = end;
	while (i != j) {
		if (mas[(i+j)/2] > in) {
			j = (i+j)/2;
		}
		else {
			i = (i+j)/2 + 1;
		}
	}
	if (mas[i] > in) return i;
	else return i+1;
}

int InsertSort (int * mas, int n) {
	int i, index, cur, j;
	
	for (i=1; i<n; i++) {
		cur = mas[i];
		index = BinarySearch (mas, 0, i-1, cur);
		for (j=i; j>index; j--) mas[j] = mas[j-1];
		mas[index] = cur;
	}
	return 0;
}

int main () {
	int N, i;
	
	scanf("%d", &N);
	int * mas = (int *) malloc (sizeof(int)*N);
	for (i=0; i<N; i++) scanf ("%d", &mas[i]);
			
	InsertSort (mas, N);	
	for (i=0; i<N; i++)	printf ("%d ", mas[i]);
	return 0;
}
