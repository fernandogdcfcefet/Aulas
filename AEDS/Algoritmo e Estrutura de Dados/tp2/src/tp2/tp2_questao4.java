public class Tp2Ex4 {
    public static void main(String[] args) {

		// a lista é inicializada com valores ordenados de 0 a 19
        Object lista[]=new Object[20];
        for(int i=0; i<lista.length;i++){
            lista[i]=i;
        }
		// os 3 primeiros itens da lista vao para as 3 ultimas posiçoes da lista
        troca(lista, 3);
        for(int i=0; i<lista.length;i++){
        System.out.println(lista[i]);
        }
	
	// a troca e feita retirando sempre o primeiro elemento e inserindo-o ao final
	// isso e feito x vezes

    }
    static void troca(Object lista[], int x){
        Object item;
        for(int i=0; i<x; i++){
            item=retira(lista, 0);
            insere(lista, lista.length-1,item);
        }
          
    }

	// metodo para retirar o elemento na pos1 da lista
    
    static Object retira(Object lista[], int pos1){
        Object guarda=lista[pos1];
        for (int i=pos1;i<lista.length-1;i++)
        {
            lista[i]=lista[i+1];
        }
        return guarda;
       }
    

	// metodo para inserir o item na pos2 da lista
    static void insere(Object lista[], int pos2,Object item){
        for(int i=lista.length-1;i>pos2;i--)
        {
            lista[i]=lista[i-1];
         }
        lista[pos2]=item;
    }
    
}
