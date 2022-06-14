#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>

#include "bitonic.c"
#include "bitonicSearch.c"
#include "bruteForce.c"
#include "localMinimum.c"
#include "maxElInBitonicArray.c"

void fillTab(int* tab, int);

int main()
{
    //zadanie2.txt -> sumOne
    //zadanie3.txt -> sumTwo
    //zadanie4.txt -> sumThree
    //zadanie5.txt -> 
    srand(time(0));
    //sumOne((unsigned long long)256);
    //sumThree(512);
    int tab[15];
    //for(int j = 0; j < 7; j++ ) printf("%d, ", tab[j]);
    bitonic(tab, 15);
    for(int i = 0; i < 15; i++) printf("%d, ", tab[i]);    
    printf("\n");
    printf("%d", maxElInBitonicArray(tab, 15));
    printf("\n");
    if(bitonicSearch(tab, 15, 20)) printf("true");
    else printf("false");
    int tablica[4] = {1, 2, -3, 0};
    printf("\n%d", bruteForce(4, tablica));


}

void fillTab(int* tab, int N)
{
    
    for(int j = 0; j < N; j++)
    {
        tab[j] = rand()%10;
    }
}

