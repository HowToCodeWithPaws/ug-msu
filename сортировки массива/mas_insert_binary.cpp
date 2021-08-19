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

int main () {
	int N, i, in, j;

	scanf("%d", &N);
	int * mas = (int *) malloc (sizeof(int)*(N+1));
	
	for (i=0; i<N; i++) scanf ("%d", &mas[i]);
	scanf ("%d", &in);
		
	i = BinarySearch (mas, 0, N-1, in);
	for(j=N;j>i;j--) mas[j]= mas[j-1];
	mas[i] = in;
	
	for (i=0; i<=N; i++) printf ("%d ", mas[i]);	
	
	return 0;
}
