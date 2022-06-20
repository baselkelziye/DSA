#include <stdio.h>
#include <stdlib.h>
void heapify(int *, int, int);
void myHeapSort(int *, int);
int main()
{

    int N;
    int *heap;
    int i;
    int starting_index = N / 2 - 1;

    printf("\n Heap' in elememan sayisini giriniz\n");
    scanf(" %d", &N);

    heap = (int *)malloc(sizeof(int) * N);

    printf("\n");
    for (i = 0; i < N; i++)
    {
        scanf(" %d", &heap[i]);
    }

    for (i = 0; i < N; i++)
    {
        printf("%d ", heap[i]);
    }

    for (i = starting_index; i >= 0; i--)
    {
        heapify(heap, N, i);
    }

    printf("\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", heap[i]);
    }

    myHeapSort(heap, N);
    printf("\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");
    return 0;
}

void heapify(int *heap, int len, int key)
{

    int left = 2 * key + 1;
    int right = 2 * key + 2;
    int smallest = key;

    if (heap[left] < heap[smallest] && left < len)
    {
        smallest = left;
    }

    if (heap[right] < heap[smallest] && right < len)
    {
        smallest = right;
    }

    if (smallest != key)
    {
        int tmp = heap[key];
        heap[key] = heap[smallest];
        heap[smallest] = tmp;
        heapify(heap, len, smallest);
    }
    
}

void myHeapSort(int *heap, int len)
{
    int i;
  
    for (i = len - 1; i >= 0; i--)
    {
        int tmp = heap[i];
        heap[i] = heap[0];
        heap[0] = tmp;
        heapify(heap, i, 0);
    }
}