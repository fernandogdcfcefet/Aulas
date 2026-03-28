// Exemplo de uma lista encadeada, compondo a tabela que tem vetores de ponteiros
#include<conio.h>// Inclui as bibliotecas 
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define tam 4 // Define o tamanho
// Vai existir uma celula e dentro dessa celula vai criar uma variavel do tipo celula que é o apontador. 
//Ponteiro do tipo celula, faz o prox apontar para outros elementos  
 typedef struct celula *apontador; // Cria um apontador

 typedef struct celula 
 {
	int chave; // Chave é o valor criado pela função hash para ir direto no código 
	apontador prox;// irá apontar para os objetos para que se possa percorrer a lista
 }celula;

 typedef struct tab
 {
	apontador primeiro, ultimo;// Cria o primeiro e o ultimo para definir os locais 
 }tab;

 int Funcao(int num) // Criação da chave para armazenamento dos valores de acordo com a Função Hash
 {
	return num % tam ;// Função hash 
 }

 void criarTabela(tab Tabela[])// Tem que criar a tabela para armazenar os valores, e vai inserir [] pois é um vetor de vetores
 {
	int i;// Criação do for para que seja criado espaços de memoria de acordo com o tamanho definido onde será inserido os valores, criando então a Tabela
	for(i=0;i<tam;i++) 
	{
		Tabela[i].primeiro=(apontador) malloc(sizeof(celula));// cria um espaço de memoria, Tabela aponta para o espaço criado
		Tabela[i].ultimo=Tabela[i].primeiro;// Faz o ultimo apontar para o primeiro, para iniciar com a tabela vazia sem lixo
		Tabela[i].ultimo->prox=NULL; // O último aponta para NULL, para demonstrar q a tabela para nesse instante e receba um NULL e não lixo de memória
	}	
 }
 void Insere(tab Tabela[])
 {
	int i,num,cod;
	for(i=0;i<tam;i++) // o usuário digitara a quantidade de espaços de memoria criado, obriga o usuário a digitar o tamanho definido, porém
	{	 //evita dele pedir a opção inserir toda vez que quiser digitar a quantidade de numeros que a tabela permite inserir . Então opcional 
		printf("\n Digite um numero a ser armazenado :\n");
		scanf("%d",&num);
		
		cod=Funcao(num);// o cod vai receber a chave definida pela função hash
		
		Tabela[cod].ultimo->prox=(apontador)malloc(sizeof(celula));// O ultimo vai apontar para o proximo onde vai ser criada um espaço de memoria
		Tabela[cod].ultimo=Tabela[cod].ultimo->prox;//o ultimo recebe o ultimo que aponta para o proximo que é a celula criada,então o ultimo vai ter uma celula vazia
		Tabela[cod].ultimo->chave=num;//O ultimo portanto aponta para a chave e recebe o numero digitado
		Tabela[cod].ultimo->prox=NULL; // O último aponta para o proximo,para demonstrar q a tabela para nesse instante e aponte para um NULL e não lixo de memória
	}
	system("cls");//Limpa a Tela
}

 void Mostrar(tab Tabela[])
 {
	int z, aux;
	printf("\n--------- TABELA ----------\n");
	
	for(z=0;z<tam;z++){
	   apontador aux=Tabela[z].primeiro->prox; // cria um aux pelo apontador, q recebe em ordem feita pelo for através da variavél z começando pelo 0
	   // e começa no primeiro da tabela e vai apontando para o próximo
	   while(aux!=NULL){ // Enquanto o aux for diferente de NULL o laço continua, quando for igual o lanço termina pois chegou o fim da lista
	   	     
	   	     printf(" %d ",aux->chave); // aux aponta para a chave onde está o número armazenado
	   	     
	   	     aux=aux->prox; // aux recebe o próximo do aux 
	   	     
       }
       printf("\n");
	}
    printf("\n");  
 }

 void Pesquisar(tab Tabela[])
 {
	int x, y , z=0 , aux;
	
	printf("\n Digite a cordenada X (0 < %d)\n",tam);
	scanf("%d",&x);
	
	printf("\n Digite a cordenada Y (0 < %d)\n",tam);
	scanf("%d",&y);
	system("cls"); //Limpa a Tela
	
	
	if(x>=0 && x<tam) // Busca o valor se estiver certo a coordenada
	{
	
     		apontador aux=Tabela[x].primeiro->prox; // cria um aux pelo apontador, q recebe em ordem feita pelo for através da variavél z começando pelo 0
	        // e começa no primeiro da tabela e vai apontando para o próximo
	        while(aux!=NULL){ // Enquanto o aux for diferente de NULL o laço continua, quando for igual o lanço termina pois chegou o fim da lista
	   	          
				  if(z==y)// se z for igual a coordenada y então imprimi o valor que está na chave
	   	            	printf(" %d ",aux->chave); // aux aponta para a chave onde está o número armazenado
	   	          
	   	          z++; // caso z não for igual a y então recebe +1 até o valor ser igual e imprimir o valor da chave correspondente	   	        
	   	          aux=aux->prox; // aux recebe o próximo do aux 
           }
	}   		
    else
	{
		printf("\n Coordenadas inválidas. \n Tente novamente. \n");
	}

 }

 void Remover(tab Tabela[])
 {
	int x, y ,z=0 ,i=-1;
	
	printf("\n Digite a cordenada X (0 < %d)\n",tam);
	scanf("%d",&x);
	
	printf("\n Digite a cordenada Y (0 < %d)\n",tam);
	scanf("%d",&y);
	system("cls"); //Limpa a Tela
	
	apontador aux = Tabela[x].primeiro;// cria uma variavel auxiliar que comecará apontando para a primeira posição da lista
	if(x>=0 && x<=tam){// Delimitação para que as coordenadas sejam entre 0 e tam
		  
				if(Tabela[x].primeiro==Tabela[x].ultimo){ // verificação se a tabela esta vazia
					   printf("\n ****Erro****  \n   Tabela vazia. \n\n");
					    
			    }
				else{// comandos para remover
		            while(i<(y-1)&&(aux->prox->prox!=NULL)){// i<(y-1) faz o aux ficar uma posição anterior , aux->prox->prox!=NULL quando o próximo do que pretende
		            // excluir for NULL então chegou a posição correta e acaba o laço
	                  aux=aux->prox;// percorre o proximo da lista do codigo até uma posição anterior a que deseja retirar
	                  i++; // incrementa o i para mudar a posição quando for igual ao (y-1)
	                }
	                   apontador z = aux->prox;// cria uma variavel z, que recebe o aux->prox, pois vai esta no elemento quee quer eliminar
	                   aux->prox = z->prox;// auxiliar passa a apontar para o elemento proximo ao de se deseja exluir, para que a lista desloque e não fique um espaço 
	                   // vazio entre duas celulas e ,assim, não gere o loop
	                   free(z);//exclui elemento
	
			    }
				    	
    }
	else
	{
		printf("\n Não existe essa coordenada. \n Tente novamente \n");		
	}				     
 }


 int main()
 {
	tab Tabela[tam]; //chama a variave tabela onde foi colocada a lista encadeada
	criarTabela(Tabela);//Chama a tabela
	
	int num[100],opc;
	
	printf("\n ---------- TABELA HASH ------------- \n\n");
    
    while(opc!=5){
    
	   printf("\nDigite um numero correspondente a opcao desejada\n\n1- Inserir\n\n2- Mostrar\n\n3- Pesquisar\n\n4- Remover \n\n5- Sair\n\n\n Digite uma opcao: ");
       fflush(stdin);
	   scanf("%d",&opc);
       system("cls");    
       
	   switch(opc){
        	case 1 :
    	    	Insere(Tabela);
    		    break;
    		
        	case 2 :
    	    	Mostrar(Tabela);
       		    break;
    		
    	    case 3 :
    		    Pesquisar(Tabela);
    		    break;
    		
    	    case 4 :
    		    Remover(Tabela);
    		    break;  		    
       }
    }
    printf("\n\n -----------Fim da Tabela Hash-------------------- \n\n");

	return 0;
 }
