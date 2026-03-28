#include <stdio.h>

#define MAXTAM 9

typedef int TipoIndice;

typedef int TipoVetor;


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
	
	for(i=1; i<=n;i++)
	{
		printf("%d", A[i]);
		printf("\n");
	}
	//getch();
	//system("cls");
	
}

void desenha(TipoVetor vet[],TipoIndice n)
{ 
	int i;

	for(i=0;i<n;i++)
	{ 
		if(vet[i]==0)
		{
			printf("E	");
		}
		else if(vet[i]==1)
		{
			printf("H	");
		}
		else if(vet[i]==2)
		{
			printf("L	");
		}
		else if(vet[i]==3)
		{
			printf("O	");
		}
		else if(vet[i]==4)
		{
			printf("R	");
		}
		else if(vet[i]==5)
		{
			printf("S	");
		}
		else if(vet[i]==6)
		{
			printf("T	");
		}
		 
	} 
		 
	//sleep(300); 
	printf("\n");
	getchar();
	
} 

int main(int argc, char *argv[])
{ 
	TipoVetor B[9] = {5,1,0,2,2,5,3,4,6};
	//TipoVetor B[9] = {3,2,1,5,4,7,8,6,0};
    TipoIndice n = MAXTAM;
  
  
    printf("Desordenado : \n");
   	desenha(B,n);
   	
   	Shellsort(B,n);
   	printf("Shellsort final \n");
   	desenha(B,n);
   	
   	//Imprime(B,n);
  	//Shellsort(B, n);
  	//Imprime(B, n);


}
