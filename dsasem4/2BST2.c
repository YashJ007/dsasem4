
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

struct node *findMinimum(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left != NULL)
    {
        return findMinimum(root->left);
    }
    return root;
}

struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));

            if (root->left == NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->right;
            }
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = findMinimum(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// void mirror(struct Node* node)
// {
//   if (node==NULL)
//     return;
//   else
//   {
//     struct Node* temp;

//     /* do the subtrees */
//     mirror(node->left);
//     mirror(node->right);

//     /* swap the pointers in this node */
//     temp        = node->left;
//     node->left  = node->right;
//     node->right = temp;
//   }
// }

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
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
    printf("%d ", root->data);
}

int main()
{
    struct node *root = NULL;
    int ch, val;
    do
    {
        printf("\n\n1 - Insert");
        printf("\n2 - Delete");
        printf("\n3 - Display");
        printf("\nYour Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter value to insert : ");
            scanf("%d", &val);
            root = insert(root, val);
            break;

        case 2:
            printf("\nEnter value to delete : ");
            scanf("%d", &val);
            root = deleteNode(root, val);
            break;

        case 3:
            printf("\nInorder Traversal : ");
            inorder(root);
            printf("\nPreorder Traversal : ");
            preorder(root);
            printf("\nPostrder Traversal : ");
            postorder(root);
            break;

        default:
            break;
        }
    } while (ch != 4);

    return 0;
}