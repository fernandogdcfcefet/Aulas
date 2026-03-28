#include <stdio.h>
#include <stdlib.h>

#define Vertice int
#define maxV 1000

/* A lista de adjacência de um vértice v é composta por nós do tipo no.
Cada nó da lista corresponde a um arco e contém um vizinho w de v e o endereço do nó seguinte da lista.
Um link é um ponteiro para um no. */
typedef struct no *link;
struct no { 
   Vertice w; 
   int custo; 
   link proximo; 
};

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A estrutura digrafo representa um digrafo.
O campo adj é um ponteiro para o vetor de listas de adjacência,
o campo V contém o número de vértices e o campo A contém o número de arcos. */
struct digrafo {
   int V; 
   int A; 
   link *adj; 
};

/* Um objeto do tipo Digrafo contém o endereço de um digrafo. */
typedef struct digrafo *Digrafo;


/* A função NOVOno recebe um vértice w e o endereço proximo de um nó
e devolve o endereço a de um novo nó tal que a->w == w e a->proximo == proximo. */
link NOVOno( Vertice w, int custo, link proximo) { 
   link a = malloc( sizeof (struct no));
   a->w = w; 
   a->custo = custo;
   a->proximo = proximo;     
   return a;                         
}


/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA:
A função DIGRAFOini devolve (o endereço de) um novo digrafo com vértices 0 1 ... V-1 e nenhum arco. */
Digrafo DIGRAFOini( int V) { 
   Vertice v;
   Digrafo G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (v = 0; v < V; v++) 
      G->adj[v] = NULL;
   return G;
}

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função DIGRAFOinsereA insere um arco v-w com custo positivo no digrafo G.
A função supõe que v e w são distintos, positivos, e menores que G->V.
Se o digrafo já tem arco v-w, a função não faz nada. */
void DIGRAFOinsereA( Digrafo G, Vertice v, Vertice w, int custo) { 
   link a;
   for (a = G->adj[v]; a != NULL; a = a->proximo) 
      if (a->w == w) return;
   G->adj[v] = NOVOno( w, custo, G->adj[v]);
   G->A++;
}

/* REPRESENTAÇÃO POR LISTA DE ADJACÊNCIA: 
Para cada vértice v do digrafo G, esta função imprime, em uma linha, todos os vértices adjacentes a v. */
void DIGRAFOmostra( Digrafo G) { 
   link a;
   Vertice v, w; 
   for (v = 0; v < G->V; v++) {
	   printf( "%2d:", v);
	   for (a = G->adj[v]; a != NULL; a = a->proximo) {
	   		printf( " %2d(%d)",a->w,a->custo);
	   }
	   printf( "\n");
   }
}

const int INFINITO = maxV;

/* Inicializa os vetores pai, dist e frj de modo que a primeira iteração de DIGRAFOsptD
comece de um só vértice, s. */
void inicializa( Digrafo G, Vertice s, Vertice pai[], 
                 int dist[], Vertice frj[]) 
{ 
   Vertice w; link a; int c;
   for (w = 0; w < G->V; w++) {
      pai[w] = -1;
      dist[w] = INFINITO;
   }
   pai[s] = s;
   dist[s] = 0;
   for (a = G->adj[s]; a != NULL; a = a->proximo) {
      w = a->w, c = a->custo;
      dist[w] = c; 
      frj[w] = s; 
   } 
}

/* Recebe digrafo G com custos positivos nos arcos e um vértice s.
Calcula uma SPT com raiz s e armazena a SPT no vetor pai. 
As distâncias a partir de s são armazenadas no vetor dist. */

/* O digrafo é representado por suas listas de adjacência. 
A função supõe que a soma dos custos de todos os arcos é estritamente menor que a constante INFINITO.
Supõe também que o digrafo tem no máximo maxV vértices.  
(O código abaixo é uma versão modificada do Programa 20.3 de Sedgewick) */
void DIGRAFOsptD( Digrafo G, Vertice s, Vertice t, Vertice pai[],
                   int dist[]) 
{ 
   Vertice v0, w, frj[maxV];
   link a; int c;
   inicializa( G, s, pai, dist, frj);

   while (1) {
      int mindist = INFINITO;
      for (w = 0; w < G->V; w++) 
         if (pai[w] == -1 && mindist > dist[w])
            mindist = dist[v0=w]; 
      if (mindist == INFINITO) break;
      pai[v0] = frj[v0];
      for (a = G->adj[v0]; a != NULL; a = a->proximo) {
         w = a->w, c = a->custo;
         if (pai[w] == -1 && dist[w] > dist[v0] + c) { 
            dist[w] = dist[v0] + c; 
            frj[w] = v0; 
         } 
      }
   }
   
   
   printf("\n\n\tO tamanho do caminho minimo de %i ate %i e de:", s, t);
   printf("\n\t>>");
   printf(" %d", dist[t]); //imprime a distancia minima ate o vertice desejado.
}

static int lbl[maxV];
/* Digamos que um vértice u está marcado se lbl[u] vale 1. 
A função dfsMaxSimplePath recebe um conjunto de vértices marcados e vértices v e t não marcados.
Devolve o custo de um caminho simples de v a t que tem custo máximo dentre todos os caminhos de v a t que não têm vértices marcados.
Se não existe caminho algum de v a t que não têm vértices marcados, devolve -1.
A função não altera o conjunto de vértice marcados. */

int dfsMaxSimplePath( Digrafo G, Vertice v, Vertice t)
{
   link a; 
   int maxv = -1;
   if (v == t) 
      return 0;
   lbl[v] = 1;
   for (a = G->adj[v]; a != NULL; a = a->proximo) {
      if (lbl[a->w] == 0) {
         int maxw = dfsMaxSimplePath( G, a->w, t);
         if (maxw != -1 && maxv < a->custo + maxw) 
            maxv = a->custo + maxw;
      }
   }
   lbl[v] = 0; /* atenção! */
   return maxv;
}

/* Recebe um digrafo G com custos positivos nos arcos e vértices s e t. 
Devolve o custo de um caminho simples máximo de s a t. Se não existe caminho algum de s a t, devolve -1
(que seria o nosso infinito negativo). (Esta função é eficiente para digrafos pequenos).*/

int DIGRAFOmaxSimplePath( Digrafo G, Vertice s, Vertice t)
{
   Vertice v;
   for (v = 0; v < G->V; ++v) lbl[v] = 0;
   return dfsMaxSimplePath( G, s, t);
}


//automatiza as funções
int main(){
	
	static Vertice pai[maxV];
	static int dist[maxV];
	
	FILE *arq = fopen("grafo.txt", "r");
	
	int numVertices = 0, ori = 0, dest = 0, custo = 0;
	
	if(arq != NULL)
  	{
  		printf("\n\tArquivo foi aberto com sucesso. \n\n");
    	fscanf(arq,"%d ", &numVertices);
		Digrafo grafo = DIGRAFOini(numVertices);
    	
        
		while( (fscanf(arq,"%d %d %d\n", &ori, &dest, &custo))!=EOF ){ //EOF - end of file (final do arquivo)
			DIGRAFOinsereA(grafo, ori, dest, custo);
		}
		DIGRAFOmostra(grafo);
		
		printf("\n\tDigite o vertice de origem:");
		scanf("%d",&ori);
		printf("\n\tDigite o vertice de destino:");
		scanf("%d",&dest);
		
		DIGRAFOsptD(grafo, ori, dest, pai, dist);
		
		int max = DIGRAFOmaxSimplePath(grafo, ori, dest);
		printf("\n\n\tO tamanho do caminho maximo de %i ate %i e de:", ori, dest);
	    printf("\n\t>>");
	    printf(" %d", max);
		
	}else{
        printf("\nNao foi possivel abrir o arquivo. \n");
    }
	getch();
	return 0;
}
