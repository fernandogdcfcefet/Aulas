#include <stdio.h>

int potencia(int k, int n);

int main(){
    printf("%d", potencia(2,2));
    return 0;
}

int potencia(int k, int n){
    int r,e;
    if(n == 1){
        k = k;
    }else if(n == 0 || k == 1){
        k = 1;
    }else{
        for(e = 1 < e <= n;e++){
          k = k * potencia(k,e)
        }
    }

    return k;
}
