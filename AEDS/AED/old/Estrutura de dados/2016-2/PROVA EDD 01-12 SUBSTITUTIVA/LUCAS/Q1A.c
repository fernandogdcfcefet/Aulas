#include <stdio.h>
#include <stdlib.h>


void Ordena ( int vet[],int n){
int i,j,aux;

for (i=0; i<n; i--){
    for (j=0;j<i;j++){
        if(vet[j]>vet[j+1]){
            vet[j+1]= aux;
            vet[j+1]= vet[j];
            aux = vet[j];

 }

 }
}

}



int main(){

         int vet[4] = {6,4,2,1};
         int n = 4;
         int i;
         Ordena(vet,n);
         for (i=0; i<n; i++){
                printf("%d", vet[i]);
         }


return 0;
}
