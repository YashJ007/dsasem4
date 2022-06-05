#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left, *right, *next;
};
struct node *head;

void push(struct node *p)
{
    if (head == NULL)
        head = p;
    else
    {
        p->next = head;
        head = p;
    }
}

struct node *pop()
{
    struct node *p = head;
    head = head->next;
    return p;
}

struct node *create(char val)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    p->next = NULL;

    return p;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%c", root->data);
    inorder(root->left);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    printf("%c", root->data);
}

int main()
{
    struct node *root, *p, *q;
    int n;
    printf("Enter the size of string:");
    scanf("%d", &n);
    char a[n];
    printf("Enter the expression:");
    scanf("%s", a);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '^')
        {
            root = create(a[i]);
            p = pop();
            q = pop();
            root->left = q;
            root->right = p;
            push(root);
        }
        else
        {
            root = create(a[i]);
            push(root);
        }
    }
    printf("\nInfix:");
    inorder(root);
    printf("\nPrefix:");
    preorder(root);
    printf("\nPostfix:");
    postorder(root);
    printf("\n");
    return 0;
}