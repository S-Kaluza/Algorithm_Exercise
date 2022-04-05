#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectSort(int*, int);
void bubbleSort(int*, int);
void insertionSort(int*, int);
void change(int*, int, int);
void insertSort(int*, int);
void fillTab(int*, int);
void showMeTab(int*, int);
void copyTab(int*, int*, int);
void minusBubble(int*, int);


int main(){
    int N = 100;
    int* tab;
    int* tab2;
    float a_time;
    FILE *fp;
    fp = fopen("tekst.txt", "w");
    clock_t start = clock();
    
    


    /*Testowanie działania funkcji zadania 1 */
    for(int j = 0; j < 10; j++){
        
        tab = (int*)calloc(N, sizeof(int));
        tab2 = (int*)calloc(N, sizeof(int));
        fillTab(tab, N);

        
        fprintf(fp, "Jest to pętla: %d\nZachodzi dla %d elementów\n", j, N);

        copyTab(tab, tab2, N);
        start = clock();
        bubbleSort(tab2, N);
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp, "%f - bubbleSort ", a_time);
        fprintf(fp, "\n");

        copyTab(tab, tab2, N);
        start = clock();
        selectSort(tab2, N);
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp, "%f - SelectSort, ", a_time);
        fprintf(fp, "\n");

        copyTab(tab, tab2, N);
        start = clock();
        insertSort(tab2, N);
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp, "%f - InsertSort ", a_time);
        fprintf(fp, "\n\n");

        N*=2;
    }
    N = 100;
    /*Testowanie dla zadania 2*/
    fp = fopen("tekst2.txt", "w");
    for(int j = 0; j < 10; j++){
        
        tab = (int*)calloc(N, sizeof(int));
        tab2 = (int*)calloc(N, sizeof(int));
        fillTab(tab, N);
        minusBubble(tab, N);

        
        fprintf(fp, "Jest to pętla: %d\nZachodzi dla %d elementów\n", j, N);

        copyTab(tab, tab2, N);
        start = clock();
        bubbleSort(tab2, N);
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp, "%f - bubbleSort ", a_time);
        fprintf(fp, "\n");

        copyTab(tab, tab2, N);
        start = clock();
        selectSort(tab2, N);
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp, "%f - SelectSort, ", a_time);
        fprintf(fp, "\n");

        copyTab(tab, tab2, N);
        start = clock();
        insertSort(tab2, N);
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp, "%f - InsertSort ", a_time);
        fprintf(fp, "\n\n");

        N*=2;
    }


}

void selectSort(int* tab, int N){
    for(int i = 0; i <= N -2; i++)
    {
        int min = i;
        for(int j = i + 1; j <= N -1; )
        {
            if(tab[j] < tab[min])
            {
                min = j;
            }
            j++;
        }
        change(tab, i, min);
    }
}

void bubbleSort(int* tab, int N){
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i; j < N - 1; j++)
        {
            if(tab[j] < tab[j-1])
            {
                change(tab, j, j-1);
            }
        }
    }
}

void insertSort(int* tab, int N){
    int temp = 0;
    int k = 0;
    for(int j = 1; j < N; j++){
        temp = tab[j];
        k = j - 1;
        while(k >= 0 && temp < tab[k]){
            tab[k + 1] = tab[k];
            k = k - 1;
        }
        tab[k + 1] = temp;
    }
}

void change(int* tab, int i, int min){
    int temp = tab[i];
    tab[i] = tab[min];
    tab[min] = temp;
}

void fillTab(int* tab, int N){
    srand(time(0));
    for(int j = 0; j < N; j++){
        tab[j] = rand()%100;
    }
}

void showMeTab(int* tab, int N){
    for(int j = 0; j < N; j++){
        printf("%d", tab[j]);
    }
}

void copyTab(int* original, int* copy, int N){
    for(int j = 0; j < N; j++){
        copy[j] = original[j];
    }
}

void minusBubble(int* tab, int N){
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i; j < N - 1; j++)
        {
            if(tab[j] > tab[j-1])
            {
                change(tab, j, j-1);
            }
        }
    }
}