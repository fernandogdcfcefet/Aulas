function [p, vetor, contador] = particao(vetor, contador, l, h)
    
    x = vetor(h);
    i = l-1;
    for j=l:(h-1)
        contador = contador+1;
        if(vetor(j) <= x)
            i = i+1;
            aux = vetor(i);
            vetor(i) = vetor(j);
            vetor(j) = aux;
        end
    end
    
    aux = vetor(i+1);
    vetor(i+1) = vetor(h);
    vetor(h) = aux;
    p = i+1;
    
end