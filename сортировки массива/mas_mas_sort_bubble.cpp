#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Word {
	char word[10];
};

int main(){
	int N, i, j;
	struct Word * mas;
	char * tmp;
	
	FILE* in;
	in = fopen("text.txt", "r");
	
	fscanf(in, "%d", &N);
	
	mas = (struct Word*)malloc(N*sizeof(struct Word));
	
	for (i=0; i<N; i++) {
		fscanf(in, "%s", mas[i].word);	
	}
	


	tmp = (char*)malloc(10*sizeof(char));
		for(i=0;i<N;i++) printf("%d %s\n",i, mas[i].word);	

	for(j=0; j<N-1; j++){
		for(i=0; i<N-1-j; i++){
			if(strcmp(mas[i].word, mas[i+1].word)>0){
				strcpy(tmp, mas[i+1].word);
				strcpy(mas[i+1].word, mas[i].word);
				strcpy(mas[i].word,tmp);
						
			}
		}
	}
	
		
	for(i=0;i<N;i++) printf("%d %s\n",i, mas[i].word);	
	
return 0;
}
