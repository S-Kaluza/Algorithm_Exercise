#include<stdlib.h>
#include<stdio.h>

#include "bubbleSort.c"
#include "selectSort.c"
#include "insertSort.c"
#include "shakerSort.c"
#include "naiveMinMax.c"
#include "divideAndConquer_minAndMax.c"

int partition(int*, int, int);
void quickSort(int*, int, int);
void fillTabWith(int*, int, int);

int main(){
    int N = 1000;
    int* tab;
    int* tab2;
    float a_time;
    clock_t start_t, end_t;
    FILE *fp;
    fp = fopen("zad1.txt", "w");
    for(int j = 0; j < 10; j++, N*=2){
        tab = (int*)malloc(sizeof(int) * N);    
        tab2 = (int*)malloc(sizeof(int) * N);   
        fillTab(tab, N);
        
        fprintf(fp, "Dla %d elementów\n\n", N);
        start_t = clock();
        minAndMaxDivideAndConquer(tab, N);
        end_t = clock();
        a_time = (float)((end_t - start_t))/CLOCKS_PER_SEC;
        fprintf(fp, "DIQMinMax : %f\n", a_time);

        start_t = clock();
        naiveMinMax(tab, N);
        end_t = clock();
        a_time = (float)((end_t - start_t))/CLOCKS_PER_SEC;
        fprintf(fp, "NaiveMinMax : %f\n", a_time);
    }
    fclose(fp);
}

void fillTabWith(int* tab, int n, int x){
    for(int j = 0; j < n; j++){
        tab[j] = x;
    }
}

void quickSort(int* tab, int left, int right){
    if(right <= left){return;}
    int i = partition(tab, left, right);
    quickSort(tab, left, i-1);
    quickSort(tab, i + 1, right);

}

int partition(int* tab, int left, int right){
    int x = tab[left];
    int i = left;
    for(int j = left + 1; j <= right; j++){
        if(tab[j] >= x){
            i = i + 1;
            change(tab, i, j);  
        }
    }
    change(tab, left, i);
    return i;
}