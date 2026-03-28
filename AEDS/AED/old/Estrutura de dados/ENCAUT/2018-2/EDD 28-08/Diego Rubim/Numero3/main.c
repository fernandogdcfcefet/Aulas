#include <stdio.h>
#include <stdlib.h>

int recursiva(int k, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        k = k*(recursiva(k,n));
    }
    return k;
}
int main()
{
    int k,n;
    printf("Digite 2 valores inteiros positivos:\n");
    scanf("%d",&k);
    scanf("%d",&n);
    recursiva(k,n);
    printf("%d",k);
    return 0;
}
