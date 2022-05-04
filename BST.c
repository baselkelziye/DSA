#include <stdio.h>
#include <stdlib.h>
struct Bstnode
{
    int data;
    struct Bstnode *right;
    struct Bstnode *left;
};
struct Bstnode *insert(struct Bstnode *, int);
struct Bstnode *getNewNode(int);
void search(struct Bstnode *, int);
void printTree(struct Bstnode *);
int minIterative(struct Bstnode *);
int findHeight(struct Bstnode *);
int max(int, int);
void LevelOrder(struct Bstnode *);
struct Bstnode *delete (struct Bstnode *, int);
struct Bstnode *findMin(struct Bstnode *);
int main()
{
    struct Bstnode *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 12);
    root = insert(root, 14);
    root = insert(root, 8);
    root = insert(root, 6);
    //  search(root, 8);
    // printTree(root);
    // printf("%d", minIterative(root));
    printf("Heigh is: %d", findHeight(root));

    printf("\n");
    return 0;
}

struct Bstnode *insert(struct Bstnode *root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
    }
    else if (data <= (root)->data)
    {
        root->left = insert((root)->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Bstnode *getNewNode(int x)
{
    struct Bstnode *newNode = (struct Bstnode *)malloc(sizeof(struct Bstnode));
    newNode->data = x;
    return newNode;
}

void search(struct Bstnode *root, int key)
{
    if (root == NULL)
    {
        printf("\n Not Found");
        return;
    }
    else if (root->data == key)
    {
        printf("Found\n");
        return;
    }
    else if (key < root->data)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
    printf("\n");
}

void printTree(struct Bstnode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

int minIterative(struct Bstnode *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty\n");
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int max(int x, int y)
{
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int findHeight(struct Bstnode *root)
{

    if (root == NULL)
    {
        return -1;
    }

    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

struct Bstnode *delete (struct Bstnode *root, int data)
{
    if (root == NULL)
    {
        printf("\ntree is empty");
        return;
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL; // cuz dangling pointer
        }

        else if (root->left == NULL)
        {
            struct Bstnode *tmp = root;
            root = root->right;
            free(tmp);
        }
        else if (root->right = NULL)
        {
            struct Bstnode *tmp = root;
            root = root->left;
            free(tmp);
        }

        else
        {
            struct Bstnode *tmp = findMin(root->right);
            root->data = tmp->data;
            root->right = delete (root->right, tmp->data);
        }
    }
    return root;
}

struct Bstnode* findMin(struct Bstnode *root)
{
    if (root == NULL)
    {
        printf("\nHata: Agacta Silinecek Eleman Bulunmamaktadir!");
        return -1;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}