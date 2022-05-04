#include<stdio.h>
#include<stdlib.h>

struct adjancencyNode{
    int data;
    struct adjancencyNode* next;
};

struct adjancencyList{
    struct adjancencyNode* head;
};


struct graph{
    int V;//number of vertices
    struct adjancencyList* adjArray; 
};

struct adjancencyNode* newAdjNode(int value){
    struct adjancencyNode* newNode = (struct adjancencyNode*)malloc(sizeof(struct adjancencyNode));
    newNode->data = value;
    newNode->next  =   NULL;
    return newNode;
}

struct graph* createGraph(int VerticesNumber){
    struct graph* aGraph = (struct graph*)malloc(sizeof(struct graph));
    aGraph->V = VerticesNumber;
    aGraph->adjArray = (struct adjancencyList*)malloc(sizeof(struct adjancencyList)*VerticesNumber);

    int i;
    for(i = 0; i <VerticesNumber; i++){
        aGraph->adjArray[i].head = NULL;
    }

    return aGraph;
}

void addEdge(struct graph* aGraph, int src, int dest){
    struct adjancencyNode* check = NULL;
    struct adjancencyNode* newNode = newAdjNode(dest);

    if(aGraph->adjArray[src].head == NULL){
        aGraph->adjArray[src].head = newNode;
    }
    else{
        check = aGraph->adjArray[src].head;
        while(check->next != NULL){
            check = check->next;
        }
        check->next = newNode;


    }

    newNode = newAdjNode(src);
    if(aGraph->adjArray[dest].head == NULL){
        aGraph->adjArray[dest].head =  newNode;
    }
    else{
        check = aGraph->adjArray[dest].head;
        while(check->next != NULL){
            check = check->next;
        }
        check->next = newNode;
    }
}

void printGraph(struct graph* aGraph){
    int v;
    for(v = 0; v < aGraph->V; v++){
        struct adjancencyNode* tmp = aGraph->adjArray[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while(tmp != NULL){
            printf("-> %d", tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    }
}





int main(){

int V =5;

struct graph* aGraph = createGraph(V);
addEdge(aGraph,0,1);
addEdge(aGraph,0,4);
addEdge(aGraph,1,2);
addEdge(aGraph,1,3);
addEdge(aGraph,1,4);
addEdge(aGraph,2,3);
addEdge(aGraph,3,4);
printGraph(aGraph);



    printf("\n");
    return 0;
}