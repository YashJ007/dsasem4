#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

struct data
{
    char name[20], ph[20];
    struct data *next;
};

struct data *head[10], *p;

int hashFunction(char str[20])
{
    long long int hash = atoi(str);
    int i = hash % 10;
    return i;
}

void insert()
{
    struct data *temp = (struct data *)malloc(sizeof(struct data));

    printf("\nEnter Name  : ");
    scanf("%s", temp->name);
    printf("Enter phone no. : ");
    scanf("%s", temp->ph);
    temp->next = NULL;

    int i = hashFunction(temp->ph);

    if (head[i] == NULL)
    {
        head[i] = temp;
    }
    else
    {
        p = head[i];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        struct data *q = head[i];
        while (q != NULL)
        {
            printf("\n%d ) %s - %s", i, q->name, q->ph);
            q = q->next;
        }
    }
    printf("\n");
}

int main()
{
    int ch;
    do
    {
        printf("\n\n1 - Insert");
        printf("\n2 - Display");
        printf("\n3 - Exit");
        printf("\nYour Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;

        default:
            printf("Enter valid choice : ");
            break;
        }

    } while (ch != 3);

    return 0;
}