#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>


#include "Ex11A.c"

void IntToBinary(int);
void piramida(int);
void piramida2(int);
double zlotyPodzial(int);
int func(int);
double F13(int);
long pascalTriangle(int, int);
int binaryNWD(int, int);
long NWD(int, int);
void reverse(int*, int, int);
int binarySearch(int*, int, int, int);
int iterativeSearch(int*, int, int);
void fillTab(int*, int);
void selectSort(int*, int);
void change(int*, int, int);
void insertSort(int*, int);
void quickSort(int*, int, int);
int partition(int*, int, int);

int main()
{
    int tab[7] = {1, 2, 3, 4, 5, 6, 7};
    int* ptr;
    clock_t start_t, end_t, start_t2, end_t2;
    double total_t, total_t2;
    int i;
    srand(time(0));
    // for(int j = 0, g = 500; j < 10; j++, g*=2){
    //     ptr = (int*)malloc(g * sizeof(int));
    //     fillTab(ptr, g);
    //     quickSort(ptr, 0, g-1);
    //     start_t = clock();
    //     binarySearch(ptr, 0, g-1, 13);
    //     end_t = clock();
    //     start_t2 = clock();
    //     iterativeSearch(ptr, g, 13);
    //     end_t2 = clock();
    //     total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    //     total_t2 = (double)(end_t2 - start_t2) / CLOCKS_PER_SEC;
    //     printf("%d : ", g);
    //     printf("%f : %f\n", total_t, total_t2);
    // }
    long long d = 100000000000000000;

    for(int j = 0; j < 10;j++, d *= 2){
        int q = rand()%d;
        int p = rand()%d;
        start_t = clock();
        binaryNWD(q, p);
        end_t = clock();
        start_t2 = clock();
        NWD(q, p);
        end_t2 = clock();
        total_t = (double)(end_t2 - start_t2) / CLOCKS_PER_SEC;
        total_t2 = (double)(end_t2 - start_t2) / CLOCKS_PER_SEC;
        printf( "%lld -> I : %f :: B : %f\n", d, total_t, total_t2);

    }
}

void IntToBinary(int number)
{
    if(number == 0) return;

    IntToBinary(number/2);
    printf("%d", number%2);
}

void piramida(int level)
{
    if(level == 0) return;
    for(int j = 0; j < level; j++)
    {
        printf("*");
    }
    printf("\n");
    piramida(level - 1);

}

void piramida2(int level)
{
    if(level == 0) return;
    piramida2(level - 1);
    for(int j = 0; j < level; j++)
    {
        printf("*");
    }
    printf("\n");

}

int func(int number)
{
    if(number == 0) return 0;
    return func(number) * func(number);
}

double zlotyPodzial(int n){
    if(n == 0) return 1;
    return 1 + 1/zlotyPodzial(n-1);
}

double F13(int n){
    if(n == 1) return -1;
    return -F13(n - 1) * n - 3;
}

long pascalTriangle(int n, int i){
    if(n == i || i == 0) return 1;
    return pascalTriangle(n - 1, i) + pascalTriangle(n - 1, i - 1);
}

int binaryNWD(int p, int q){
    if(q == 0) return p;
    if(p == 0) return q;
    if((p % 2 == 0) && (q % 2 == 0)) return 2 * binaryNWD(p/2, q/2);
    if((p % 2 == 0)&&(q % 2 != 0)) return binaryNWD(p/2, q);
    if((p % 2 != 0)&&(q % 2 == 0)) return binaryNWD(p, q/2);
    if((p % 2 != 0)&&(q % 2 != 0)&&(p >= q)) return binaryNWD((p-q)/2, q);
    if((p % 2 != 0)&&(q % 2 != 0)&&(p < q)) return binaryNWD(p, (q - p)/2);

}

long NWD (int n, int k){
    if (k == 0) return n;
    return NWD(k, n % k);
}

void reverse(int* tab, int n, int k){
    int rightIndex = n - 1;
    int leftIndex = k - n;
    //printf("left index: %dright Index: %d", leftIndex, rightIndex);
    if(leftIndex > rightIndex) return;
    int temp = tab[leftIndex];
    tab[leftIndex] = tab[rightIndex];
    tab[rightIndex] = temp;
    reverse(tab, n-1, k);
}

int binarySearch(int* tab, int left, int right, int x)
{
   if (right >= left)
   {
        int mid = left + (right - left)/2;
        if (tab[mid] == x)  return mid;
        if (tab[mid] > x) return binarySearch(tab, left, mid-1, x);
        return binarySearch(tab, mid+1, right, x);
   }
   return -1;
}

int iterativeSearch(int* tab, int n, int x){
    if(tab[n]==x) return n;
    else return iterativeSearch(tab, n - 1, x);
    return -1;
}

void fillTab(int* tab, int n){
    for(int j = 0; j < n; j++){
        tab[j] = rand()%100;
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

void change(int* tab, int i, int min){
    int temp = tab[i];
    tab[i] = tab[min];
    tab[min] = temp;
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

void quickSort(int* tab, int left, int right){
    if(right <= left){return;}
    int i = partition(tab, left, right);
    quickSort(tab, left, i-1);
    quickSort(tab, i + 1, right);

}

int partition(int* tab, int left, int right){
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