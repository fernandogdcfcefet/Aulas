#include <stdio.h>
#include <stdlib.h>

int recursiva(int k1, int n1){
    int res,i=1;
    if(n1==0){
        return 1;
    }
    else if(n1==1){
        return k1;
    }
    else if(i<=n1){
        res=k1*(recursiva());
        return res;
    }
    i++;

}

int main()
{
    int k,n;
    printf("Digite o valor de k:");
    scanf("%d",&k);
    printf("Digite o valor de n:");
    scanf("%d",&n);

    printf("Valor: %d\n",recursiva(k,n));


    return 0;
}
