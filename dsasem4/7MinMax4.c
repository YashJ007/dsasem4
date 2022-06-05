#include <stdio.h>

int a[100];
int min, max, n;

void MinMax(int i, int j)
{
    int min1, max1, mid;

    if (i == j)
    {
        min = max = a[i];
    }
    else if (i == j - 1)
    {
        if (a[i] < a[j])
        {
            max = a[j];
            min = a[i];
        }
        else
        {
            max = a[i];
            min = a[j];
        }
    }
    else
    {
        mid = (i + j) / 2;
        MinMax(i, mid);
        max1 = max;
        min1 = min;
        MinMax(mid + 1, j);

        if (max < max1)
        {
            max = max1;
        }
        if (min > min1)
        {
            min = min1;
        }
    }
}

int main()
{
    printf("\nEnter the number of elemets : ");
    scanf("%d", &n);

    printf("\nEnter the numbers : \n");
    for (int i = 1; i <= n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    min = a[0];
    max = a[0];

    MinMax(1, n);

    printf("\nMinimum element in array : %d", min);
    printf("\nMaximum element in array : %d", max);

    return 0;
}