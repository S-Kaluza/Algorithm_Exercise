void bitonic(int* tab, int N)
{
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