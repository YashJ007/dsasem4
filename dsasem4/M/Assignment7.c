// minmax
#include <stdio.h>

int arr[10], min, max;

void minmax(int i, int j)
{
    if (i == j)
        min = max = arr[i];
    else if (i == j - 1)
    {
        if (arr[i] > arr[j])
        {
            max = arr[i];
            min = arr[j];
        }
        else
        {
            max = arr[j];
            min = arr[i];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        minmax(i, mid);
        int min1 = min;
        int max1 = max;
        minmax(mid + 1, j);
        if (max < max1)
            max = max1;
        if (min > min1)
            min = min1;
    }
}

int main(void)
{
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    minmax(0, n - 1);
    printf("Min: %d \nMax: %d", min, max);
    return 0;
}
