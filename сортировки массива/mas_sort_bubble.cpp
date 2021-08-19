#include<stdio.h>
#include<stdlib.h>

int main(){
	int N, i, j, tmp;
	int * mas;
	
	scanf("%d", &N);
	mas = (int*)malloc(N*sizeof(int));
	
	for(i=0;i<N;i++) scanf("%d", &mas[i]);

	for(j=0; j<N-1; j++){
		for(i=0; i<N-1-j; i++){
			if(mas[i]>mas[i+1]){
				tmp = mas[i+1];
				mas[i+1] = mas[i];
				mas[i] = tmp;
			}
		}
	}
	
	for(i=0;i<N;i++) printf("%d ", mas[i]);	
	
return 0;
}
