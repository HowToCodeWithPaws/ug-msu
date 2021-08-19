//найти наименьшее четное произведение чисел, расстояние между которыми не менее 6

#include<stdio.h>
#include<limits.h>

int main(){
	
	int mino = INT_MAX, mine = INT_MAX, in, N, i, j, ans = INT_MAX;
	int a[6];
	
	scanf("%d", &N);
	
	for(i=0;i<6;i++) {
		scanf("%d", &a[i]);
	//	printf("%d\n", a[i]);
	}
	
	for(j=6; j<N; j++){
		scanf("%d", &in);
		
		if(((a[0]*in)%2==0) && (a[0]*in<ans)) ans = in*a[0];
		if(((mino*in)%2==0) && (mino*in<ans)) ans = in*mino;
		if(((mine*in)%2==0) && (mine*in<ans)) ans = in*mine;
		
		if(a[0]%2==0 && a[0]<mine) mine = a[0];
		if(a[0]%2>0 && a[0]<mino) mino = a[0];
		
		for(i=0;i<5;i++) a[i] = a[i+1];
		a[5] = in;
	}
	
	if(ans == INT_MAX) printf("error");
	else printf("%d", ans);

	return 0;
}
