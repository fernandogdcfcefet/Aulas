public class ArvoreSBB{

	private static class No{
		int reg;
		No esq, dir;
		byte incE, incD;	
	}

	private static final byte Horizontal = 0;
	private static final byte Vertical = 1;
	private No raiz;
	private boolean propSBB;
	private int c = 0;

	public ArvoreSBB(){
		raiz = null;
		propSBB = true;	
	}

	public Integer pesquisa(int reg){
		return pesquisa(reg, raiz);	
	}

	public void insere(int reg){
		raiz = insere(reg, null, raiz, true);	
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

	private No ee(No ap){
		No ap1 = ap.esq;
		ap.esq = ap1.dir;
		ap1.dir = ap;
		ap1.incE = Vertical;
		ap.incE = Vertical;
		ap = ap1;
		return ap;	
	}

	private No dd(No ap){
		No ap1 = ap.dir;
		ap.dir = ap1.esq;
		ap1.esq = ap;
		ap1.incD = Vertical;
		ap.incD = Vertical;
		ap = ap1;
		return ap; 	
	}

	private No ed(No ap){
		No ap1 = ap.esq;
		No ap2 = ap1.dir;
		ap1.incD = Vertical;
		ap.incE = Vertical;
		ap1.dir = ap2.esq;
		ap2.esq = ap1;
		ap.esq = ap2.dir;
		ap2.dir = ap;
		ap = ap2;
		return ap;	
	}

	private No de(No ap){
		No ap1 = ap.dir;
		No ap2 = ap1.esq;
		ap1.incE = Vertical;
		ap.incD = Vertical;
		ap1.esq = ap2.dir;
		ap2.dir = ap1;
		ap.dir = ap2.esq;
		ap2.esq = ap;
		ap = ap2;
		return ap; 	
	}

	private No insere(int reg, No pai, No filho, boolean filhoEsq){
		if(filho == null){
			filho = new No();
			filho.reg = reg;
			filho.incE = Vertical;
			filho.incD = Vertical;
			filho.esq = null;
			filho.dir = null;
			if(pai != null)
				if(filhoEsq)
					pai.incE = Horizontal;
				else
					pai.incD = Horizontal;
			propSBB = false;		
		}	

		else if(reg < filho.reg){
			filho.esq = insere(reg, filho, filho.esq, true);
			if(!propSBB)
				if(filho.incE == Horizontal){
					if(filho.esq.incE == Horizontal){
						filho = ee(filho);
						if(pai!=null)
							if(filhoEsq)
								pai.incE = Horizontal;
							else
								pai.incD = Horizontal;
					
					}
					else if(filho.esq.incD == Horizontal){
						filho = ed(filho);
						if(pai != null)
							if(filhoEsq)
								pai.incE = Horizontal;
							else
								pai.incD = Horizontal;
					
					}
				
				}	
				else
					propSBB = true;	
		}		
		else if(reg > filho.reg){
			filho.dir = insere(reg, filho, filho.dir, false);
			if(!propSBB)
				if(filho.incD == Horizontal){
					if(filho.dir.incD == Horizontal){
						filho = dd(filho);
						if(pai!=null)
							if(filhoEsq)
								pai.incE = Horizontal;
							else
								pai.incD = Horizontal;
					
					}
					else if(filho.dir.incE == Horizontal){
						filho = de(filho);
						if(pai != null)
							if(filhoEsq)
								pai.incE = Horizontal;
							else
								pai.incD = Horizontal;
					
					}
				
				}	
				else
					propSBB = true;			
		}

		else{
			System.out.println("Registro já existente!");
			propSBB = true;
		}

		return filho;

	}

	private void imprime(No p){
		if(p.esq != null)
			imprime(p.esq);
		System.out.println(p.reg);
		if(p.dir != null)
			imprime(p.dir);	
	}

}
