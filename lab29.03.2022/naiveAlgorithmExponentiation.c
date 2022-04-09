int naiveExponentiation(int a, int n){
    int score = a;
    for(int j = 1; j < n; j++){
        score *= a;
    }
    return score;
}