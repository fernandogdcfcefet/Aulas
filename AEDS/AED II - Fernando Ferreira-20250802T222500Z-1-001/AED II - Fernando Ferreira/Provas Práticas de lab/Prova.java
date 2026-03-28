public class Prova {

	/*
	 * Classe  Fila
	 */
	public static class Fila {
		private static class Celula {
			Object item;
			Celula prox;
		}

		private Celula frente;
		private Celula tras;

		public Fila() {
			this.frente = new Celula();
			this.tras = this.frente;
			this.frente.prox = null;
		}

		public void enfileira(Object x) {
			this.tras.prox = new Celula();
			this.tras = this.tras.prox;
			this.tras.item = x;
			this.tras.prox = null;
		}

		public Object desenfileira() throws Exception {
			Object item = null;
			if (this.vazia())
				throw new Exception("Erro: A fila esta vazia");
			this.frente = this.frente.prox;
			item = this.frente.item;
			return item;
		}

		public boolean vazia() {
			return (this.frente == this.tras);
		}

		public void imprime() {
			Celula aux;
			aux = this.frente.prox;
			while (aux != null) {
				System.out.print(" " + aux.item.toString());
				aux = aux.prox;
			}
			System.out.println();
		}
	}
	
	
	/*
	 * Classe  Pilha
	 */
	public static class Pilha {
		private static class Celula {
			Object item;
			Celula prox;
		}

		private Celula topo;
		private int tam;

		public Pilha() {
			this.topo = null;
			this.tam = 0;
		}

		public void empilha(Object x) {
			Celula aux = this.topo;
			this.topo = new Celula();
			this.topo.item = x;
			this.topo.prox = aux;
			this.tam++;
		}

		public Object desempilha() throws Exception {
			if (this.vazia())
				throw new Exception("Erro: A pilha esta vazia");
			Object item = this.topo.item;
			this.topo = this.topo.prox;
			this.tam--;
			return item;
		}

		public boolean vazia() {
			return (this.topo == null);
		}

		public int tamanho() {
			return this.tam;
		}

		public void imprime() {
			Celula aux;
			aux = this.topo;
			while (aux != null) {
				System.out.print(" " + aux.item.toString());
				aux = aux.prox;
			}
			System.out.println();
		}
	}

	/*
	 * Classe àrvore Binária
	 */
	public static class ArvoreBinaria {
		private static class No {
			int reg;
			No esq, dir;
		}

		private No raiz;
		private int folhas;

		private No insere(int reg, No p) {
			if (p == null) {
				p = new No();
				p.reg = reg;
				p.esq = null;
				p.dir = null;
			} else if (reg < p.reg)
				p.esq = insere(reg, p.esq);
			else if (reg > p.reg)
				p.dir = insere(reg, p.dir);
			else
				System.out.println("Erro: Registro ja existente");
			return p;
		}

		public ArvoreBinaria() {
			this.raiz = null;
			this.folhas = 0;
		}

		public void insere(int reg) {
			this.raiz = this.insere(reg, this.raiz);
		}

		public int q1() {
			return this.q1(this.raiz);
		}

		/******************************************************
		 * 
		 * Q1 : Implemente aqui a resposta da questão 1. Não altere a declaração do
		 * método.
		 * 
		 ******************************************************/
		private int q1(No raiz) {

			return -1;
		}

		
		public void q2() {
			this.q2(this.raiz);
		}

		/******************************************************
		 * 
		 * Q2 : Implemente aqui a resposta da questão 2. Não altere a declaração do
		 * método.
		 * 
		 ******************************************************/
		private void q2(No raiz) {

		}
	}		
	
	/******************************************************
	 * 
	 * Q3 : Implemente aqui a resposta da questão 3. Não altere a declaração dos
	 * métodos.
	 * 
	 ******************************************************/	
	public static Fila q3 (Fila f) {
		
		return null;
	}
	
	/******************************************************
	 * 
	 * Q4 : Implemente aqui a resposta da questão 3. Não altere a declaração dos
	 * métodos.
	 * 
	 ******************************************************/
	public static Pilha q4 (Pilha p1, Pilha p2) {
		
		return null;
	}	
	
	private static void q5(int v[], int inicio, int meio, int fim) {
		int n1, n2, i, j, k;
		n1 = meio - inicio + 1;
		n2 = fim - meio;

		int A1[] = new int[n1 + 1];
		int A2[] = new int[n2 + 1];

		for (i = 0; i < n1; i++)
			A1[i] = v[inicio + i];
		for (j = 0; j < n2; j++)
			A2[j] = v[meio + j + 1];

		A1[i] = Integer.MAX_VALUE;
		A2[j] = Integer.MAX_VALUE;

		i = 0;
		j = 0;

		for (k = inicio; k <= fim; k++) {
			if (A1[i] <= A2[j])
				v[k] = A1[i++];
			else
				v[k] = A2[j++];
		}
	}
	
	/******************************************************
	 * 
	 * Q5 : Implemente aqui a resposta da questão 3. Não altere a declaração dos
	 * métodos.
	 * 
	 ******************************************************/
	public static void q5(int v[], int inicio, int fim) {
		
	}

	public static void teste() {

		ArvoreBinaria arvore = new ArvoreBinaria();

		arvore.insere(3); 
		arvore.insere(2); 
		arvore.insere(5);
		arvore.insere(4); 
		arvore.insere(7);
		arvore.insere(6); 
		arvore.insere(8); 

		/*
		 * Teste q1
		 */

		System.out.println("Resposta q1: " + arvore.q1()); 

		/*
		 * Teste q2
		 */

		System.out.println("Resposta q2"); 
		arvore.q2();

		/*
		 * Teste q3
		 */
		
		Fila f = new Fila();
		
		for (int i = 1; i <= 7; i++)
			f.enfileira(i);
		
		Fila q = q3(f);
		
		System.out.println("Resposta q3");
		q.imprime();

		/*
		 * Teste q4
		 */

		Pilha p1 = new Pilha();
		Pilha p2 = new Pilha();
		
		for (int i = 1; i <= 7; i++) {
			p1.empilha(i);
			p2.empilha(i);
		}
		
		Pilha s = q4(p1, p2);
		
		System.out.println("Resposta q4");
		s.imprime();
		
		/*
		 * Teste q5
		 */
		
		int vetor [] = new int [] {3, 2, 1, 5, 4, 7, 6, 8};
		
		q5(vetor, 0, 7);	
		
		System.out.println("Resposta q5");
		for (int i = 0; i < vetor.length; i++) {
			System.out.print(vetor[i] + " ");
		}
		
	}

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub

		/*
		 * Procedimento para testar as questões da prova. Não altere este procedimento.
		 * Se desejar, utilize o restante da função mais para escrever seus testes
		 */
		teste();

		/*
		 * Para teste das questões q1 e q2 faça a chamada dos métodos sem passar
		 * parâmetros
		 */

	}
}
