#include <stdio.h>
#include <stdlib.h>

struct abc
{
  int data;
  struct abc *left, *right;
};

struct abc *insert(struct abc *root, int d);
struct abc *create(int d);
struct abc *delete (struct abc *root, int d);
struct abc *find_min(struct abc *root);
void inorder(struct abc *root);
void preorder(struct abc *root);
void postorder(struct abc *root);
struct abc *search(struct abc *root, int d);

struct abc *insert(struct abc *root, int d)
{
  if (root == NULL)
    return create(d);
  else if (d < root->data)
    root->left = insert(root->left, d);
  else
    root->right = insert(root->right, d);
  return root;
}

struct abc *create(int d)
{
  struct abc *temp = (struct abc *)malloc(sizeof(struct abc));
  temp->data = d;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct abc *delete (struct abc *root, int d)
{
  if (root == NULL)
    return NULL;
  if (d > root->data)
    root->right = delete (root->right, d);
  else if (d < root->data)
    root->left = delete (root->left, d);
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
      return NULL;
    }
    else if (root->left == NULL || root->right == NULL)
    {
      struct abc *temp = (struct abc *)malloc(sizeof(struct abc));
      if (root->left == NULL)
        temp = root->right;
      else
        temp = root->left;
      free(root);
      return temp;
    }
    else
    {
      struct abc *temp = find_min(root->right);
      root->data = temp->data;
      root->right = delete (root->right, temp->data);
    }
  }
  return root;
}

struct abc *find_min(struct abc *root)
{
  if (root == NULL)
    return NULL;
  else if (root->left != NULL)
    return find_min(root->left);
  return root;
}

void inorder(struct abc *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d", root->data);
  printf("\t");
  inorder(root->right);
}

void preorder(struct abc *root)
{
  if (root == NULL)
    return;

  printf("%d", root->data);
  printf("\t");
  preorder(root->left);
  preorder(root->right);
}

void postorder(struct abc *root)
{
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d", root->data);
  printf("\t");
}

struct abc *search(struct abc *root, int d)
{
  struct abc *p = (struct abc *)malloc(sizeof(struct abc));
  p->data = d;
  p->left = NULL;
  p->right = NULL;
  return p;
}

int main()
{
  struct abc *root = NULL;
  int a, b, c, d, ch;
  do
  {
    printf("\n1.Create\n2.Search\n3.Insert\n4.Delete\n5.Inorder\n6.Preorder\n7.Postorder\n8.Exit\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("\nenter number to set  as root of tree:");
      scanf("%d", &a);
      root = create(a);
      break;

    case 2:
      printf("\nenter a number to search in binary tree:");
      scanf("%d", &b);
      root = search(root, b);
      break;

    case 3:
      printf("\nenter a number to insert in binary tree:");
      scanf("%d", &c);
      root = insert(root, c);
      break;

    case 4:
      printf("\nenter a number to delete from binary tree:");
      scanf("%d", &d);
      root = delete (root, d);
      break;

    case 5:
      printf("\ninorder traversing:");
      inorder(root);
      break;

    case 6:
      printf("\npreorder traversing:");
      preorder(root);
      break;

    case 7:
      printf("\npostorder traversing:");
      postorder(root);
      break;

    case 8:
      printf("Thank you!!");
    }
  } while (ch < 8);
  return 0;
}