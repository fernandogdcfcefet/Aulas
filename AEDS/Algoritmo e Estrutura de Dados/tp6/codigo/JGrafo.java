public class JGrafo{

	public class Aresta{
		private int v1, v2, peso;
		public Aresta(int v1, int v2, int peso){
			this.v1 = v1;
			this.v2 = v2;
			this.peso = peso;		
		}
		public int peso(){
			return peso;		
		}	
		public int v1(){
			return v1;		
		}
		public int v2(){
			return v2;		
		}
	}

	private int mat[][];
	private int numVertices;
	private int pos[];
	
	public JGrafo(int numVertices){
		mat = new int[numVertices][numVertices];
		pos = new int[numVertices];
		this.numVertices = numVertices;
		for (int i=0; i<numVertices; i++){
			for (int j=0; j<numVertices; j++)
				mat[i][j] = 0;
			pos[i] = -1;		
		}
	}

	public int getPeso(int v1, int v2){
		return mat[v1][v2];	
	}

	public int getTamanho(){
		return mat.length;	
	}

	public void insereAresta(int v1, int v2, int peso){
		mat[v1][v2] = peso;
	}

	public boolean existeAresta(int v1, int v2){
		return (mat[v1][v2] > 0);
	}

	public int primeiroListaAdj(int v){
		pos[v] = -1;
		return proxAdj(v);
	}

	public int proxAdj(int v){
		pos[v] ++;
		while((pos[v] < numVertices) && (mat[v][pos[v]] == 0))
			pos[v] ++;
		if(pos[v] == numVertices)
			return -1;
		else
			return pos[v];			
	}

	public Aresta retiraAresta(int v1, int v2){
		if(mat[v1][v2] == 0)
			return null;
		else{
			Aresta aresta = new Aresta(v1,v2,mat[v1][v2]);
			mat[v1][v2] = 0;
			return aresta;		
		}
	}

	public void imprime(){
		System.out.print("	");
		for(int i=0; i<numVertices; i++){
			System.out.print(i + "	");		
		}
		System.out.println();
		for(int i=0; i<numVertices; i++){
			System.out.print(i + "	");	
			for(int j=0; j<numVertices; j++){
				System.out.print(mat[i][j] + "	");			
			}	
			System.out.println();
		}	
	}

}
