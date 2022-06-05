#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

struct person
{
  char name[20], ph[20];
  struct person *next;
};

struct person *head[SIZE], *p;

void insert()
{
  char name[20], ph[20];
  printf("Enter Name: ");
  scanf("%s", name);
  printf("\nEnter Number: ");
  scanf("%s", ph);
  struct person *temp = (struct person *)malloc(sizeof(struct person));
  strcpy(temp->name, name);
  strcpy(temp->ph, ph);
  temp->next = NULL;

  long long int k = atoi(ph);
  int i = k % SIZE;

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
    while (head[i] != NULL)
    {
      printf("\n\n%d|Name: %s\n", i, head[i]->name);
      printf("Phone Number: %s\n", head[i]->ph);
      head[i] = head[i]->next;
    }
  }
}

int main()
{
  int ch, y = 1;
  do
  {
    printf("Enter 1 to Insert person\nEnter 2 to Display\n");
    printf("\nYour Choice: ");
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
      printf("Enter valid choice!");
      break;
    }
    printf("1) Continue \t 2) Quit\n");
    printf("Do you want to continue? : ");
    scanf("%d", &y);
  } while (y == 1);

  return 0;
}