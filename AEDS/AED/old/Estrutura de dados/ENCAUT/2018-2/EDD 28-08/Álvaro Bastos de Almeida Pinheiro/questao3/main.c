#include <stdio.h>
#include <stdlib.h>

int recur(int k,int n){
    if(n>0){return k*recur(k,n-1);}
    else{
        return 1;
    }
}

int main()
{
    printf("%d",recur(2,5));
}
