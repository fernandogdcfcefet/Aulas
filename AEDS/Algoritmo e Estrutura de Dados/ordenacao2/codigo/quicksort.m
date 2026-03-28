function [contador, vetor] = quicksort(vetor, esq, dir, contador)
    
    i = esq;
    j = dir;
    pivo = vetor(i);
    
    while(i<j)
        contador = contador+2;
        while(vetor(i)<pivo)
            i = i+1;
            contador = contador +1;
        end
        while(vetor(j)>pivo)
            j = j-1;
            contador = contador +1;
        end
        if(i<=j)
            aux = vetor(i);
            vetor(i) = vetor(j);
            vetor(j) = aux;
            i = i+1;
            j = j-1;
        end
    end
    
    if(j > esq)
        [contador, vetor] = quicksort(vetor, esq, j, contador);
    end
    
    if(i < dir)
        [contador, vetor] = quicksort(vetor, i, dir, contador);
    end
    
end