#include<stdio.h>
#include<string.h>
#include<ctype.h>

void push(char*,int*,char);
int pop(char*,int*);
int isOperand(char );
int isOperator(char);
int GetOperatorWeight(char);
void outputYazdir(char* , int );

int main(){

    char stack[20];
    char postfix[20];
    char input_string[20];
    int i;
    int sp = -1, postfixIndex = 0;
    printf("\nLutfen aritmetik islem giriniz\n");
    fgets(input_string,20,stdin);

    int stringLength = strlen(input_string); // adds the null character 
    
    for(i = 0; i < stringLength; i++){
        
        if(isOperand(input_string[i])){
            postfix[postfixIndex] = input_string[i];
            postfixIndex++;
        }
        else if( isOperator(input_string[i])){
            while(sp != -1 && stack[sp] != '(' && GetOperatorWeight(stack[sp]) >= GetOperatorWeight(input_string[i]))
            {
                postfix[postfixIndex] = stack[sp];
                pop(stack,&sp);
                postfixIndex++;
            }
            push(stack,&sp,input_string[i]);
        }
        else if( input_string[i] == '('){
            push(stack,&sp, input_string[i]);
        }
        else if(input_string[i] == ')'){
            while(sp != -1 && stack[sp] != '('){
                postfix[postfixIndex] = stack[sp];
                postfixIndex++;
                pop(stack,&sp);
            }
            pop(stack,&sp);
        }
    }
    while(sp != -1){
        postfix[postfixIndex] = stack[sp];
        pop(stack,&sp);
        postfixIndex++;
    }
    outputYazdir(postfix,stringLength);
    

    printf("\n");
    return 0;
}




void push(char* stack, int* sp, char a){
    if(*sp == 10){
        printf("\nError: Stackoverflow");
        return;
    }
    *sp = *sp+1;
    stack[*sp] = a;
}

int pop(char* stack,int* sp){
    if(*sp == -1){
        printf("\nError: Stack underflow");
        return 0;
    }
    *sp = *sp - 1;
    return stack[*sp+1];
}

int isOperand(char a){
    if( a >= 48 && a <= 57){
        return 1;
    }
    else if(a >= 65 && a <= 90){
        return 1;
    }
    else if(a >= 97 && a <= 122){
        return 1;
    }
    else{
        return 0;
    }
}

int isOperator(char a){

    if(a == '+' || a == '-' || a == '*' || a == '/'){
    return 1;
    }

    return 0;
}



int GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
    weight = 1;
        break;
	case '-':
		weight = 1;
        break;
	case '*':
    weight = 2;
        break;
	case '/':
		weight = 2;
        break;

	}
	return weight;
}


void outputYazdir(char* postfix, int len){
    int i;
    printf("\n");
    for(i =0; i< len; i++){
        printf("%c ", postfix[i]);
    }
}