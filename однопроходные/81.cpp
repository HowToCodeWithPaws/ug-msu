1.81. Определите длину постоянного участка с наибольшей суммой элементов.

#include<stdio.h>

int main(){
	FILE * f;
	f = fopen("input.txt", "r");
	if (f == NULL) { 
		printf("Fatal error, what's wrong with the file?\n");
		return -1;
	} else {
		int in, rem, kprev, remprev, k = 0, flag1 = -1, flag2 = -1;
		
		while (fscanf(f, "%d", &in) != 0) {
		
			if(flag1 == -1){
				rem = in;
				flag1 = 1;
			}	
			
			if(in == rem){	
				k++;
			}
			
			else{
				if(flag2 == -1){
				remprev = rem;
				kprev = k;
				flag2 = 1;
			}
				if(k*rem > kprev*remprev) {
					remprev = rem;
					kprev = k;			
				}
				k = 1;
				rem = in;
			}		
			

		}
		
		if(flag2 == -1){
			remprev = rem;
			kprev = k;
			flag2 = 1;
		}
		
		if(k*rem > kprev*remprev) {
					remprev = rem;
					kprev = k;			
				}
			
		printf("The length of the constant subarray with the biggest sum is %d", kprev);
	}

	fclose(f);
}
