#include <stdio.h>
#include <stdlib.h>
#define tam 7

void imprime(int vet[]){
    int i;
    for(i=0;i<tam;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

//void imprime(char vet[]){
//    int i;
//    printf("[");
//    for(i=0;i<tam;i++){
//        printf("%c ",vet[i]);
//    }
//    printf("]\n");
//}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

//void insertionSort(int vet[]){
//    int i,j, sentinela;
//    for(j=1;j<tam;j++){
//        sentinela = vet[j];
//        i=j-1;
//        while(vet[i]>sentinela&&(i>=0)){
//            vet[i+1]= vet[i];
//            i--;
//        }
//        vet[i+1]=sentinela;
//    }
//}

void selectionSort(int vet[]){
    int i,j;
    for(j=0;j<tam;j++){
        int min = j;//posicao do menor elemento do meu vetor
        for(i=j+1;i<tam;i++){
            if(vet[i]<vet[min]){
                min = i;
            }
        }
        troca(&vet[j],&vet[min]);
        imprime(vet);
    }
}

void bubbleSort(int vet[]){
    int i,j, mov=0,comp=0;
    for(i=0;i<tam;i++){
        for(j=i;j<tam;j++){
            comp++;
            if(vet[i]>vet[j]){
                mov++;
                troca(&vet[i],&vet[j]);
            }
        }
    }
    printf("Comparacoes:%d movimentos:%d\n",comp,mov);
}

void insertionSort(int vet[]){
    int i , j ,x;
    for ( i = 1; i < tam; i++){
            x = vet[ i ];
            j = i-1;
            //vet[0] = x ; /* sentinela */
            while (x < vet[ j ]&&j>=0){
                vet[ j +1] = vet[ j ];
                j--;
            }
            vet[ j +1] = x;
            imprime(vet);
    }
}




void imprimeQuick(int vet[], int esq,int dir){
    int i;
    printf("[");
     for(i=0;i<esq;i++){
        printf("- ",vet[i]);
    }
    for(i=esq;i<=dir;i++){
        printf("%d ",vet[i]);
    }
     for(i=dir+1;i<tam;i++){
        printf("- ",vet[i]);
    }
    printf("]\n");
}
void shellSort(int vet[], int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
                imprime(vet);
        }
    }
}
void Particao(int Esq, int Dir , int * i , int * j , int A[])
{
    int x , w;
    *i = Esq; *j = Dir;
    x = A[(*i + *j)/2]; /* obtem o pivo x */
    do
    {
        while (x > A[*i]) (*i)++;
        while (x < A[*j]) (*j)--;
        if(* i <= * j ){
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++; (*j)--;
            imprimeQuick(A,Esq,Dir);
        }
    } while (*i<= *j);
}
void Ordena(int Esq, int Dir , int A[])
{
    int i , j ;
    Particao(Esq, Dir , &i , &j , A) ;
    if (Esq < j ) Ordena(Esq, j , A) ;
    if ( i < Dir ) Ordena( i , Dir , A) ;
}
void QuickSort(int A[], int n)
{
    Ordena(0 , n-1, A) ;//n eh o numero de elementos do vetor
}

void siftDown( int vet[], int start, int end)
{
    int root = start,aux;

    while ( root*2+1 < end ) {
        int child = 2*root + 1;
        if ((child + 1 < end) && vet[child]<vet[child+1]) {
            child++;
        }
        if (vet[root]< vet[child]) {
            aux=vet[child];
            vet[child]=vet[root];
            vet[root]=aux;
            root = child;
        }
        else
            return;
    }
}

void heapsort( int vet[], int n)
{
    int start, end, aux;

    /* heapify */
    for (start = (n-2)/2; start >=0; start--) {
        siftDown( vet, start, n);
    }

    for (end=n-1; end > 0; end--) {
        aux=vet[end];
        vet[end]=vet[0];
        vet[0]=aux;
        siftDown(vet, 0, end);
    }
}

int main()
{
//    char vet[tam]={'s','a','m','u','e','l','b','z','x','y'};
//    int vet[tam]={0,1,2,3,4,5,6,7,8,9};
//    int vet[tam]={49,5,18,16,4,55,40,53};
   int vet[tam]={9,7,8,5,0,6,1};
    imprime(vet);
//    insertionSort(vet);
    QuickSort(vet,tam);
    imprime(vet);
//heapsort(vet,tam);
    return 0;
}
