float Ex11A(float n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return Ex11A(n - 1) + (1/n)*(1/n);
}

int Ex11B(int n){
    if(n == 0) return 0;
    return Ex11B(n - 1) + n;
}

int Ex11C(int n){
    if(n == 0) return 0;
    return Ex11C(n - 1) + n * 2;
}

int Ex11D(int n){
    if(n == 0) return 0;
    return Ex11D(n - 1) + (n *(n + 1)*((2 * n) + 1))/6;
}