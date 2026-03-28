#include <stdio.h>
#include <stdlib.h>

int menor (int m[6][6]){
	
	int i,j,cont=0,cont2=5,menor[6]={0},menos;
	
	menos=m[0][5];
	
	while(cont<6){
		menor[cont]=m[cont][cont2];
	    cont++;
		cont2--;		
	}

	for(cont=0;cont<6;cont++){
		if(menos<menor[cont-1]){
			menos=menor[cont];
		}
	}
}


int main(){
	
	int i,j;
	
	int m[6][6]={1,0,2,3,5,7,
	            0,-5,2,1,-1,-3,
				0,-4,7,3,3,4,
				1,0,2,3,5,7,
	            0,-5,2,1,-1,-3,
				0,-4,7,3,3,4};
	
	printf("Menor %d\n\n", menor (m));
	
	
	system("pause");
	return 0;
}
