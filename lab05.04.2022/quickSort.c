#include<stdio.h>

int partition(char*, int, int);
void change(char*, int, int);

void quickSort(char* tab, int left, int right){
    if(right <= left){return;}
    int i = partition(tab, left, right);
    quickSort(tab, left, i-1);
    quickSort(tab, i + 1, right);

}

int partition(char* tab, int left, int right){
    char x = tab[left];
    int i = left;
    for(int j = left + 1; j <= right; j++){
        if(tab[j] <= x){
            i = i + 1;
            change(tab, i, j);  
        }
    }
    change(tab, left, i);
    return i;
}

void change(char* tab, int left, int right){
    //printf("%d - %c : %d - %c\n", left, tab[left], right, tab[right]);
    char temp = tab[left];
    tab[left] = tab[right];
    tab[right] = temp;
    
}