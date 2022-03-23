#include <stdio.h>
#include <stdlib.h>
#define s 3

float absolute(float);

main()
{
    int i, j, k, n, i_max;
    float A[s][s], x[s], b[s], temp, max;
    //float A[s][s] = { {1,2,3},{0,1,2},{2,4,1} }, x[s] , b[s] = { 14,8,13 }, temp, max;
    //n = 3;

    printf("enter the number of equations:");
    scanf("%d", &n);

    printf("enter the coefficient matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }

    printf("enter the constant matrix:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &b[i]);
    }


    for (i = 0; i < n; i++)
    {
        max = absolute(A[i][i]);
        i_max = i;
        for (j = i + 1; j < n; j++)
        {
            if (absolute(A[j][i]) > max)
            {
                max = absolute(A[j][i]);
                i_max = j;
            }
        }


        for (j = 0; j < n; j++)
        {
            temp = A[i][j];
            A[i][j] = A[i_max][j];
            A[i_max][j] = temp;
        }
        temp = b[i];
        b[i] = b[i_max];
        b[i_max] = temp;

        for (j = i; j < n; j++)
        {
            A[i][j] /= max;
        }
        b[i] /= max;

        for (j = i + 1; j < n; j++)
        {
            temp = A[j][i];
            for (k = i; k < n; k++)
            {
                A[j][k] -= temp*A[i][k];
            }
            b[j] -= temp * b[i];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%f\t",A[i][j]);
        }
        printf("\t%f", b[i]);
        printf("\n");
    }

    for (i = n - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for (j = n - 1; j > i; j--)
        {
            x[i] -= A[i][j] * x[j];
        }
    }
    printf("Computation of the variables Successfully Completed\n");
    
    printf("\nresult:");
    for (i = 0; i < n; i++)
    {
        printf("\nx[%d]=%f\n", i, x[i]);
    }
    return 0;
}

float absolute(float x)
{
    if (x < 0)
        return -x;
    else
        return x;
}