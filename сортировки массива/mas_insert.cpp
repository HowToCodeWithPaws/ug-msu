#include<stdio.h>
#include<stdlib.h>

int main(){
	int N, i, j, in, tmp;
	int * mas;
	
	scanf("%d", &N);
	mas = (int*)malloc((N+1)*sizeof(int));
	
	for(i=0;i<N;i++) {
		scanf("%d", &mas[i]);	
	}
	
	scanf("%d", &in);
	
	for(i=0; i<N; i++){
		if(in<mas[i]){
			for(j=N;j>i;j--) mas[j]= mas[j-1];
			mas[i] = in;
			break;
		}
	}
	
	for(i=0;i<(N+1);i++) printf("%d ", mas[i]);	
	
return 0;
}
