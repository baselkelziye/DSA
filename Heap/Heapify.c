#include <stdio.h>
#include <stdlib.h>
void heapify(int *, int, int); // array, len,element to be inserted, index of current
void heapSort(int *, int);
void heapYazdir(int *, int);
void insertHeap(int *, int *, int);

int main()
{

    int len, originalLen;
    int *heap;
    int i;
    int startingIndex;
    printf("\nLutfen Heap'in uzunlugunu giriniz\n");
    scanf(" %d", &len);

    heap = (int *)calloc(3 * len, sizeof(int));

    printf("\nLutfen Elemanlari giriniz");
    for (i = 0; i < len; i++)
    {
        scanf(" %d", &heap[i]);
    }
    startingIndex = len / 2 - 1;
    for (i = startingIndex; i >= 0; i--)
    {
        heapify(heap, len, i);
    }
    heapYazdir(heap, len);
    heapSort(heap, len);
    heapYazdir(heap, len);
    // array = 50,30,20,15,10,8,16
    free(heap);
    printf("\n");
    return 0;
}

void heapify(int *heap, int len, int i)

{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < len && heap[largest] < heap[left])
        largest = left;

    if (right < len && heap[largest] < heap[right])
        largest = right;

    if (largest != i)
    {
        int tmp = heap[largest];
        heap[largest] = heap[i];
        heap[i] = tmp;
        heapify(heap, len, largest);
    }
}

void heapSort(int *heap, int len)
{
    int i;
    for (i = len - 1; i > 0; i--)
    {
        int tmp = heap[i];
        heap[i] = heap[0];
        heap[0] = tmp;
        heapify(heap, i, 0);
    }
}

void heapYazdir(int *heap, int len)
{
    int i;
    printf("\nHeap: \n");
    for (i = 0; i < len; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void insertHeap(int *heap, int *len, int data)
{
    heap[*len] = data;
    *len = *len + 1;
    heapify(heap, len, *len - 1);
}

void deleteHeap(int *heap, int *len, int data)
{
    
}