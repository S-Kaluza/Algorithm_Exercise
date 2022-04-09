int * minAndMaxDivideAndConquer(int* tab, int N){
    int min = 0;
    int max = 0;
    for(int i = 0; i < N - 2; i++){
        if(tab[i] < tab[i + 1]){
            if(tab[i] < tab[min]){
                min = i;
            }
            if(tab[i] > tab[max]){
                max = i;
            }
        }
        else{
            if(tab[i + 1] < tab[min]){
                min = i + 1;
            }
            if(tab[i] > tab[max]){
                max = i;
            }
        }
        i += 2;
    }
    if(N % 2 != 0){
        if(tab[N - 1] < tab[min]){
            min = N - 1;
        }
        if(tab[N - 1] > tab[max]){
            max = N - 1;
        }
    }
    static int score[2];
    score[0] = tab[min];
    score[1] = tab[max];
    return score;
}