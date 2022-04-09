long divideAndConquerExponentiation(long a, int n){
    long temp;
    if(n == 0){
        return 1;
    }
    else{
        if(n % 2 == 0){
            temp = divideAndConquerExponentiation(a, n/2);
            return temp * temp;
        }
        else{
            temp = divideAndConquerExponentiation(a, (n-1)/2);
            return temp * temp * a;
        }
    }
}