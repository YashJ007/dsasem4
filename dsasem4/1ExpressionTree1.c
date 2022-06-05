#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *left, *right, *next;
};

struct node *top = NULL;

struct node *createNode(char data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->next = NULL;

    return temp;
}

struct node *pop()
{
    struct node *p = top;
    top = top->next;
    return p;
}

void push(struct node *root)
{
    if (top == NULL)
    {
        top = root;
    }
    else
    {
        root->next = top;
        top = root;
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

int main()
{
    struct node *p, *q, *root;

    int n;
    printf("\nEnter the size of Expression : ");
    scanf("%d", &n);

    char s[n];
    printf("\nEnter the Expression : ");
    scanf("%s", s);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            root = createNode(s[i]);
            p = pop();
            q = pop();
            root->left = q;
            root->right = p;
            push(root);
        }
        else
        {
            root = createNode(s[i]);
            push(root);
        }
    }

    printf("\nInorder expression : ");
    inorder(root);
    printf("\npreorder expression : ");
    preorder(root);
    printf("\npostorder expression : ");
    postorder(root);

    return 0;
}