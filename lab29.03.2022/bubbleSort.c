#include <stdlib.h>
#include <stdio.h>
#include "auxiliaryFunction.c"

void bubbleSort(int* tab, int N){
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = N - 1; j > i; j--)
        {
            if(tab[j] < tab[j-1])
            {
                change(tab, j, j-1);
            }
        }
    }
}
