#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void filltab(int* , int);
void showTab(int*, int);
void print(int*, int);
int sum_even(int*, int);
void F1(int);
int F2(int);
int F3(int);

int main(){
    int tab[10];
    int T1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int N = -3;
    srand(time(0));
    filltab(tab, 10);
    //print(tab, 10);
    //printf("\n");
    //showTab(tab, 10);
    //printf("\n%d", sum_even(T1, 10));
    //printf("\nPodaj wartość n\n");
    //scanf("%d", &N);
    printf("Wypisz wszystkie liczby od N do 0 a następnie od 0 do NF1\n");
    F1(N);
    printf("\nF2\nSumuj wszystkie cyfry w liczbie\n");
    printf("%d", F2(1234));
    printf("\nF3\nW przedziale od 0 do N ile jest liczb podzielnych przez 5 ale nie przez 3\n");
    printf("%d", F3(15));

}

void filltab(int* tab, int N){
    for(int j=0; j < N; j++){
        tab[j] = rand()%100 + 1;
    }
}

void showTab(int* tab, int N){
    for(int j = 0; j < N; j++){
        printf("%d,", tab[j]);
    }
}

void print(int* tab, int N){
    if(N == 0) return;
    print(tab, N-1);
    printf("%d,", tab[N-1]);
}

int sum_even(int* tab, int N){
    if(N == 0) return 0;
    if(tab[N-1] % 2 == 0) return tab[N-1] + sum_even(tab, N-1);
    if(tab[N-1] % 2 !=0) return sum_even(tab, N-1);
}

int max_elem(int* tab, int N){
    if(N == 0) return tab[N-1];
}

void F1(int N){
    if(N==-1) return;
    if(N < 0) N = rand()%96 + 5;
    printf("%d,", N);
    F1(N-1);
    printf("%d,", N);
}

int F2(int N){
    if(N == 0) return 0;
    return F2(N/10) + N%10;
}

int F3(int N){
    if(N == 0) return 0;
    if((N % 5 == 0) && (N % 3 != 0)) return F3(N - 1) + 1;
    else F3(N - 1);
}
