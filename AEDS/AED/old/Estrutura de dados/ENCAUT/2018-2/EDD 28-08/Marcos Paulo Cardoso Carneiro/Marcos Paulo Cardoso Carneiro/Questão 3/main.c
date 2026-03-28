#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void expoente(int *k,int *n){
    int i;
        for ( i = 0; i < n; i++){
            *k = (*k) * k;
        }

}
int main()
{
    int result,k,n;

    printf("informe o valor de k");
    scanf("%d", &k);
    printf("informe o valor de n");
    scanf("%d", &n);
    result = expoente(&k,&n);
    printf("%d", k);

    getch();
    return 0;
}
