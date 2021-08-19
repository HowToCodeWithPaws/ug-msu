//массив структур "фамилия" не длиннее 20 букв + номер, сортировать по фамилии

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person {
	char lastname[20];
	int number;
};

int BinarySearch (struct person * mas, int start, int end, char* in) {
	int i = start, j = end;
	while (i != j) {
		if (strcmp(mas[(i+j)/2].lastname, in) > 0) {
			j = (i+j)/2;
		}
		else {
			i = (i+j)/2 + 1;
		}
	}
	if (strcmp(mas[i].lastname, in) > 0) return i;
	else return i+1;
}

int InsertSort (struct person * mas, int n) {
	int i, index, j, curnumber;
	char* cur;

	cur = (char*)malloc(20*sizeof(char));
	
	for (i=1; i<n; i++) {
		strcpy(cur, mas[i].lastname);
		curnumber = mas[i].number;
		
		index = BinarySearch (mas, 0, i-1, cur);
		
		for(j=i; j>index; j--) {
			strcpy(mas[j].lastname, mas[j-1].lastname);	
			mas[j].number = mas[j-1].number;
		}

		strcpy(mas[index].lastname, cur);
		mas[index].number = curnumber;
	}
	return 0;
}

int main () {
	int N, i;
	
	scanf("%d", &N);
		
	struct person * mas = (struct person*)malloc(N*sizeof(struct person));
	
	for (i=0; i<N; i++) {
		scanf ("%s %d", mas[i].lastname, &mas[i].number);	
	}
	
	InsertSort (mas, N);
	
	for (i=0; i<N; i++)	printf("%s %d\n", mas[i].lastname, mas[i].number);

	return 0;
}
