#include<stdio.h>
#include<stdlib.h>
#define SIZE 8

void push(char* ,int*,char);
void pop(char*, int*);
int checkEqual(char*, int ,char);


int main(){

char* stack = (char*)malloc(sizeof(char)*SIZE);
char input_string[SIZE];

printf("Enter String:\n");
fgets(input_string,SIZE,stdin);

int sp = -1;
int i;
int diff_brace;
for(i =0; i<6; i++){
    if(input_string[i] == '(' || input_string[i] == '[' || input_string[i] == '{'){
        push(stack,&sp,input_string[i]);
    }
    else if(input_string[i] == ')' || input_string[i] == ']' || input_string[i] == '}' ){
      //  diff_brace = stack[sp] - input_string[i];
       
        if( checkEqual(stack,sp,input_string[i]) == -1 ){
            printf("\nError:Not Equal");
        }
        else{
            pop(stack,&sp);
        }
    }
}

if(sp == -1){
    printf("\nParentheses Are Balanced");
}
else{
    printf("\nParentheses Are Not Balanced");
}




    free(stack);
    printf("\n");
    return 0;
}

void push(char* stack,int*sp, char expression){
    *sp = *sp+1;
    stack[*sp] = expression;
}

void pop(char* stack, int*sp){
    *sp = *sp-1;
}

int checkEqual(char* stack, int sp, char a){
    
    if(stack[sp] == '(' && a == ')'){
        return 1;
    }
    else if(stack[sp] == '{' && a== '}'){
        return 1;
    }
    else if(stack[sp] == '[' && a == ']'){
        return 1;
    }
    else{
        return -1;
    }
}