#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void filltab(int*, int);
void showMeTab(int*, int);
void copyTab(int*, int*, int);
void change(int*, int, int);

void fillTab(int* tab, int N){
    srand(time(0));
    for(int j = 0; j < N; j++){
        tab[j] = rand()%100;
    }
}

void showMeTab(int* tab, int N){
    for(int j = 0; j < N; j++){
        printf("%d, ", tab[j]);
    }
}

void copyTab(int* original, int* copy, int N){
    for(int j = 0; j < N; j++){
        copy[j] = original[j];
    }
}

void change(int* tab, int i, int min){
    int temp = tab[i];
    tab[i] = tab[min];
    tab[min] = temp;
}