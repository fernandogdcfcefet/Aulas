#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define mat[V,A] 100
int ordenado( int mat[V,A]){
	int i,j;
	for(i=0;i<v;i++){
	for(j=i;j<A;j++){
     if(mat[i,j]==mat[j,i]){
     	return 1;
       printf("%d Grafo nao orientado");
	 }
		}
	}
	else{
	return 0;
	printf("%d grafo orientado");
	}
	
}



int main(){
	
}
