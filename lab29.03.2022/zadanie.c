#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "reversedBubbleSort.c"
#include "insertSort.c"
#include "bubbleSort.c"
#include "selectSort.c"
#include "shakerSort.c"
#include "auxiliaryFunction.c"
#include "divideAndConquer_minAndMax.c"
#include "naiveAlgorithmExponentiation.c"
#include "divideAndConquer_Exponentiation.c"

void change(int*, int, int);

int main(){
    int N = 100;
    int* tab;
    int* tab2;
    clock_t start_t, end_t;
    float a_time;
    FILE *fp;
    fp = fopen("tekst.txt", "w");
    
    // /*Testowanie działania funkcji zadania 1 */
    // for(int j = 0; j < 10; j++){
        
    //     tab = (int*)calloc(N, sizeof(int));
    //     tab2 = (int*)calloc(N, sizeof(int));
    //     fillTab(tab, N);

        
    //     fprintf(fp, "Jest to pętla: %d\nZachodzi dla %d elementów\n", j, N);

    //     copyTab(tab, tab2, N);
    //     start = clock();
    //     bubbleSort(tab2, N);
    //     a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
    //     fprintf(fp, "%f - bubbleSort ", a_time);
    //     fprintf(fp, "\n");

    //     copyTab(tab, tab2, N);
    //     start = clock();
    //     selectSort(tab2, N);
    //     a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
    //     fprintf(fp, "%f - SelectSort, ", a_time);
    //     fprintf(fp, "\n");

    //     copyTab(tab, tab2, N);
    //     start = clock();
    //     insertSort(tab2, N);
    //     a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
    //     fprintf(fp, "%f - InsertSort ", a_time);
    //     fprintf(fp, "\n\n");

    //     N*=2;
    // }


    // N = 100; //przywrócenie początkowej wartości N
    
    // /*Testowanie dla zadania 2*/
    // fp = fopen("tekst2.txt", "w");
    // for(int j = 0; j < 10; j++){
        
    //     tab = (int*)calloc(N, sizeof(int));
    //     tab2 = (int*)calloc(N, sizeof(int));
    //     fillTab(tab, N);
    //     minusBubble(tab, N);

        
    //     fprintf(fp, "Jest to pętla: %d\nZachodzi dla %d elementów\n", j, N);

    //     copyTab(tab, tab2, N);
    //     start = clock();
    //     bubbleSort(tab2, N);
    //     a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
    //     fprintf(fp, "%f - bubbleSort ", a_time);
    //     fprintf(fp, "\n");

    //     copyTab(tab, tab2, N);
    //     start = clock();
    //     selectSort(tab2, N);
    //     a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
    //     fprintf(fp, "%f - SelectSort, ", a_time);
    //     fprintf(fp, "\n");

    //     copyTab(tab, tab2, N);
    //     start = clock();
    //     insertSort(tab2, N);
    //     a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
    //     fprintf(fp, "%f - InsertSort ", a_time);
    //     fprintf(fp, "\n\n");

    //     N*=2;
    // }
    printf("%d\n", naiveExponentiation(2, 10));
    printf("%ld", divideAndConquerExponentiation(2, 10)); 
    
}