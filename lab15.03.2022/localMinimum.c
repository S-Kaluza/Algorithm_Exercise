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