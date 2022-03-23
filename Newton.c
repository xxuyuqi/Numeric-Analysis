#include <stdio.h>
#include <math.h>

#define N 4
double a[N - 1] = { 0.0 };


void fun(double* x, double* y, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        y[i] = log(x[i]);
    }
}


int factorial(int n)
{
    if (n > 0) {
        return n * factorial(n - 1);
    }
    else {
        return 1;
    }
}


void difference(double *x, double* y)
{
    double buf[N];
    int i, j, k;
    memcpy(buf, y, (sizeof(double) * N));
    for (j = 0; j < N - 1; j++) {
        for (k = 0; k < (N - (1 + j)); k++) {
            buf[k] = buf[k + 1] - buf[k];
        }
        a[j] = buf[0];
    }
}

double newton(double *x, double*y, double xp)
{
    double sum, temp;
    double p;

    p = (xp - x[0]) / (x[1] - x[0]);

    difference(x, y);

    sum = y[0];
    for (int i = 0; i < N; i++) {
        temp = 1;
        for (int j = 0; j < (i + 1); j++) {
            temp *= (p - j);
        }
        temp = temp * a[i] / factorial(i + 1);
        sum += temp;
    }
    return sum;
}

void print(char* st, double* data, int n)
{
    int i;
    printf("\n%s",st);
    for (i = 0; i < n; i++)
    {
        printf("\t%f", data[i]);
    }
}


int main(void)
{
    double x[N] = { 10, 11, 12, 13 };
    double y[N];
    fun(x, y, N);
    print("x:", x, N);
    print("y:", y, N);
    double xp;
    printf("\nEnter x: ");
    scanf("%lf", &xp);
    printf("\ny = %f\n", newton(x, y, xp));
    print("a:", a, N - 1); // a[i] = f(x0,...,xi)*(x1-x0)*(x2-x1)...
    return 0;
}