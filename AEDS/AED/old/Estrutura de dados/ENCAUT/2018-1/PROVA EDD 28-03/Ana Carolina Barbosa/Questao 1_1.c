#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int funcao(int mat[6][6]){
	int m = (mat[0][5]);
	int i = 0;
	for( i = 0;i<6;i++){
		if(m>mat[i][5-i]){
			m=mat[i][5-i];			
		}
	}
	return m;
}



int main(){
    int mat[6][6]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
    int m = funcao(mat);
    printf("Menor elemento: %d \n",m);

return 0;
}
