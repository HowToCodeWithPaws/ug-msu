#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int rows, int cols, int row, int rem, double* left, double* right)
{
	double temp;
	int j;
	
	for(j = 0; j < cols; j++)	
	{
		temp = left[row * cols + j];
		left[row * cols + j] = left[rem * cols + j];
		left[rem * cols + j] = temp;
	}
	
	temp = right[row];
	right[row] = right[rem];
	right[rem] = temp;

	return;
}

void findMax(int rows, int cols, int row, double* left, double* right)
{
	int i, rem;
	double max = 0.;
	
	for(i = 0; i < rows; i++)
	{
		if(left[cols * i + row] > max) 
		{
			max = left[cols * i + row];
			rem = i;
		}
	}

	if(max != 0.) swap(rows, cols, row, rem, left, right);

	return;
}

int gauss(int rows, int cols, double* left, double* right)
{
	int i, j, p, q;
	
	for(i = 0; i < rows; i++)
	{	
	    if(i < cols)
	    {
			double lead = left[i + i * cols];

			if(lead == 0.) findMax(rows, cols, i, left, right);

	        lead = left[i + i * cols];
        
	        if(lead != 0)
	        {
		        for(j = 0; j < cols; j++) left[i * cols + j] /= lead;

			    right[i] /= lead;
				for(p = 0; p < rows; p++)
				{
					if(p != i)
					{
						double temp = left[p * cols + i];
               
						for(q = 0; q < cols; q++)
						{
							left[p * cols + q] -= temp * left[i * cols + q];
						}
               
						right[p] -= temp * right[i];
					}
				}   
			}
	    }
	}
}

int main(){

	double* leftPart, * rightPart, * solutions;
	int i, j, rows, cols;
	
	printf("Это метод Гаусса для решения СЛАУ вида (A|B),\n");
	printf("где А - матрица коэффициентов, и В - вектор решений\n");
	printf("Пожалуйста, введите размеры матрицы А: сначала строки, потом столбцы,\n");
	printf("а затем построчно (A|B)\n");

	scanf("%d", &rows);
	scanf("%d", &cols);
	
	leftPart = (double*)malloc(rows * cols * sizeof(double));
	rightPart = (double*)malloc(rows * sizeof(double));
	
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)	scanf("%lf", &leftPart[j + i * cols]);

		scanf("%lf", &rightPart[i]);
	}
	
	printf("\n\nВаши матрица и вектор решений:\n");

	for(i = 0; i < rows; i++)	
	{
		for(j = 0; j < cols; j++)	printf("%lf ", leftPart[j + i * cols]);

		printf("%lf\n", rightPart[i]);
	}

	gauss(rows, cols, leftPart, rightPart);

	printf("\n\nВаши матрица и вектор решений в каноническом виде:\n");

	for(i = 0; i < rows; i++)	
	{
		for(j = 0; j < cols; j++)	printf("%lf ", leftPart[j + i * cols]);

		printf("%lf\n", rightPart[i]);
	}

	return 0;
}