#include<stdio.h>
#include<stdlib.h>

#include "Ex11A.c"

void IntToBinary(int);
void piramida(int);
void piramida2(int);
int func(int);

int main()
{
    //IntToBinary(366);
    //printf("\n");
    //piramida(6);
    //printf("\n");
    //piramida2(6);

    //printf("%d", func(3));   
    printf("%f", Ex11A(10));
}

void IntToBinary(int number)
{
    if(number == 0) return;

    IntToBinary(number/2);
    printf("%d", number%2);
}

void piramida(int level)
{
    if(level == 0) return;
    for(int j = 0; j < level; j++)
    {
        printf("*");
    }
    printf("\n");
    piramida(level - 1);

}

void piramida2(int level)
{
    if(level == 0) return;
    piramida2(level - 1);
    for(int j = 0; j < level; j++)
    {
        printf("*");
    }
    printf("\n");

}

int func(int number)
{
    if(number == 0) return 0;
    return func(number) * func(number);
}




