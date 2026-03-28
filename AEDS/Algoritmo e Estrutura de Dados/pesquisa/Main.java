import java.util.Random;

public class Main{

	public static void permuta(int n, int[] vet){
		int []aux = new int[n];
		for(int i=0; i<n; i++){
			aux[i] = i;
		}
		int it = 0;
		while(n > 1){
			Random gerador = new Random(); 
        	int numero = gerador.nextInt(n);
			vet[it] = aux[numero];
			it ++;
			for(int j=numero; j<n-1; j++){
				aux[j] = aux[j+1];			
			}
			n --;
		}
		vet[it] = aux[0];	
	}

	public static void main(String args[]){
		ArvoreBinaria ab;
		ArvoreSBB sbb;

		for(int n=1000; n<=10000; n+=1000){
			ab = new ArvoreBinaria();
			sbb = new ArvoreSBB();
			for(int i=0; i<n; i++){
				ab.insere(i);			
				sbb.insere(i);
			}
			System.out.println("Arvore Binaria - Elementos Ordenados");
			ab.pesquisa(n);
			System.out.println(ab.comparacoes());
			System.out.println("SBB - Elementos Ordenados");
			sbb.pesquisa(n);
			System.out.println(sbb.comparacoes());		
		}

		
		for(int n=1000; n<=10000; n+=1000){
			ab = new ArvoreBinaria();
			sbb = new ArvoreSBB();
			int []vetor = new int [n];
			permuta(n, vetor);
			for(int i=0; i<n; i++){
				ab.insere(vetor[i]);
				sbb.insere(vetor[i]);			
			}
			System.out.println("Arvore Binaria - Elementos Aleatorios");
			ab.pesquisa(n);
			System.out.println(ab.comparacoes());
			System.out.println("SBB - Elementos Aleatorios");
			sbb.pesquisa(n);
			System.out.println(sbb.comparacoes());		
		}		

		

	}

}
