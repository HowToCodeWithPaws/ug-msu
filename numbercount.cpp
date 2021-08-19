#include<stdio.h>
#include<stdlib.h>

int main(){
	long long int in;
	int i, j, r;
	int q[10];
	int u[10];
		
	for(i=0; i<10; i++){
		q[i] = 0;
	}
	
	for(i=0; i<10; i++){
		u[i] = i;
	}
	
	scanf("%lld", &in);
	
	while(in>0){
		q[(int)in%10] = q[(int)in%10] + 1;
		in = in/10;
	}
	
	for(i=1; i<10; i++){
		for(j=1; j<10; j++){
			if(q[j]<q[j-1]){
				r = q[j];
				q[j] = q[j-1];
				q[j-1] = r;
				
				r = u[j];
				u[j] = u[j-1];
				u[j-1] = r;				
			}
		}
	}
	
	for(i=0; i<10; i++){
		printf("%d %d\n", u[i], q[i]);
	}
	
	return 0;
}
