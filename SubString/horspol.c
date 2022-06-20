#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void shift_table(char *, int *);
void diziYazdir(int *, int);
int horspol(int *, char *, char *);
int main()
{
    int lenTable;
    char *input_string = (char *)malloc(sizeof(char) * MAX);
    int *table = (int *)malloc(sizeof(int) * MAX);
    char *aranan_string = (char *)malloc(sizeof(char) * MAX);

    printf("\nMetni Giriniz!\n");
    fgets(input_string, 40, stdin);

    printf("\nAramak istediginiz kelimeyi girinzi\n");

    fgets(aranan_string, 20, stdin);
    shift_table(input_string, table);

    diziYazdir(table, MAX);

    printf("horspol -> %d", horspol(table, aranan_string, input_string));

    free(table);
    free(input_string);
    free(aranan_string);
    printf("\n");
    return 0;
}

void shift_table(char *input_string, int *table)
{
    int m;
    int i;
    m = strlen(input_string);
    for (i = 0; i < MAX; i++)
    {
        table[i] = m;
    }

    for (i = 0; i < MAX; i++)
    {
        table[input_string[i] - 'A'] = m - i - 1;
    }
}

void diziYazdir(int *input_dizi, int len)
{
    int i;
    printf("\n");

    // for (i = 0; i < 28; i++)
    // {
    //     printf("%c ", 65 + i);
    // }
    // printf("\n");
    for (i = 0; i < len; i++)
    {
        printf("%d ", input_dizi[i]);
    }
}

int horspol(int *table, char *pattern, char *input_string)
{
    int i, j;
    int k;
    int m = strlen(pattern);
    int n = strlen(input_string);

    i = m - 1; // m yaprsak null characteri gelir
    while (i < n)
    {
        k = 0;
        while (k < m && pattern[m - k - 1] == input_string[i - k])
        {
            k++;
        }
        if (k == m)
        {
            return i - k + 1;
        }
        else
        {
            i = i + n - table[input_string[i - k] - 'A'];
            // printf("\n deger -> %d", table[input_string[i] - 'A']);
        }
    }
    return -1;
}