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
int printAncestors(struct Bstnode *, struct Bstnode *);
void findLeafNumber(struct Bstnode *);
void enqueue(struct Bstnode **, int *, int *, struct Bstnode *, int);
void dequeue(struct Bstnode **, int *, int *, int);
void printLevelOrder(struct Bstnode *, struct Bstnode **, int *, int *);
void printNodesAtDistance(struct Bstnode *, int);
int isEmpty(int, int);
int leafcount = 0;
int main()
{
    struct Bstnode *root = NULL;
    struct Bstnode **Queue = (struct Bstnode **)malloc(sizeof(struct Bstnode *) * 15);
    int front = -1;
    int rear = -1;

    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 12);
    root = insert(root, 14);
    root = insert(root, 8);
    root = insert(root, 6);

    printNodesAtDistance(root, 3);
    //  printLevelOrder(root, Queue, &front, &rear);
    //  search(root, 8);
    // printTree(root);
    // struct Bstnode *tmp = getNewNode(6);
    // findLeafNumber(root);
    // printf("number of leafs is -> %d", leafcount);

    // printAncestors(root, tmp);
    // printf("%d", minIterative(root));
    //  printf("Heigh is: %d", findHeight(root));
    // printLevelOrder(root, Queue, &front, &rear);

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
    newNode->left = NULL;
    newNode->right = NULL;
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
        else if (root->right == NULL)
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

struct Bstnode *findMin(struct Bstnode *root)
{
    if (root == NULL)
    {
        printf("\nHata: Agacta Silinecek Eleman Bulunmamaktadir!");
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

int printAncestors(struct Bstnode *head, struct Bstnode *target)
{
    if (head != NULL)
    {
        if (head->data == target->data)
        {
            return 1;
        }
        if (printAncestors(head->left, target) || printAncestors(head->right, target))
        {
            printf("%d ", head->data);
            return 1;
        }
        return 0;
    }
    return 0;
}

void findLeafNumber(struct Bstnode *root)
{
    if (root != NULL)
    {
        if (root->right == NULL && root->left == NULL)
        {
            leafcount++;
        }
        findLeafNumber(root->left);
        findLeafNumber(root->right);
    }
}

void enqueue(struct Bstnode **Queue, int *front, int *rear, struct Bstnode *tmp, int size)
{
    if (*front == (*rear + 1) % size)
    {
        printf("\nHata: Kuyruk Doludur!");
        return;
    }

    if (*front == -1 && *rear == -1)
    {
        //   printf("\nKuyruga ilk defa eleman atanacak!\n");
        *rear = *rear + 1;
        *front = *front + 1;
        Queue[*rear] = tmp;
        return;
    }
    else
    {
        *rear = (*rear + 1) % size;
        Queue[*rear] = tmp;
    }
}

void dequeue(struct Bstnode **Queue, int *front, int *rear, int Size)
{
    if (*front == -1 && *rear == -1)
    {
        printf("\nHata: Kuyruk bos Eleman cekilemez!");
        return;
    }
    else if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        *front = (*front + 1) % Size;
    }
}

void printLevelOrder(struct Bstnode *root, struct Bstnode **Queue, int *front, int *rear)
{
    enqueue(Queue, front, rear, root, 10);
    enqueue(Queue, front, rear, NULL, 15);
    struct Bstnode *tmp;

    do
    {
        tmp = Queue[*front];
        dequeue(Queue, front, rear, 15);

        if (tmp != NULL)
        {

            printf("%d ", tmp->data);

            if (tmp->left != NULL)
            {
                enqueue(Queue, front, rear, tmp->left, 15);
            }
            if (tmp->right != NULL)
            {
                enqueue(Queue, front, rear, tmp->right, 15);
            }
        }
        if (tmp == NULL)
        {
            printf("\n");
            enqueue(Queue, front, rear, NULL, 15);
        }

    } while (!isEmpty(*rear, *front) && (Queue[*front] != NULL || Queue[*front + 1] != NULL));
}

int isEmpty(int rear, int front)
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printNodesAtDistance(struct Bstnode *root, int distance)
{
    if (root == NULL)
    {
        return;
    }
    if (distance == 0)
    {
        printf("%d ", root->data);
    }
    printNodesAtDistance(root->left, distance - 1);
    printNodesAtDistance(root->right, distance - 1);
}

//{0,2,3,3,2,0,1,0,2,3,1}