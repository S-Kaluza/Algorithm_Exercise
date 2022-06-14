#include<stdio.h>
#include<stdlib.h>

void F1(int);
void F2(int);
void F3(int);
int F4(int, int);
int F7(int);

int main()
{
    printf("%d", F7(6));
}

void F1(int n){
    if (n <= 0) return;
    printf("%d,", n);
    F1(n - 2);
    F1(n - 3);
    printf("%d,", n);
}

void F2(int n){
    if (n <= 0) return;
    F1(n - 3);
    printf("%d,", n);
    F1(n - 2);
    printf("%d,", n);
}

void F3(int n){
    if (n <= 0) return;
    F1(n - 3);
    F1(n - 2);
    printf("%d,", n);
    printf("%d,", n);
}

int F4(int a, int b){
    if(b == 0) return 0;
    if (b % 2 == 0) return F4(a + a, b/2);
    return F4(a + a, b/2) + a;
}

int F7(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    return 2 * F7(n - 2) + F7(n - 3);
}