public class Tp2Ex3 {
    public static void main(String[] args) {
        Object lista[] = new Object[20];
		// a lista recebe valores ordenados de 0 a 14 
        for(int i=0;i<15;i++){
            lista[i]=i;
        }

		// sao removidos da lista os elementos da posiçao 5 a 6
        RemoveNC(lista, 5, 2);
        for(int i=0; i<lista.length;i++){
        System.out.println(lista[i]);
        }
    }
    
	// remove da lista os elementos da posiçao pos a pos+Qtde-1

    static void RemoveNC(Object lista[], int pos, int Qtde){
        for(int i=pos; i<lista.length-Qtde;i++)
            
            lista[i]=lista[i+Qtde];
    }
}
