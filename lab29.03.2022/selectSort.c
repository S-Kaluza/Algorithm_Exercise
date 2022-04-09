
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
