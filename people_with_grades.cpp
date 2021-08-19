#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person {
	char lastname[20];
	int number;
	int score;
};

int BinarySearchName (struct person * mas, int start, int end, char* in) {
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

int BinarySearchNumber (struct person * mas, int start, int end, int in) {
	int i = start, j = end;
	while (i != j) {
		if (mas[(i+j)/2].number > in) {
			j = (i+j)/2;
		}
		else {
			i = (i+j)/2 + 1;
		}
	}
	if (mas[i].number > in) return i;
	else return i+1;
}

int BinarySearchScore (struct person * mas, int start, int end, int in) {
	int i = start, j = end;
	while (i != j) {
		if (mas[(i+j)/2].score > in) {
			j = (i+j)/2;
		}
		else {
			i = (i+j)/2 + 1;
		}
	}
	if (mas[i].score > in) return i;
	else return i+1;
}

int InsertSortNumber (struct person * mas, int n) {
	int i, index, curnumber, curscore, j;
	char* curname;
	
	curname = (char*)malloc(20*sizeof(char));
	
	for (i=1; i<n; i++) {
		strcpy(curname, mas[i].lastname);
		curnumber = mas[i].number;
		curscore = mas[i].score;
		
		index = BinarySearchNumber (mas, 0, i-1, curnumber);
		
		for (j=i; j>index; j--){
			strcpy(mas[j].lastname, mas[j-1].lastname);	
			mas[j].number = mas[j-1].number;
			mas[j].score = mas[j-1].score;
		} 
		
		strcpy(mas[index].lastname, curname);
		mas[index].number = curnumber;
		mas[index].score = curscore;
	}
	return 0;
}

int InsertSortScore (struct person * mas, int n) {
	int i, index, curnumber, curscore, j;
	char* curname;
	
	curname = (char*)malloc(20*sizeof(char));
	
	for (i=1; i<n; i++) {
		strcpy(curname, mas[i].lastname);
		curnumber = mas[i].number;
		curscore = mas[i].score;
		
		index = BinarySearchScore (mas, 0, i-1, curscore);
		
		for (j=i; j>index; j--){
			strcpy(mas[j].lastname, mas[j-1].lastname);	
			mas[j].number = mas[j-1].number;
			mas[j].score = mas[j-1].score;
		} 
		
		strcpy(mas[index].lastname, curname);
		mas[index].number = curnumber;
		mas[index].score = curscore;
	}
	return 0;
}

int InsertSortName (struct person * mas, int n) {
	int i, index, j, curnumber, curscore;
	char* curname;

	curname = (char*)malloc(20*sizeof(char));
	
	for (i=1; i<n; i++) {
		strcpy(curname, mas[i].lastname);
		curnumber = mas[i].number;
		curscore = mas[i].score;
		
		index = BinarySearchName (mas, 0, i-1, curname);
		
		for(j=i; j>index; j--) {
			strcpy(mas[j].lastname, mas[j-1].lastname);	
			mas[j].number = mas[j-1].number;
			mas[j].score = mas[j-1].score;
		}

		strcpy(mas[index].lastname, curname);
		mas[index].number = curnumber;
		mas[index].score = curscore;
	}
	return 0;
}


int main () {
	int N, i, key;
	
	FILE* in;
	in = fopen("people.txt", "r");
	
	fscanf(in, "%d", &N);
		
	struct person * mas = (struct person*)malloc(N*sizeof(struct person));
	
	for (i=0; i<N; i++) {
		fscanf (in, "%s %d %d", mas[i].lastname, &mas[i].number, &mas[i].score);	
	}
	
	printf("If you want to sort the array by name print 1, if you want to sort the array by ID print 2, if you want to sort the array by score print 3\n");
	scanf("%d", &key);

	
	if(key==1)InsertSortName (mas, N);
	if(key==2)InsertSortNumber (mas, N);
	if(key==3)InsertSortScore (mas, N);
	
	for (i=0; i<N; i++)	printf("%s %d %d\n", mas[i].lastname, mas[i].number, mas[i].score);

	return 0;
}
