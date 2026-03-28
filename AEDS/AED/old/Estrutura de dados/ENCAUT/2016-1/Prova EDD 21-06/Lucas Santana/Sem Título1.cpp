#include <stdio.h>
#define n 10
int funcao(int mat[n][n]){
	int i, j,c=-1;
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			if!(mat[i][j]=mat[j][i]) {
				c=1;
			}			
		}
	}
}
int main(){
	
	int mat[n][n],c;
	c=funcao(mat);
	
	if(c==1) printf("Grafo não orientado");
	else printf("Grafo orientado");
	
	
	
}
