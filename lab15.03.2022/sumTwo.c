void sumTwo(unsigned long long N)
{
    unsigned long long sum = 0;
    for (int i = 1; i < N; i *= 2)
    for(int j = 0; j < i; j++)
        sum++;
}