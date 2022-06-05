// Construct and expression tree from postfix/prefix expression and perform
// recursive and
// non-recursive In-order, pre-order and post-order traversals.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
    struct node *next; // for stack positions
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
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->next = NULL;
    return ptr;
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}
int main()
{
    struct node *root, *p, *q;
    int n;
    printf("Enter size of string: ");
    scanf("%d", &n);
    char arr[n];
    printf("Enter expression: ");
    scanf("%s", arr);
    // char arr[] = {'A','B','C','*','+','D','/'};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' ||
            arr[i] == '^')
        {
            root = create(arr[i]);
            p = pop();
            q = pop();
            root->right = p;
            root->left = q;
            push(root);
        }
        else
        {
            root = create(arr[i]);
            push(root);
        }
    }
    printf("\nInfix: ");
    inorder(root);
    printf("\nPrefix: ");
    preorder(root);
    printf("\nPostfix: ");
    postorder(root);
    printf("\n");

    return 0;
}
