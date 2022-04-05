#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectSort();
void fillTab(int*, int);
void load(int *, int);
void selectSort(int*, int);
void change(int*, int, int);
void bubbleSort(int*, int);

int main()
{
    FILE *fp;
    fp = fopen("tekst.txt", "w");

    srand(time(0));
    int noe = 128; //number of elements
    int* tab;
    float a_time;
    char* tekst;
    clock_t start = clock();
    for (int i = 0; i < 10; i++, noe *= 2)
    {
        tab = (int *) calloc(noe, sizeof(int));
        fillTab(tab, noe);
        start = clock();
        selectSort(tab, noe);
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp, "%f", a_time);
        fprintf(fp, "\n ");
        free(tab);
    }

    for(int i = 0; i < 5; i++){
        fprintf(fp ,"\n");
        printf(".");
    }
    noe = 128;
    for(int i = 0; i < 10; i++, noe *= 2)
    {
        
        tab = (int *) calloc(noe, sizeof(int));
        fillTab(tab, noe);
        start = clock();
        bubbleSort(tab, noe);
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp, "%f", a_time);
        fprintf(fp, "\n");
        free(tab);
    }
    
   /*tab = (int *) calloc(noe, sizeof(int));
   fillTab(tab, noe);
   selectSort(tab, noe);
   load(tab, noe);*/
    

}

void fillTab(int* tab, int numberOfElements)
{
    for(int i = 0; i < numberOfElements; i++)
    {
        tab[i] = rand()%1000;
    }
}

void load(int* tab, int noe)
{
    for(int i = 0; i < noe; i++)
    {
        printf("%d, ", tab[i]);
    }
}

void selectSort(int* tab, int noe)
{
    for(int i = 0; i <= noe -2; i++)
    {
        int min = i;
        for(int j = i + 1; j <= noe -1; )
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

void change(int* tab, int i, int min)
{
    int temp = tab[i];
    tab[i] = tab[min];
    tab[min] = temp;
}

void bubbleSort(int* tab, int noe)
{
    for(int i = 0; i < noe - 1; i++)
    {
        for(int j = i; j < noe - 1; j++)
        {
            if(tab[j] < tab[j-1])
            {
                change(tab, j, j-1);
            }
        }
    }
}