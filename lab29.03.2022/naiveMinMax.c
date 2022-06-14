int* naiveMinMax(int* tab, int N){
    int min = 0;
    int max = 0;
    for(int j = 0; j < N; j++){
        if(tab[j] < tab[min]) min = j;
        if(tab[j] > tab[max]) max = j;
    }
    static int score[2];
    score[0] = tab[min];
    score[1] = tab[max];
    return score;
}