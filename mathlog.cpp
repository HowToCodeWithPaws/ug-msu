#include<stdio.h>
#include<stdlib.h>
int a, b;

int mlog_not(int);
int mlog_and(int, int);
int mlog_or(int, int);
int mlog_imp(int, int);
int mlog_xor(int, int);
int mlog_eqw(int, int);

int main()
{
 	int i, j, n, x, y, z, f, flag, Flag;
 	
 	struct array
	{
		int X;
		int Y;
		int Z;
		int F;
	};

	struct array t[8];
	
	for(x = 0; x<=1; x++)
	{
		for(y = 0; y<=1; y++)
		{
			for(z = 0; z<=1; z++)
			{
				t[z+2*y + 4*x].X = x;
				t[z+2*y + 4*x].Y = y;
				t[z+2*y + 4*x].Z = z;
				t[z+2*y + 4*x].F = mlog_or(mlog_eqw(x, z), mlog_imp(x, mlog_and(y, z)));
			}
		}	
	}
	
	for(i=0; i<8; i++)
	printf("%d) %d %d %d = %d\n", i+1, t[i].X, t[i].Y, t[i].Z, t[i].F );
	
	printf("Write the number of lines\n");
	
	scanf ("%d", &n);	
	struct array * crit = (struct array *) malloc (sizeof(struct array) * n);
	
	printf("Wtite 'x', 'y', 'z', 'F'\nIf there's a '-' in the table, write '-1' instead, please\n");

	for (i=0; i<n; i++) 
	{
		scanf ("%d %d %d %d", &crit[i].X, &crit[i].Y, &crit[i].Z, &crit[i].F);
	}
	
//перебор			
		
	//xyz
	Flag = 1;
	for (i=0; i<n; i++) 
	{
		flag = 0;
		for (j=0; j<8; j++)
			if ((crit[i].X == -1 || crit[i].X == t[j].X) && (crit[i].Y == -1 || crit[i].Y == t[j].Y) && (crit[i].Z == -1 || crit[i].Z == t[j].Z) && crit[i].F == t[j].F)
			{
				flag = 1;
				break;
			}
					
		if (flag == 0) 
		{
			Flag = 0;
			break;
		}	 	
	}
	if (Flag == 1) 
	{
		printf ("xyz");
		return 0;
	}
		
	//xzy
	Flag = 1;
	for (i=0; i<n; i++) 
	{
		flag = 0;
		for (j=0; j<8; j++)
			if ((crit[i].X == -1 || crit[i].X == t[j].X) && (crit[i].Y == -1 || crit[i].Y == t[j].Z) && (crit[i].Z == -1 || crit[i].Z == t[j].Y) && crit[i].F == t[j].F)
			{
				flag = 1;
				break;
		 	}		
		if (flag == 0) 
		{
			Flag = 0;
			break;
		}	 	
	}
	if (Flag == 1) 
	{
		printf ("xzy");
		return 0;
	}
		
	//yxz
	Flag = 1;
	for (i=0; i<n; i++) 
	{
		flag = 0;
		for (j=0; j<8; j++)
			if ((crit[i].X == -1 || crit[i].X == t[j].Y) && (crit[i].Y == -1 || crit[i].Y == t[j].X) && (crit[i].Z == -1 || crit[i].Z == t[j].Z) && crit[i].F == t[j].F)
		 	{
		 		flag = 1;
				break;
			}		
		if (flag == 0) 
		{
			Flag = 0;
			break;
		}	 	
	}
	if (Flag == 1) 
	{
		printf ("yxz");
		return 0;
	}
		
	//yzx
	Flag = 1;
	for (i=0; i<n; i++) 
	{
		flag = 0;
		for (j=0; j<8; j++)
			if ((crit[i].X == -1 || crit[i].X == t[j].Y) && (crit[i].Y == -1 || crit[i].Y == t[j].Z) && (crit[i].Z == -1 || crit[i].Z == t[j].X) && crit[i].F == t[j].F)
			{
		 		flag = 1;
		 		break;
			}		
		if (flag == 0) 
		{
			Flag = 0;
			break;
		}	 	
	}
	if (Flag == 1) 
	{
		printf ("yzx");
		return 0;
	}
		
	//zxy
	Flag = 1;
	for (i=0; i<n; i++) 
	{
		flag = 0;
		for (j=0; j<8; j++)
			if ((crit[i].X == -1 || crit[i].X == t[j].Z) && (crit[i].Y == -1 || crit[i].Y == t[j].X) && (crit[i].Z == -1 || crit[i].Z == t[j].Y) && crit[i].F == t[j].F)
			{
		 		flag = 1;
		 		break;
			}		
		if (flag == 0) 
		{
			Flag = 0;
			break;
		}	 	
	}
	if (Flag == 1) 
	{
		printf ("zxy");
		return 0;
	}
		
	//zyx
	Flag = 1;
	for (i=0; i<n; i++) 
	{
		flag = 0;
		for (j=0; j<8; j++)
			if ((crit[i].X == -1 || crit[i].X == t[j].Z) && (crit[i].Y == -1 || crit[i].Y == t[j].Y) && (crit[i].Z == -1 || crit[i].Z == t[j].X) && crit[i].F == t[j].F)
		 	{
		 		flag = 1;
		 		break;
		 	}		
		if (flag == 0) 
		{
			Flag = 0;
			break;
		}	 	
	if (Flag == 1) 
	{
		printf ("zyx");
		return 0;
	}
		
	}
}


int mlog_not(int a)
{
	if (a == 0) return 1;
	else return 0;
}

int mlog_and(int a, int b)
{
	if (a == 1 && b == 1) return 1;
	else return 0;
}

int mlog_or(int a, int b)
{
	if (a == 0 && b == 0) return 0;
	else return 1;
}

int mlog_imp(int a, int b)
{
	if (a == 1 && b == 0) return 0;
	else return 1;
}

int mlog_xor(int a, int b)
{
	if (a == 0 && b == 0) return 0;
	if (a == 1 && b == 1) return 0;
	if (a == 1 && b == 0) return 1;
	if (a == 0 && b == 1) return 1;
}

int mlog_eqw(int a, int b)
{
	if (a == 0 && b == 0) return 1;
	if (a == 1 && b == 1) return 1;
	if (a == 1 && b == 0) return 0;
	if (a == 0 && b == 1) return 0;
}
