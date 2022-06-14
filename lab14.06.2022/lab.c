#include<stdio.h>
#include<stdlib.h>
#include<regex.h>

void greedGiveMoney(int);
void dynamicGiveMoney(int*, int, int, int*);


int main(){
    //printf("Hello world");
    //greedGiveMoney(387);
    int c[6] = { 1,3,4,10,30,40 };
    int n =6;
    int r =56;
    int k[6] = { 0 };
    int sumM = 0;
    dynamicGiveMoney(c, n, r, k);
    for(int i = 0; i < 6; ++i){
        if(k[i]){
            printf("%d X %dzł\n", k[i], c[i]);
            sumM += k[i];
        }
    }
    printf("liczba potrzebnych monet wynosi: %d", sumM);

    
}

void greedGiveMoney(int amount){
    const int mon1 = 1;
    const int mon2 = 2;
    const int mon3 = 5;
    const int mon4 = 10;
    const int mon5 = 20;
    const int mon6 = 50;
    const int mon7 = 100;
    const int mon8 = 200;
    const int mon9 = 500;
    int temp;

    while(amount > 0){
        if(mon9 <= amount){
            temp = (amount - (amount % mon9))/amount;
            for(int i = 0; i <= temp; i++){
                printf("%d + ", mon9);
            }
            amount = amount % mon9;
        }
        
        if(mon8 <= amount){
            temp = (amount - (amount % mon9))/amount;
            for(int i = 0; i <= temp; i++){
                printf("%d + ", mon8);
            }
            amount = amount % mon8;
        }

        if(mon7 <= amount){
            temp = (amount - (amount % mon7))/amount;
            for(int i = 0; i <= temp; i++){
                printf("%d + ", mon7);
            }
            amount = amount % mon7;
        }

        if(mon6 <= amount){
            temp = (amount - (amount % mon6))/amount;
            for(int i = 0; i <= temp; i++){
                printf("%d + ", mon6);
            }
            amount = amount % mon6;
        }

        if(mon5 <= amount){
            temp = (amount - (amount % mon5))/amount;
            for(int i = 0; i <= temp; i++){
                printf("%d + ", mon5);
            }
            amount = amount % mon5;
        }

        if(mon4 <= amount){
            temp = (amount - (amount % mon4))/amount;
            for(int i = 0; i <= temp; i++){
                printf("%d + ", mon4);
            }
            amount = amount % mon4;
        }

        if(mon3 <= amount){
            temp = (amount - (amount % mon3))/amount;
            for(int i = 0; i <= temp; i++){
                printf("%d + ", mon3);
            }
            amount = amount % mon3;
        }

        if(mon2 <= amount){
            temp = (amount - (amount % mon2))/amount;
            for(int i = 0; i <= temp; i++){
                printf("%d + ", mon2);
            }
            amount = amount % mon2;
        }

        if(mon1 <= amount){
            temp = (amount - (amount % mon1))/amount;
            for(int i = 0; i <= temp; i++){
                printf("%d + ", mon1);
            }
            amount = amount % mon1;
        }
    }

}

void dynamicGiveMoney(int* c, int n, int r, int* k){
    int* o = (int*) malloc(r * sizeof(int));
    int* s = (int*) malloc(r * sizeof(int));

	int i, j; // Liczniki

	// Wypełnianie tabel
	for (j = 0; j < n; ++j) {

		for (i = 0; i < r; ++i) {

			if (j == 0) {

				// Rozważamy jednoelementowy zbiór nominałów - jest tylko jedna możliwość wydania kwoty
				o[i] = i + 1;
				s[i] = 0;

			}
			else if ((i + 1) == c[j]) {

				// Kwota "i" jest równa nominałowi o indeksie "j"
				o[i] = 1;
				s[i] = j;

			}
			else if ( ((i + 1) > c[j]) && (o[i] > o[i-c[j]] ) ) {

				// Należy użyć nominału o indeksie "j"
				o[i] = o[i - c[j]] + 1;
				s[i] = j; 

			} // W pozostałym przypadku pozostawiamy stare wartości o[i] i s[i]
			
		}
	}

	// Wyzerowanie tablicy k[]
	for (j = 0; j < n; ++j) {
		k[j] = 0;
	}

	// Zwiększanie wartości k na podstawie tablicy s
	while (r > 0) {
		k[s[r-1]] += 1;
		r -= c[s[r-1]];
	}

	// Zwolnienie pamięci
	free(o);
    free(s);

}