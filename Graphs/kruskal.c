#include <stdio.h>

struct edge
{
    int source;
    int destination;
    int weight;
}

struct edgelist
{
    struct edge edgeListesi[10];
}

int
main()
{
    

    int *parent = (int *)malloc(sizeof(int) * 10);

    free(parent);
    printf("\n");
    return 0;
}