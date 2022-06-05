#include <stdio.h>

void printArray(int a[], int n)
{
    printf("\nArray is - ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, b[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for (int i = 0; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int n;
    printf("Enter the no. of elements in array : ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the array elements : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printArray(a, n);

    mergeSort(a, 0, n - 1);
    printf("\n\nAfter Sorting : -");
    printArray(a, n);

    return 0;
}