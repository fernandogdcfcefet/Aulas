void letraB (Tree * raiz){
    if (raiz ->sae!=null){
        printf("1");
        letraB (raiz ->sad);
    }

    if (raiz ->ch!=''){
        printf("1");
        printf("%c\n",raiz->ch);
    }

    if (raiz ->sad!=null){
        printf("0");
        letraB (raiz ->sae);
    }
}
