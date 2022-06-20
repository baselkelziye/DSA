#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Reverse(struct Node *head)
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
struct Node *getNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = x;

    return newNode;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main()
{
    struct Node *head = NULL;
    struct Node *tmp = getNewNode(10);
    struct Node *tmp2;
    head = tmp;
    int i;
    for (i = 0; i < 5; i++)
    {
        tmp2 = getNewNode(i);
        tmp->next = tmp2;
        tmp = tmp2;
    }

    printList(head);

    head = Reverse(head);
    printf("\n");
    printList(head);
    printf("\n");
    return 0;
}