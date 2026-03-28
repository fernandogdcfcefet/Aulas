#include <stdio.h>
#include <stdlib.h>


int exp(int k, int n){

    if(n == 1){
        return k;
    }

    return k * (exp(k,n-1));

}

int main()
{
    int k = 2,n = 3;

    printf("%d\n",exp(k,n));

    return 0;
}
