#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void push(int*,int*,int);
int pop(int*,int*);
// int isOperand(char*,char);
// int isOperator(char*,char);
int main(){

    char input_string[20];
     int stackSize,i; // stack size is also the len of the input string
     int op1,op2;
     int sp = -1;
     char tmpChar;
     int value;// the value will be pushed to stack after and operation

    printf("\nPlease Enter The Expression You'd Like to Evaluate\n");
    fgets(input_string,20,stdin);
    stackSize = strlen(input_string);
   // printf("\nLen: %d", stackSize);
    int* stack = (int*)malloc(sizeof(int)*stackSize);

    for(i = 0; i<stackSize; i++){
        tmpChar = input_string[i];
        if(isdigit(tmpChar)){
            push(stack,&sp,tmpChar - '0');
        }
        else if(tmpChar == '+' || tmpChar == '-' || tmpChar == '*' || tmpChar == '/'){
            op2 = pop(stack,&sp);
            op1 = pop(stack,&sp);
            switch(tmpChar){

                case '+':
                value = op1 + op2;
                break;

                case '-':
                value = op1 - op2;
                break;

                case '*':
                value = op1 * op2;
                break;

                case '/':
                value = op1/op2;
                break;

            }
            push(stack,&sp,value);
        }
    }

    printf("\n Result is: %d", pop(stack,&sp));

    free(stack);
    printf("\n");
    return 0;
}

void push(int* stack, int* sp, int a){
    if(*sp == 10){
        printf("\nError: Stackoverflow");
        return;
    }
    *sp = *sp+1;
    stack[*sp] = a;
}

int pop(int* stack,int* sp){
    if(*sp == -1){
        printf("\nError: Stack underflow");
        return 0;
    }
    *sp = *sp - 1;
    return stack[*sp+1];
}

int isOperand(char* input_string, char a){
    if(a >= 48 && a <= 57){
        return 1;
    }
    else{
        return -1;
    }
}

// int isOperator(char* input_string,char a){
//     if(a >=)
// }
