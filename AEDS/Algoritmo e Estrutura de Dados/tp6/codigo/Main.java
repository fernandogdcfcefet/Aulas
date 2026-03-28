public class Main{
	
	static String mascara = "inteiros";

	public static void JAEDsMAPs(JGrafo grafo, int inicio, int fim){
		int tam = grafo.getTamanho();		
		int p[] = new int[tam];
		int antecessor[] = new int[tam];
		int S[] = new int[tam];
		int infinito = 0;
		for(int i=0; i<tam; i++)
			for(int j=0; j<tam; j++)
				infinito += grafo.getPeso(i,j);
		infinito ++;		
		for (int i=0; i<tam; i++){
			p[i] = infinito;
			antecessor[i] = -1;
		}
		p[inicio] = 0;
		Heap heap = new Heap(tam, p);
		heap.constroiHeap();
		int tamS = 0;
		while(!heap.vazio()){
			int u = heap.retiraMin();
			S[tamS++] = u;
			int v = grafo.primeiroListaAdj(u);
			if(v != -1){
				if(p[v] > p[u] + grafo.getPeso(u,v)){
					p[v] = p[u] + grafo.getPeso(u,v);
					heap.setCusto(v, p[v]);
					antecessor[v] = u;
				}
				v = grafo.proxAdj(u);			
			}
			while(v != -1){
				if(p[v] > p[u] + grafo.getPeso(u,v)){
					p[v] = p[u] + grafo.getPeso(u,v);
					heap.setCusto(v, p[v]);
					antecessor[v] = u;
				}
				v = grafo.proxAdj(u);
			}
			heap.constroiHeap();
		}
		System.out.print("Caminho: ");
		caminho(antecessor, fim, fim);
		System.out.println("\nCusto: " + p[fim]);
	} 

	public static void caminho(int antecessor[], int v, int fim){
		String c = "";
		String letra[] = new String[5];
		letra[0] = "a";
		letra[1] = "b";
		letra[2] = "c";
		letra[3] = "d";
		letra[4] = "e";
		if(mascara.equals("inteiros"))
			c = (v+1)+"";
		else if(mascara.equals("letras"))
			c = letra[v];	
		if(antecessor[v] == -1){
			System.out.print(c);
			if(v != fim)
				System.out.print(" - ");
		}
		else{
			caminho(antecessor, antecessor[v], fim);
			System.out.print(c);
			if(v != fim)
				System.out.print(" - ");		
		}
	}

	public static void main(String args[]){
		System.out.println("---------Grafo1---------");
		JGrafo grafo = new JGrafo(5);
		grafo.insereAresta(0,1,8);
		grafo.insereAresta(0,2,4);
		grafo.insereAresta(0,3,5);
		grafo.insereAresta(1,4,9);
		grafo.insereAresta(2,3,1);
		grafo.insereAresta(2,4,5);
		grafo.insereAresta(3,1,3);
		grafo.insereAresta(3,2,5);
		grafo.insereAresta(3,4,2);
		JAEDsMAPs(grafo, 0, 4);
		System.out.println("---------Grafo2---------");
		mascara = "letras";
		grafo = new JGrafo(5);
		grafo.insereAresta(0,1,3);
		grafo.insereAresta(0,3,5);
		grafo.insereAresta(1,2,2);
		grafo.insereAresta(1,3,2);
		grafo.insereAresta(2,4,2);
		grafo.insereAresta(3,1,3);
		grafo.insereAresta(3,2,5);
		grafo.insereAresta(3,4,9);
		grafo.insereAresta(4,0,6);
		grafo.insereAresta(4,2,4);
		JAEDsMAPs(grafo, 3, 0);
	}

}
