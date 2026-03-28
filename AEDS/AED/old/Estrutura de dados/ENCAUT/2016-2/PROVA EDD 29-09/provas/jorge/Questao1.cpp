




void RetiraTodos(Tipolista*lista , Tipoitem item){
	
	if(Vazia(*lista)){
		printf(" erro");
		return;
	}
	
	tipoapontador q=lista->primeiro;
	tipoapontador p=lista->primeiro->proximo;
	while(p!=NULL){
		if(p->item.chave==item->chave){
			q->proximo=p->proximo;
			free(p);
			p=q->proximo;
		}
		else{
			q=p;
			p=p->proximo;
		}
	}
}



void insereOrdenado(Tipoitem x,Tipolista *lista){
	tipoapontador aux;
	tipoapontador anterior=lista->primeiro;
	tipoapontador novo=(Tipoapontador) malloc(sizeof(Tipocelula));
	novo->item=x.chave;
	for(aux=lista->primeiro->proximo;aux!=NULL;aux=aux->proximo){
		if(x.chave<aux->item.chave){
			novo->proximo=aux;
			anterior->proximo=novo;
		}
		anterior=aux;
	}
}
