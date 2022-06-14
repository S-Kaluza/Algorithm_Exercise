#include<stdlib.h>
#include<stdio.h>

#include "bubbleSort.c"
#include "selectSort.c"
#include "insertSort.c"

void fillTabWith(int*, int, int);

int main(){
    int N = 100;
    int* tab;
    int* tab2;
    float a_time;
    clock_t start_t, end_t;
    FILE *fp;
    fp = fopen("zad1.txt", "w");
    for(int j = 0; j < 10; j++, N*=2){
        tab = (int*)malloc(sizeof(int) * N);    
        fillTabWith(tab, N, 7);
        fprintf(fp, "Dla %d elementów\n\n", N);
        start_t = clock();
        bubbleSort(tab, N);
        end_t = clock();
        a_time = (float)((end_t - start_t))/CLOCKS_PER_SEC;
        fprintf(fp, "Bubblesort : %f\n", a_time);

        start_t = clock();
        insertSort(tab, N);
        end_t = clock();
        a_time = (float)((end_t - start_t))/CLOCKS_PER_SEC;
        fprintf(fp, "InsertSort : %f\n", a_time);

        start_t = clock();
        selectSort(tab, N);
        end_t = clock();
        a_time = (float)((end_t - start_t))/CLOCKS_PER_SEC;
        fprintf(fp, "SelectSort : %f\n", a_time);
    }
    fclose(fp);
}

void fillTabWith(int* tab, int n, int x){
    for(int j = 0; j < n; j++){
        tab[j] = x;
    }
}