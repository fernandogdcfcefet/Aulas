function [contador, vetor]= heapsort2(vetor)

    contador=0;
    tam = length(vetor);
    esq = tam/2+1;

    while (esq > 1) 
        esq = esq - 1;
        [vetor contador] = refaz2(vetor, esq, tam,contador);
    end
    

    while (tam > 1)

        vetor([tam 1]) = vetor([1 tam]);
        tam = tam - 1;
        [vetor contador] = refaz2(vetor,1,tam,contador);

    end

end