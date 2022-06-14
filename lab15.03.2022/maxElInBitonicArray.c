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