function [comp, vetor] = insercao(vetor)
    
    comp = 0;

    tam = length(vetor);

    for i=2:tam
        j = i;
        comp = comp+1;
        while(j > 1 && vetor(j)<vetor(j-1))
            aux = vetor(j-1);
            vetor(j-1) = vetor(j);
            vetor(j) = aux;
            j = j-1;
            comp = comp + 1;
        end
    end
    
end