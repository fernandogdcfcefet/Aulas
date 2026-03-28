#include <stdio.h>
#include <stdlib.h>

void potencia(int k, int n){
    int total;
    if(n == 1){
        printf("%d", k);
    }
    else{
        total = pow(k,n);
        printf("%d", total);
    }
}

int main()
{
    potencia(2,3);

}
