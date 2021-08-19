#include<stdio.h>
#include<stdlib.h>

int main(){
	long long int in;
	long long int rem;
	int i, p, j, r, min, k, flag;
	int q[10];
	int u[10];
	
	p = 0;
	k = 10;
		
	for(i=0; i<10; i++){
		q[i] = 0;
	}
	for(i=0; i<10; i++){
		u[i] = 0;
	}
	
	scanf("%lld", &in);
	
	rem = in;
	
	while(in>0){
		q[(int)in%10] = q[(int)in%10] + 1;
		in = in/10;
		p++;
	}
	
	min = p;
	
	in = rem;
	
	if(q[0]!=0){
		printf("The rarest divider, which you actually shouldn't divide by, is 0"); 
		return 0;
		}
	else{	
		for(i=2; i<10; i++){
			if(q[i]!=0){
				while(in%i == 0){
				 u[i]++;
				 in = in/i;	
				} 
				in = rem;
			}
			else u[i]=-1;
		}

		for(i=2; i<10; i++){
			if(u[i]>0 && u[i]<=min){
				if(u[i]<min){
				min = u[i];
				k = i;
				}
				else {
					if(i<=k){
						min = u[i];
						k = i;	
					}
					else break;
				}
			}

	}
	
	
		if(k!=10){ 
		printf("The rarest divider is %d, it occurs only %d time(s)", k, min);}
		else printf("The only divider, also an infinite and the rarest one, is 1");
		
}
	return 0;
}
