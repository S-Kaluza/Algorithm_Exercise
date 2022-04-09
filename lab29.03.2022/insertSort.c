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