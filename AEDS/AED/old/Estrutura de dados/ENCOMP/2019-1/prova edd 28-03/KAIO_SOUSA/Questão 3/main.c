#include <stdio.h>
#include <stdlib.h>
int exponencial(int n,int k)
{
    int i,aux;
    aux=k;
    i=1;
    do
    {
        k=(k*aux);
        i++;
    }while(i<n);

    return k;
}
int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    exponencial(n,k);
    printf("%d\n",exponencial(n,k));
    return 0;
}
