void change(int*, int, int);

void minusBubble(int* tab, int N){
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i; j < N - 1; j++)
        {
            if(tab[j] > tab[j-1])
            {
                change(tab, j, j-1);
            }
        }
    }
}
