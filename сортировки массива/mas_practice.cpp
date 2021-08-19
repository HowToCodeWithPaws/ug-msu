#include<stdio.h>
#include<stdlib.h>

int init(int * m, int N, int i){
	m[i] = i;
}

int main(){
	int N, i;
	int * mas;
	
	scanf("%d", &N);
	mas = (int*)malloc(N*sizeof(int));
	
	for(i=0;i<N;i++) {
		mas[i] = init(&mas[0], N, i);
		printf("%d", mas[i]);
	}
	return 0;
}
