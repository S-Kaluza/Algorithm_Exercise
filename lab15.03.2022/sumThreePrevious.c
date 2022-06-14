void sumThree(unsigned long long N)
{
    int ile = 0;
    int sum = 0;
    clock_t start = clock();
    clock_t stop = clock();
    float a_time;
    FILE *fp;
    fp = fopen("/mnt/c/Users/szymo/Desktop/Algorytmy/lab15.03.2022/zadanie4.txt", "w");
    while(ile < 25){
        start = clock();
        unsigned long long sum = 0;
        for (int i = 1; i < N; i *= 2)
        for(int j = 0; j < N; j++)
            sum++;
            ile++;
        a_time = (float)((clock() - start))/CLOCKS_PER_SEC;
        fprintf(fp ,"%f\n", a_time);
    }
    fclose(fp);
}