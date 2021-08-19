1.67. –аспечатайте значени€ и пор€дковые номера трех элементов последовательности, 
имеющих наибольшие по модулю значени€.

#include<stdio.h>
#include<math.h>

int main(){
	FILE * f;
	f = fopen("input.txt", "r");
	if (f == NULL) { 
		printf("Fatal error, what's wrong with the file?\n");
		return -1;
	} 
	else {
		int count_all = 0, m1, m2, m3, n1, n2, n3, in, flag1 = -1, flag2 = -1, flag3 = -1;	
		while (fscanf(f, "%d", &in) != 0) {
			count_all++;
			if(flag1 == -1){
				m1 = in;
				n1 = count_all;
				flag1 = 1;
			}	
			else{
				if((flag2 == -1) && (in != m1)){
					m2 = in;
					n2 = count_all;
					flag2 = 1;
				}
				else{
					if((flag3 == -1) && (in != m1) && (in != m2)){
					m3 = in;
					n3 = count_all;
					flag3 = 1;
					}
					else {
						if(fabs(m1) < fabs(m2)){
							if(fabs(m3) < fabs(m1)){
								if((fabs(in) > fabs(m3)) && (in != m1) && (in != m2)){
									m3 = in;
									n3 = count_all;
								}
							}
							else {
								if((fabs(in) > fabs(m1)) && (in != m2) && (in != m3)){
									m1 = in;
									n1 = count_all;
								}	
							}
						}
						else {
							if(fabs(m3) < fabs(m2)){
								if((fabs(in) > fabs(m3)) && (in != m1) && (in != m2)){
									m3 = in;
									n3 = count_all;
								}
							}
							else {
								if((fabs(in) > fabs(m2)) && (in != m1) && (in != m3)){
									m2 = in;
									n2 = count_all;
								}	
							}
						}
					}
				}
			}
		}
		
		printf("Three numbers with the biggest absolute value are %d (with the index %d), %d (%d) and %d (%d)", m1, n1, m2, n2, m3, n3);
		}

	fclose(f);
}
