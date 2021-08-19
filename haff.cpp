#include<stdio.h>

int main (){
	FILE* inc;
	unsigned char s;
	int i, k;
	int mas [255];
	inc = fopen ("data.txt", "r");
	if (inc == NULL){
		printf ("error");
		return 0;
	}
		for (i=0; i<255; i++)
			mas[i] = 0;
	while (!feof(inc)){
		k = fscanf (inc, "%c", &s);
		mas[(int(s))]++;
		//printf("%c%d",s, mas[(int(s))]);
	}
		for (i=0;i<255;i++){
			if (mas[i]!=0)
				printf ("'%c'%d\n", (char)i, mas[i]);
				}
	return 0;			
}
