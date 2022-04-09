#include <stdbool.h>

void shakerSort(int* tab, int N){
    int bottom = 0;
    int top = N - 1;
    bool trans = true;
    while(trans){
        trans = false;
        for(int i = top; i > bottom; i--){
            if(tab[i] < tab[i - 1]){
                change(tab, i, i-1);
                trans = true;
            }
        }
        trans = false;
        bottom++;
        for(int i = bottom; i < top; i++){
            if(tab[i] > tab[i + 1]){
                change(tab, i, i + 1);
                trans = true;
            }
        }
        top = top - 1;
    }
}