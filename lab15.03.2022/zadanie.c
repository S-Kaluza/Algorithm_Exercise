#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void sumOne(unsigned long long);
void sumTwo(unsigned long long);
void sumThree(unsigned long long);
int bruteForce(int, int*);
void fillTab(int* tab, int);

int main()
{
    //sumOne((unsigned long long)256);
    //sumThree(512);

    int tab[7] = {1, 2, 3, 4, 5};
    for(int j = 0; j < 7; j++ ) printf(tab[j]);
       
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
    int* tab = (int*)malloc(N * sizeof(int));
    int sum = 0;
    fillTab(tab, N);
    for(int j = 0; j < N-4; j++){
        for(int i = j + 1; j < N-5; i++){
            for(int k = i + 1; k < N-6; i++){
                for(int l = k + 1; l < N-7; i++){
                    if(tab[j] + tab[i] + tab[k] + tab[l] == 0) sum++;
                }
            }
        }
    }

}

void fillTab(int* tab, int N)
{
    srand(time(0));
    for(int j = 0; j < N, j++)
    {
        tab[j] = rand()%10;
    }
}