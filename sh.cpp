#include <stdio.h>

int main () {
	FILE* inc;
	char s;
	int k;
	inc = fopen ("data.txt", "r");
	if (inc == NULL) {
		printf("error");
		return 0;
	}

	while (1) {
	 	k=fscanf(inc, "%c", &s);
	 		if (k != 1) break;
		if (s == 'a') printf("e");
	 	if (s == 'b') printf("f");
	 	if (s == 'c') printf("g");
	 	if (s == 'd') printf("h");
	}
	return 0;
}
