function [contador, vetor] = heapsort(vetor)
    
    contador = 0;
    n = length(vetor);
    
    esq = n/2 + 1;
    
    while(esq > 1)
        esq = esq -1;
        [contador, vetor] = refaz(esq, n, vetor, contador);
    end
    
    while(n > 1)
        aux = vetor(n);
        vetor(n) = vetor(1);
        vetor(1) = aux;
        n = n-1;
        [contador, vetor] = refaz(1, n, vetor, contador);
    end
    
end