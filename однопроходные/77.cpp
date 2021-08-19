1.77. ѕусть последовательность €вл€етс€ неубывающей. ќпределите количество элементов, 
которые по€вл€ютс€ в этой последовательности более
n раз. «начение n вводитс€ с клавиатуры.

#include<stdio.h>

int main(){
	FILE * f;
	f = fopen("input.txt", "r");
	if (f == NULL) { 
		printf("Fatal error, what's wrong with the file?\n");
		return -1;
	} else {
		int count = 0, in, rem, k = 0, n, flag1 = -1, flag2 = -1;

		scanf("%d", &n);	
		
		while (fscanf(f, "%d", &in) != 0) {
			if(flag2 == -1){
				rem = in;
				flag2 = 1;
			}	
	
			if(in == rem){	
				k++;
				if((k > n) && (flag1 == -1)){
					count++;
					flag1 = 1;
				}
			}
			else{
				rem = in;
				k = 1;
				flag1 = -1;	
			}		
		}
		printf("The number of symbols that appear more than %d times is %d", n, count);
	}

	fclose(f);
}
