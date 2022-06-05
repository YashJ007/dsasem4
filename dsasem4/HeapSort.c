#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxheap(int a[], int n, int i)
{
    int largest = i;
    int l = (i * 2) + 1;
    int r = (i * 2) + 2;

    if (l < n && a[largest] < a[l])
    {
        largest = l;
    }
    if (r < n && a[largest] < a[r])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        maxheap(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxheap(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        maxheap(a, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nArray before sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    heapsort(a, n);
    printf("\nArray after sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}