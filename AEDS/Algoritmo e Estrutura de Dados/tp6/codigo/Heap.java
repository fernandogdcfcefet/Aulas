public class Heap{	

	public static class Vertice{
		Object vertice;
		int custo;
		public Vertice(Object v, int custo){
			this.vertice = v;
			this.custo = custo;
		}
		public void setCusto(int custo){
			this.custo = custo;		
		}	
		public int getCusto(){
			return custo;		
		}
		public Object getVertice(){
			return vertice;		
		}
	}

	Vertice v[];
	int n;

	public Heap(int numVertices, int custo[]){
			n = numVertices;
			v = new Vertice[n];
			for (int i=0; i<n; i++){
				v[i] = new Vertice(i, custo[i]);			
			}
	}

	public void setCusto(Object vertice, int c){
		for(int i=0; i<n; i++){
			if(v[i].getVertice() == vertice)
				v[i].setCusto(c);		
		}
	}	

	public int retiraMin() {
        
		if(n == 0){
			return -1;		
		}

        troca(--n, 0);

        return Integer.parseInt(v[n].getVertice()+"");

    }

	public boolean vazio() {
		if(n == 0){
			return true;		
		}	
		return false;
	}

	public void constroiHeap() {
        for (int i = n / 2 - 1; i >= 0; i--)
            refaz(i, n);
    }

    private void refaz(int pos,int n) {
        int max = 2 * pos + 1, right = max + 1;
        if (max < n) {
            if (right < n && v[max].getCusto() > v[right].getCusto())
                max = right;
            if (v[max].getCusto() < v[pos].getCusto()) {
                troca(max, pos);
                refaz(max, n);
            }
        }
    }

    private void troca(int j, int aposJ) {
        Vertice aux = v[j];
        v[j] = v[aposJ];
        v[aposJ] = aux;
    }

}
