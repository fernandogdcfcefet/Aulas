function [vetor contador] = refaz2(vetor,esq,dir,contador)
    while (esq * 2 <= dir)
        filho = esq * 2;

        contador = contador + 2;

        if (filho + 1 <= dir) && (vetor(filho) < vetor(filho+1))
            filho = filho + 1;
        end

        contador = contador + 1;

        if (vetor(esq) < vetor(filho))
            vetor([esq filho]) = vetor([filho esq]);
            esq = filho;

        else
            return
        end
    end
end