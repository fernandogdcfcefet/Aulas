#include <stdio.h>
#include <stdlib.h>

int rec (int k, int n){
    if (n==1) return k;
    else return rec(k+k, n-1);

}
int main()
{
    int k, n;
    printf("Digite k: \n");
    scanf("%d", &k);
    printf("Digite n: \n");
    scanf("%d", &n);
    printf("%d\n", rec(k,n));
    return 0;
}
