#include <stdio.h>
#include <stdlib.h>

int recur(int k, int n)
{

    if((k>0) && (n>0))
    {
        return recur(k,(n*(k*k)));
    }

}



int main()
{
    int k=3,n=2,result;

    result=recur(k,n);

    printf("%d",result);

    return 0;
}
