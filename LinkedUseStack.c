#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};

void Push(int x, struct Node** top){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = *top;
    *top = temp;

}
void Pop(struct Node** top){
  if(top == NULL){
      printf("\nStack is Empty");
      return;
  }
struct Node*tmp = *top;
 *top = (*top)->link;
 free(tmp);
}
void printStack(struct Node* top){
    while(top != NULL){
        printf("%d ", top->data);
        top = top->link;
    }
    printf("\n");
}

int main(){
/*to the complexity be O(1) we must add the node at the beggining */
struct Node* top = NULL;
Push(5,&top);
printStack(top);
Push(7,&top);
printStack(top);
Push(2,&top);
printStack(top);
Pop(&top);
printStack(top);
    printf("\n");
    return 0;
}