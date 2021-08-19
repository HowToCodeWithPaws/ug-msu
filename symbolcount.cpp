#include<stdio.h>

int main (){
	FILE* fin;
	unsigned char str;
	int *nmb;
	int k, i;
	fin = fopen ("data.txt", "r");
	int mas [255];
//	int count = (FILE fin, *str, *nmb);

	if (fin == NULL){
		printf ("error");
		return 0;
	}
	
	for (i=0; i<255; i++)
		mas [i] = 0;
	
	
	while (!feof(fin)){
	k = fscanf( fin, "%c", &str);
	mas[(int)str]++;
	}
	for (i=0; i<255; i++)
		if (mas[i]!=0) 
			printf ("'%c'%d\n", (char)i, mas[i] );
		return 0;
	
}
