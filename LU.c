#include<stdio.h>
#include<math.h>
#define s 20

int main(void)
{
	float a[s][s], b[s], x[s], l[s][s], u[s][s], y[s];
	int j, i, k, n;

	printf("enter the number of equations:");
	scanf("%d", &n);

	printf("enter the coefficient matrix:");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%f", &a[i][j]);
		}
	}

	printf("enter the constant matrix:");
	for (i = 0; i < n; i++)
	{
		scanf("%f", &b[i]);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			l[i][j] = 0;
			u[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++)
	{
		u[i][i] = 1;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j <= i)
			{
				l[i][j] = a[i][j];
				for (k = 0; k < j; k++)
				{
					l[i][j] -= l[i][k] * u[k][j];
				}
			}
			else
			{
				u[i][j] = a[i][j];
				for (k = 0; k < i; k++)
				{
					u[i][j] -= l[i][k] * u[k][j];
				}
				u[i][j] /= l[i][i];
			}
		}
	}

	printf("L:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%f\t", l[i][j]);
		}
		printf("\n");
	}
	printf("U:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%f\t", u[i][j]);
		}
		printf("\n");
	}
	printf("\tLU Decomposition Successfull\n");
	for (i = 0; i < n; i++)
	{
		y[i] = b[i];
		for (j = 0; j < i; j++)
		{
			y[i] -= l[i][j] * y[j];
		}
		y[i] /= l[i][i];
	}
	for (i = n - 1; i >= 0; i--)
	{
		x[i] = y[i];
		for (j = n - 1; j > i; j--)
		{
			x[i] -= u[i][j] * x[j];
		}
	}



	printf("\nresult:");
	for (i = 0; i < n; i++)
	{
		printf("\nx[%d]=%f\n", i, x[i]);
	}

	return 0;
}