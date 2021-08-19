//контроль последнего элемента 1)произведение различных наибольших элементов последовательности, 2) кратность 21, если нет таких - равное нулю

#include<stdio.h>

int main(){
	int R, contr, max21, max3, max7, maxr, in, N, i;
	max21 = -1;
	max3 = -1;
	max7 = -1;
	maxr = -1;
	
	scanf("%d", &N);

	for(i=0; i<N; i++){
		scanf("%d", &in);
		
		if(in%3 == 0){
			if(in%7 != 0){
				if(in>max3)  max3 = in;
			}
			else {
				if(in>max21) max21 = in;
			}
		} 
		else{
			if(in%7 != 0){
				if(in>maxr) maxr = in;
			}
			else{
				if(in>max7) max7 = in;
			}
		}
	}
		
	if(max21 == -1){
		if(max3 == -1) contr = 0;
		else {
			if(max7 == -1) contr = 0;
			else contr = max3*max7;
		}
	}
	else {
		if((max3 > max7) && (max3 > maxr)) contr = max21*max3;
		if((max7 > max3) && (max7 > maxr)) contr = max21*max7;
		if((maxr > max7) && (maxr > max3)) contr = max21*maxr;
	}

	scanf("%d", &R);

	if(R == contr) printf("right");
	else printf("wrong");

	return 0;
}
