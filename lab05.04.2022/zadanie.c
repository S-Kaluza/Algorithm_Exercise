#include<stdio.h>
#include "quickSort.c"

int main(){
    char tab[16] = {'q','u','i','c','k','s','o','r','t','e','x','a','m','p','l','e'};
    quickSort(tab, 0, 15);
    for(int j = 0; j < 16; j++){
        printf("%c", tab[j]);
    }
}