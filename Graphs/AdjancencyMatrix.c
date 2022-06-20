#include <stdio.h>
#include <stdlib.h>

void addNodeToTheGraph(int **, int, int, int *, int[10][2], int);
void printMatrix(int **, int);
void connectedNode(int[10][2], int);
int isCycle(int **, int);
void setUnion(int *parent, int x, int y);
int findParent(int *, int);

int main()
{

    int V = 5, selection = 0;
    int i, j;
    int x, y, weight;
    int ikilimatris[10][2];
    int edgenumber = 0;

    int **Matrix = (int **)malloc(V * sizeof(int *));
    for (i = 0; i < V; i++)
    {
        Matrix[i] = (int *)malloc(V * sizeof(int));
    }

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            Matrix[i][j] = 0;
        }
    }
    while (selection != -1)
    {
        printf("1->Graf'a Node Ekle\n");
        printf("2->Graf'i yazdir\n");
        printf("3->Bagli dugumleri yazdir\n");
        printf("4->Grafta Dongu Kontrolu\n");
        scanf(" %d", &selection);
        switch (selection)
        {
        case 1:
            printf("Sirasiyla src ve dest ve agirligi giriniz\n");
            scanf(" %d %d %d", &x, &y, &weight);
            addNodeToTheGraph(Matrix, x, y, &edgenumber, ikilimatris, weight);
            break;
        case 2:
            printMatrix(Matrix, V);
            break;

        case 3:
            connectedNode(ikilimatris, edgenumber);
            break;
        case 4:
            if (isCycle(Matrix, V))
            {
                printf("Grafta Dongu Bulunuyor!\n");
            }
            else
            {
                printf("Grafta Dongu bulunmamaktadir!\n");
            }

            break;

        default:
            printf("cikiliyor..\n");
            break;
        }
    }

    //  addNodeToTheGraph(Matrix, 0, 1, &edgenumber, ikilimatris);
    // printMatrix(Matrix, V);
    // connectedNode(ikilimatris, edgenumber);

    // addNodeToTheGraph(Matrix, 2, 3, &edgenumber, ikilimatris);
    // printMatrix(Matrix, V);
    // connectedNode(ikilimatris, edgenumber);

    for (i = 0; i < V; i++)
    {
        free(Matrix[i]);
    }
    free(Matrix);
    printf("\n");
    return 0;
}

void addNodeToTheGraph(int **Matrix, int x, int y, int *edgenumber, int ikilimatris[10][2], int weight)
{
    Matrix[x][y] = weight;
    Matrix[y][x] = weight;

    // printf("matrix inside function call %d %d\n", ikilimatris[*edgeNumber][0], ikilimatris[*edgeNumber][1]);
    ikilimatris[*edgenumber][0] = x;
    ikilimatris[*edgenumber][1] = y;
    *edgenumber = *edgenumber + 1;
}

void printMatrix(int **matrix, int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void connectedNode(int ikilimatris[10][2], int edgenumbers)
{
    int i, j;
    printf("Edges --> %d\n", edgenumbers);
    for (i = 0; i < edgenumbers; i++)
    {
        printf("%d. --> [%d,%d]\n", i, ikilimatris[i][0], ikilimatris[i][1]);
    }
    printf("\n");
}

int findParent(int *parent, int i)
{
    if (parent[i] < 0)
    {
        return i;
    }
    return findParent(parent, parent[i]);
}

void setUnion(int *parent, int x, int y) //
{
    if (abs(findParent(parent, x)) >= abs(findParent(parent, y)))
    {

        parent[y] = x;
        parent[findParent(parent, x)] = parent[findParent(parent, x)] - 1;
    }
    else
    {
        parent[x] = y;
        parent[findParent(parent, y)] = parent[findParent(parent, y)] - 1;
    }
}

int isCycle(int **Matrix, int V)
{
    int *parent = (int *)malloc(sizeof(int) * V);
    int i, j;
    int x, y;
    int z;
    for (i = 0; i < V; i++)
    {
        parent[i] = -1;
    }

    for (i = 0; i < V; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (Matrix[i][j] != 0)
            {
                x = findParent(parent, i);
                y = findParent(parent, j);
                if (x == y)
                {
                    printf("\ni ve j nin degerleri %d %d\n", i, j);
                    printf("\nDongu Yakalandigi An paren dizisi -> ");
                    for (z = 0; z < V; z++)
                    {
                        printf("%d ", parent[z]);
                    }
                    return 1;
                }

                setUnion(parent, x, y);
            }
        }
    }
    printf("\n");
    for (i = 0; i < V; i++)
    {
        printf("%d ", parent[i]);
    }
    return 0;
}