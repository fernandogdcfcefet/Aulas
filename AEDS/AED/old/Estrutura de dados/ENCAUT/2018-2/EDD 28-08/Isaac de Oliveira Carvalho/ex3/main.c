#include <stdio.h>
#include <stdlib.h>

int calculakn(int k, int n) {
    int a = k;
    if(n>1) {
            k = a*a;
            n = n-1;
            calculakn(k, n);
    } else {
        return k;
    }


}


int main()
{
    int k=2, n=2;
    printf("%d", calculakn(k, n));
    return 0;
}
