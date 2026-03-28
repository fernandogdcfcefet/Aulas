public class ArvoreBinaria {

	private static class No{
		int reg;
		No esq, dir;	
	}

	private No raiz;
	private int c = 0;

	public ArvoreBinaria(){
		raiz = null;	
	}

	public Integer pesquisa(int reg){
		return pesquisa(reg, raiz);	
	}

	public void insere(int reg){
		raiz = insere(reg, raiz);	
	}

	public void imprime(){
		imprime(raiz);	
	}

	public int comparacoes(){
		return c;	
	}

	private Integer pesquisa(int reg, No p){
		c ++;		
		if(p==null) return null;
		else if(reg < p.reg){
			c ++;			
			return pesquisa(reg, p.esq);
		}
		else if(reg > p.reg){
			c+=2;
			return pesquisa(reg, p.dir);
		}	
		else{
			c+=2;			
			return p.reg;
		}
	}

	private No insere(int reg, No p){
		if(p==null){
			p = new No();
			p.reg = reg;
			p.esq = null;
			p.dir = null;		
		}	
		else if(reg < p.reg)
			p.esq = insere(reg, p.esq);
		else if(reg > p.reg)
			p.dir = insere(reg, p.dir);
		else
			System.out.println("Registro já existente!");
		return p;
	}	

	private void imprime(No p){
		if(p.esq != null)
			imprime(p.esq);
		System.out.println(p.reg);
		if(p.dir != null)
			imprime(p.dir);	
	}

} 
