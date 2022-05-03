#include<stdio.h>
#define size 20
void Push(char x, int* sp, char dizi[]){
    if(*sp == size){
        printf("Error: Stackoverflow");
        printf("\n");
    }
    *sp = *sp +1;
    dizi[*sp] = x;
}

char Pop(int*sp,char dizi[]){
    *sp = *sp -1;
    return dizi[(*sp) +1];
}
int isEmpty(int sp){
    if(sp == -1){
        return 0;
    }
    return 1;
}


int main(){

int sp = -1;
char dizi[size] = "Hello";
char dizison[size];
int i = 0;
printf("\nDizinin onceki hali: ");
for(i = 0; i < 6; i++){
    printf("%c",dizi[i]);
}
i =0;
while(i < 6){
    Push(dizi[i],&sp,dizi);
    i++;
}

i = 0;
while(isEmpty(sp) == 1){
    dizison[i] = Pop(&sp,dizi);
    i++;
}

printf("\nDizinin son hali: ");
for(i = 0; i < 6; i++){
    printf("%c",dizison[i]);
}

    printf("\n");
    return 0;
}