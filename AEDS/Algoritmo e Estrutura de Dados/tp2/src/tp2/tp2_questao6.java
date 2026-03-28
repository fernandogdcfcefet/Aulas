public class Tp2Ex6 {
    static class celula {

        char letra;
        celula proximo;
    }
    static celula primeiro;
    static celula ultimo;
    public static void main(String[] args) {

		// lista encadeada e inicializada com caracteres

    	primeiro = new celula();
    	ultimo = primeiro;
   
   		celula auxiliar=new celula();
   		auxiliar.letra='E';
   		ultimo.proximo=auxiliar;
   		ultimo=auxiliar;
   
   		auxiliar=new celula();
   		auxiliar.letra='O';
   		ultimo.proximo=auxiliar;
   		ultimo=auxiliar;
   
   		auxiliar=new celula();
   		auxiliar.letra='F';
   		ultimo.proximo=auxiliar;
   		ultimo=auxiliar;
   
   		auxiliar=new celula();
   		auxiliar.letra='H';
   		ultimo.proximo=auxiliar;
   		ultimo=auxiliar;
   
        // em cada iteraçao o ultimo elemento e removido e inserido na posiçao inversa a sua posiçao inicial   
        for(int i=1; i<=5; i++){
              char auxiliar3=remove();
             insere(i, auxiliar3);
        } 
		// imprime a lista
        celula aux = primeiro;
        for (int i = 0; i < 5; i++) {
            aux = aux.proximo;
            System.out.println(aux.letra);

        }
    }
     

	// remove o ultimo elemento da lista 
    static char remove(){
       celula auxiliar=primeiro;
       char auxiliar2=' ';
        while(auxiliar.proximo!=null){
            if(auxiliar.proximo==ultimo){
                auxiliar2=auxiliar.proximo.letra;
                auxiliar.proximo=null;
                ultimo=auxiliar;
                break;
            }
            auxiliar=auxiliar.proximo;
           }
        return auxiliar2;
    }

	// insere a letra na posiçao pos
    static void insere(int pos, char letra){
        celula auxiliar=primeiro;
       int contador=0;
        while(auxiliar!=null){
            if(contador==pos-1){
                celula nova=new celula();
                nova.letra=letra;
                nova.proximo=auxiliar.proximo;
                auxiliar.proximo=nova;
                break;
            }
            auxiliar=auxiliar.proximo;
            contador++;
        }
    }
}
