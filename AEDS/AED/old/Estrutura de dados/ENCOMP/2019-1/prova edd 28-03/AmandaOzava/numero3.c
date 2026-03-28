#include<stdio.h>
int elevado (int n, int k, int i, int total)
{
    if(n==1)
        return k;
    else if(i<n)
    {
       total=total*k;
       elevado(n,k,i+1,total);
    }
    else
    {
      return total;
    }

}
int main()
{
    int k, n;
    printf("Numero:");
    scanf("%d", &k);
    printf("Potencia:");
    scanf("%d", &n);
    printf("%d",elevado(n, k, 0, 1));
}
