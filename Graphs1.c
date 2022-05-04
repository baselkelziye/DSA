
#include <stdio.h>
#define MAX 100

struct edge
{
    int u, v, w;
};

struct edgelist
{
    struct edge data[MAX];
    int n;
};
struct edgelist elist;
int G[MAX][MAX], n;
struct edglelist spanlist;

void kruskal();
void find(int *, int);
void birlesim(int *, int, int);
void sort();
void print();

int main()
{

    int i, j, total_cost, numberOfVertices;

    printf("Enter the number of vertices\n");
    scanf("%d", &numberOfVertices);

    printf("Enter the adjancecy matrix\n");

    for (i = 0; i < numberOfVertices; i++)
    {
        for (j = 0; j < numberOfVertices; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    return 0;
}


void kruskal(){


    int belongs[MAX],i,j,cno1,cno2;
    elist.n = 0;
    for(i = 1; i < numberOfVertices; i++){
        for(j = 0; j <i; j++){
            if(G[i][j] != 0){
                elist.data[elist.n].u = i;
                elist.data[elist.n].v =j;
                elist.data[elist.n].w = G[i][j];
                elist.n++;
            }
        }
    }
sort();
for(i = 0; i < n; i++){
    belongs[i] = i;  
}
spanlist.n = 0;
for(i =0; i <n; i++){
    cno1 = find(belogns,elist.data[i].u);
    cno2 = find(belongs,elist.data[i].v);
}
}
