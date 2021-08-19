#include<stdio.h>

int main(){

	int N, a, b, max = -1, i, d, sum = 0;
			
	scanf("%d", &N);
	
	for(i=0; i<N, i++){
		scanf("%d %d", &a, &b);
		
		if(a>=b){
			sum = sum + a;
			if((max < b) && (b%3 > 0)) {
				max = b;
				d = a - b;	
			}	
		}
		else{
			sum = sum + b;	
			if((max < a) && (a%3 > 0)) {
				max = a;
				d = b - a;	
			}	
		} 
			
	}
	
	if(sum%3 == 0) {
		if(max != -1){
			sum = sum - d;
		}
		else printf("error");
	}
	
	printf("%d", sum);


return 0;
}
