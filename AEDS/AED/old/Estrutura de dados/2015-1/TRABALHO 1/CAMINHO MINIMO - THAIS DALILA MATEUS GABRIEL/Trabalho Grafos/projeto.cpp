// Programa de algoritmo de caminho de Dijkstra (a procura do caminho mais curto)
// Utilizamos no programa uma representação de matriz de adjacência.

#include <stdio.h>
#include <limits.h>
#define V 6 //número de vertices do grafo

// Utilizamos uma função para encontar o vértice com a menor distância (valor), a partir do
// conjunto de vértices ainda não inclusos no menor caminho
int minDistance(int dist[], bool sptSet[])
{
   // Inicia com valor mínimo
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}

// Função para imprimir a matriz de distância contruída
int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

// Função que implementa algoritmo de Dijkstra para um grafo representado, utilizando uma matriz de adjacência
void dijkstra(int graph[V][V], int src)
{
     int dist[V];     // Matriz de saída - dist[i] vai realizar o caminho mais curto
                      // distancia de src para i  
					    
     bool sptSet[V];  // sptSet[i] será verdadeiro se o vertice i estiver incluido no mais curto
                     // caminho ou menor distancia de src para i finalizar
 
     // Inicializar todas as distancias finitas e stpSet[] como falsa
	 for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    // Distancia do vertice fonte dele mesmo é sempre 0
     dist[src] = 0;
 
    // Encontra o caminho mais curto para todos os vertices
	 for (int count = 0; count < V-1; count++)
     {
       // Escolhe o vértice de menor distância do conjunto de vértices ainda não processados
       // u é sempre igual aos src na primeira iteração
       int u = minDistance(dist, sptSet);
 
       // Marca o vertice escolhido como processado
	   sptSet[u] = true;
 
       // Atualize o valor da distancia dos vertices adjacentes do vertice escolhido
	   for (int v = 0; v < V; v++)
	   
	   	 // Atualiza dist[v] somente se não estiver em sptSet, existe uma aresta 
         // de u para v, e peso total de caminho de src para v através de u é menor do que
         // o valor atual da dist [v] 
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
	 //Imprime a matriz construída
     printSolution(dist, V);
}
 
//Programa para testar a função acima 
int main()
{
    //Criação do nosso grafo
   int graph[V][V] = {{0, 3, 999, 6, 999, 4},
                      {3, 0, 5, 999, 999, 999},
                      {999, 5, 0, 7, 1, 999},
                      {6, 999, 7, 0, 2, 999},
                      {10, 999, 1, 2, 0, 7},
                      {4, 999, 999, 999, 7, 0},
                     };
 
    dijkstra(graph, 0);
 
    return 0;
}
