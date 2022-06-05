#include <stdio.h>

int size = 0;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int array[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[largest])
            largest = l;
        if (r < size && array[r] > array[largest])
            largest = r;
        if (largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }
}

void insert(int array[], int newNum)
{
    if (size == 0)
    {
        array[0] = newNum;
        size += 1;
    }
    else
    {
        array[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(array, size, i);
        }
    }
}

void deleteRoot(int array[])
{
    int lastElement = array[size - 1];
    array[0] = lastElement;
    size = size - 1;
    heapify(array, size, 0);
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[10];
    int ch;
    int val;
    do
    {
        printf("\n1 - Insert");
        printf("\n2 - Delete");
        printf("\n3 - Display");
        printf("\n4 - Exit");
        printf("\nYour choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value to insert : ");
            scanf("%d", &val);
            insert(array, val);
            break;

        case 2:
            deleteRoot(array);
            break;

        case 3:
            printArray(array, size);
            break;

            // case 3:
            //     printArray(array, size);
            //     break;

        default:
            break;
        }
    } while (ch != 4);
}