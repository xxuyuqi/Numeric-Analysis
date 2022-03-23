#include<stdio.h>
#include<math.h>

float x3(float x)
{
	return pow(x,3);
}

int main(int argc, char* argv)
{
	int i, j, n;
	float x[10], y[10], LF[10], xp, yp, sum;
	printf("\nEnter no. of discrete data points: ");
	scanf("%d", &n);
	printf("\nEnter:\n");
	for (i = 0; i < n; i++)
	{
		printf("x[%d] = ", i);
		scanf("%f", &x[i]);
		y[i] = x3(x[i]);
		printf("\ty[%d] = %f", i, y[i]);
		//scanf("%f", &y[i]);
		printf("\n");
	}
	printf("\nEnter x: ");
	scanf("%f", &xp);
	sum = 0.0;
	for (i = 0; i < n; i++)
	{
		LF[i] = 1.0;
		for (j = 0; j < n; j++)
		{
			if (i != j)
				LF[i] = ((xp - x[j]) / (x[i] - x[j])) * LF[i];
		}
		sum = sum + LF[i] * y[i];
	}
	yp = sum;
	printf("\np%d(x)=", n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				printf("(x-(%f))", x[j]);
			}
			else
			{
				printf("(%f)", LF[j]);
			}
		}
		printf("+");
	}
	printf("\ny(%f) = %f", xp, yp);
	return 0;
}