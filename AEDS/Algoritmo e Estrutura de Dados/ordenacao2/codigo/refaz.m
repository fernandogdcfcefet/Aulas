function [contador, vetor] = refaz(esq, dir, vetor, contador)
    
    i = esq;
    j = i*2;
    aux = vetor(i);
    
    contador = contador + 1;
    while(j <= dir)
        contador = contador + 2;
        if(j<dir && vetor(j) < vetor(j+1))
            j = j+1;
        end
        if(aux >= vetor(j))
            break;
        end
        contador = contador +1;
        vetor(i) = vetor(j);
        i=j;
        j = i*2;
    end
    
    vetor(i) = aux;
    
end