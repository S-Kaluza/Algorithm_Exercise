#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>

void sumOne(unsigned long long);
void sumTwo(unsigned long long);
void sumThree(unsigned long long);
int bruteForce(int, int*);
int localMinimum(int*, int);
int maxElInBitonicArray(int*, int);
bool bitonicSearch(int*, int, int);
void bitonic(int*, int);
void fillTab(int* tab, int);

int main()
{
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
}

void sumOne(unsigned long long N)
{
    int ile = 0;
    clock_t start = clock();
    clock_t stop = clock();
    float a_time;
    FILE *fp;
    fp = fopen("/mnt/c/Users/szymo/Desktop/Algorytmy/lab15.03.2022/zadanie2.txt", "w");
    while (ile < 25)
    {
        start = clock();
        unsigned long long sum = 0;
        for (unsigned long long n = N; n > 0; n /= 2)
        for (unsigned long long i = 0; i < n; i++)
        sum++;
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp ,"%f\n", a_time);
        ile++;
        N *= 2;
    }
    fclose(fp);
}

void sumTwo(unsigned long long N)
{
    int ile = 0;
    int sum = 0;
    clock_t start = clock();
    clock_t stop = clock();
    float a_time;
    FILE *fp;
    fp = fopen("/mnt/c/Users/szymo/Desktop/Algorytmy/lab15.03.2022/zadanie3.txt", "w");
    while(ile < 25){
        start = clock();
        unsigned long long sum = 0;
        for (int i = 1; i < N; i *= 2)
        for(int j = 0; j < i; j++)
            sum++;
            ile++;
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp ,"%f\n", a_time);
    }
    fclose(fp);
}

void sumThree(unsigned long long N)
{
    int ile = 0;
    int sum = 0;
    clock_t start = clock();
    clock_t stop = clock();
    float a_time;
    FILE *fp;
    fp = fopen("/mnt/c/Users/szymo/Desktop/Algorytmy/lab15.03.2022/zadanie4.txt", "w");
    while(ile < 25){
        start = clock();
        unsigned long long sum = 0;
        for (int i = 1; i < N; i *= 2)
        for(int j = 0; j < N; j++)
            sum++;
            ile++;
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp ,"%f\n", a_time);
    }
    fclose(fp);
}

int bruteForce(int N, int* tab)
{
    int sum = 0;
    for(int j = 0, i = 1, k = 2; j < N-3; j++, i++, k++){
        printf("i:%d - j:%d - k:%d", j, i, k);
        for(int l = k + 1; l < N; l++){
                    if(tab[j] + tab[i] + tab[k] + tab[l] == 0) sum++;
                    printf("-l:%d\n", l);
                    printf("%d + %d + %d + %d\n", tab[j], tab[i], tab[k], tab[l]);
                }
    }
    return sum;
}

int localMinimum(int* tab, int N){
    int localMin = 0;
    int L = 0;
    int R = N-1;
    int M = 0;
    while(L != R){
        M = (L + R)/2;
        if(tab[M]<tab[M-1] && tab[M]<tab[M+1]) return tab[M];
        else if(tab[M-1] < tab[M+1]) R = M-1;
        else if(tab[M-1] > tab[M+1]) L = M+1;
    }
    if(tab[L] < tab[L-1] && tab[L] < tab[L+1]) return tab[L];
    else return 0;
}

int maxElInBitonicArray(int* tab, int N){
    int L = 0;
    int R = N;
    int mid = (L + R)/2;
    while(L != R){
        mid = (L + R)/2;
        if(tab[mid]>tab[mid-1] && tab[mid]>tab[mid+1]) return tab[mid];
        else if(tab[mid-1] > tab[mid+1]) R = mid-1;
        else if(tab[mid-1] < tab[mid+1]) L = mid+1;
    }
    return tab[L];

}

bool bitonicSearch(int* tab, int N, int key){
    int L = 0;
    int R = N;
    int start1, end1, start2, end2;
    int mid = (L + R)/2;
    while(L != R){
        mid = (L + R)/2;
        if(tab[mid]>tab[mid-1] && tab[mid]>tab[mid+1]) break;
        else if(tab[mid-1] > tab[mid+1]) R = mid-1;
        else if(tab[mid-1] < tab[mid+1]) L = mid+1;
    }
    start1 = 0;
    end1 = mid-1;
    start2 = mid;
    end2 = N;

    while(start1 <= end1){
        mid = start1 + (end1 - start1)/2;
        if(tab[mid] == key) return true;
        else if(tab[mid] < key) start1 = mid + 1;
        else end1 = mid  - 1; 

    }

    while(start2 <= end2){
        mid = start2 + (end2 - start2)/2;
        if(tab[mid] == key) return true;
        else if(tab[mid] > key) start2 = mid + 1;
        else end2 = mid  - 1; 

    }
    printf("\n");
    return false;


}

void fillTab(int* tab, int N)
{
    srand(time(0));
    for(int j = 0; j < N; j++)
    {
        tab[j] = rand()%10;
    }
}

void bitonic(int* tab, int N)
{
    srand(time(0));
    int mid = rand()%N;
    tab[0] = rand()%9;
    for(int i = 1; i < mid; i++){
        tab[i] = tab[i-1] + 1 + (rand()%9);
    }
    if(mid > 0) tab[mid] = tab[mid - 1] + (rand()%10) - 5;
    for(int i = mid + 1; i < N; i++){
        tab[i] = tab[i-1] -1 - (rand()%9);
    }
}