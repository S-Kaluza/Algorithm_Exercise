bool bitonicSearch(int* tab, int N, int key){
    int L = 0;
    int R = N;
    int start1, end1, start2, end2;
    int mid = (L + R)/2;
    while(L != R){
        mid = (L + R)/2;
        if(tab[mid]>tab[mid-1] && tab[mid]>tab[mid+1]) break;
        else if(tab[mid-1] > tab[mid+1]) R = mid-1;
        else if(tab[mid-1] < tab[mid+1]) L = mid+1;
    }
    start1 = 0;
    end1 = mid-1;
    start2 = mid;
    end2 = N;

    while(start1 <= end1){
        mid = start1 + (end1 - start1)/2;
        if(tab[mid] == key) return true;
        else if(tab[mid] < key) start1 = mid + 1;
        else end1 = mid  - 1; 

    }

    while(start2 <= end2){
        mid = start2 + (end2 - start2)/2;
        if(tab[mid] == key) return true;
        else if(tab[mid] > key) start2 = mid + 1;
        else end2 = mid  - 1; 

    }
    return false;
}