void sumOne(unsigned long long N)
{
    unsigned long long sum = 0;
    for (unsigned long long n = N; n > 0; n /= 2)
        for (unsigned long long i = 0; i < n; i++)
    sum++;
}