#include <stdio.h>

#define MAXTAM 10

typedef int TipoIndice;

typedef int TipoVetor;

char c[] = {'*','-','>','?',1,2,3,4,5,6};

void Shellsort(TipoVetor *A, TipoIndice n)
{ 
	int i, j;  
	int h = 1;
  	TipoVetor x;
  	
  	while(h<n)
	{
	  
	  	h = h * 3 + 1; 
	  
	}
	
  	while(h>1)
    { 
		h /= 3;
      	for (i = h; i < n; i++) 
        { 
			x = A[i];  
			j = i -h;
          	while (j>=0 && x<A[j]) 
            { 
				A[j+h] = A[j];  
				j = j - h;
              	
              	desenha(A,n);
            }
            
            A[j+h] = x;
            desenha(A,n);
        }
        
		
        
    }
}


Imprime (TipoVetor *A, TipoIndice n)
{
	int i,j;
	
	for(i=0; i<n;i++)
	{
		printf("%d", A[i]);
		printf("\n");
	}
}

void desenha(TipoVetor vet[],TipoIndice n)
{ 
	int i,j; 
	system("cls"); 
	for(i=0;i<n;i++)
	{ 
		switch (vet[i])
		{ 
			case 1: 
				printf("%d\t",vet[i]); 
			break; 
			case 2: 
				printf("%d\t",vet[i]); 
			break; 
			case 3: 
				printf("%d\t",vet[i]); 
			break; 
			case 4: 
				printf("%d\t",vet[i]); 
			break; 
			case 5: 
				printf("%d\t",vet[i]); 
			break; 
			case 6:
				printf("%d\t",vet[i]); 
			break; 
			case 7: 
				printf("%d\t",vet[i]); 
			break; 
			case 8: 
				printf("%d\t",vet[i]); 
			break; 
			case 9: 
				printf("%d\t",vet[i]); 
			break; 
			case 10: 
				printf("%d\t",vet[i]); 
			break; 
		} 
		
		for(j=0;j<vet[i];j++)
		{ 
			switch (vet[i])
			{ 
			case 1: 
				printf("%c",c[0]); 
			break; 
			case 2: 
				printf("%c",c[1]); 
			break; 
			case 3: 
				printf("%c",c[2]); 
			break; 
			case 4: 
				printf("%c",c[3]); 
			break;
			case 5: 
				printf("%c",c[4]); 
			break; 
			case 6: 
				printf("%c",c[5]); 
			break; 
			case 7: 
				printf("%c",c[6]); 
			break; 
			case 8: 
				printf("%c",c[7]); 
			break; 
			case 9: 
				printf("%c",c[8]); 
			break; 
			case 10: 
				printf("%c",c[9]); 
			break; 
			} 
		}
		
		 printf("\n"); 
	} 
		 
	//sleep(300); 
		 
	getchar(); 
} 

int main(int argc, char *argv[])
{ 
	TipoVetor B[10] = {3,10,9,1,7,6,5,4,8,2};
    TipoIndice n = 10;
  
  
    printf("Desordenado : \n");
   	Imprime(B,n);
   
   	getch();
   	system("cls");
   	
   	Shellsort(B,n);
   	printf("Shellsort \n");
   	Imprime(B,n);
   	
   	system("cls");
   	desenha(B,n);
  	//Shellsort(B, n);
  	//Imprime(B, n);


}
