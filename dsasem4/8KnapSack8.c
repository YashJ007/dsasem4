#include <stdio.h>

void knapsack_r(int n, float weight[], float profit[], float capacity)
{
    int i, j, temp;
    float u;
    float x[10], tp = 0;

    u = capacity;

    for (i = 0; i < n; i++)
    {
        x[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
        {
            break;
        }
        else
        {
            x[i] = 1;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n)
    {
        x[i] = u / weight[i];
    }
    tp = tp + (x[i] * profit[i]);

    printf("\nTotal Profit by ratio method : %f\n", tp);
}
void knapsack_p(int n, float weight[], float profit[], float capacity)
{
    int i, j, temp;
    float u;
    float x[10], tp = 0;

    u = capacity;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (profit[i] < profit[j])
            {
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        x[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
        {
            break;
        }
        else
        {
            x[i] = 1;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n)
    {
        x[i] = u / weight[i];
    }
    tp = tp + (x[i] * profit[i]);

    printf("\nTotal Profit by profit method : %f\n", tp);
}
void knapsack_w(int n, float weight[], float profit[], float capacity)
{
    int i, j, temp;
    float u;
    float x[10], tp = 0;

    u = capacity;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (weight[i] > weight[j])
            {
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        x[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
        {
            break;
        }
        else
        {
            x[i] = 1;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n)
    {
        x[i] = u / weight[i];
    }
    tp = tp + (x[i] * profit[i]);

    printf("\nTotal Profit by Weight method : %f\n", tp);
}

int main()
{
    float weight[10], profit[10], ratio[10], capacity, temp;
    int n, i, j;

    printf("\nEnter the number of objects : ");
    scanf("%d", &n);

    printf("\nEnter the weight and profits of each objects : ");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter capacity of knapsack : ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    knapsack_r(n, weight, profit, capacity);
    knapsack_p(n, weight, profit, capacity);
    knapsack_w(n, weight, profit, capacity);
}