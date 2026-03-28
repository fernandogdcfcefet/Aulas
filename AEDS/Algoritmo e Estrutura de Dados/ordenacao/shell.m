function [comp] = shell(vetor)

    comp = 0;

    tam = length(vetor);
    h = 1;
    while(h < tam)
        h = 3*h + 1;
    end
    
    while(h > 1)
        h = fix(h/3);
        for i=2:tam
            j = i;
            comp = comp+1;
            while(j > h && vetor(j)<vetor(j-h))
                aux = vetor(j-h);
                vetor(j-h) = vetor(j);
                vetor(j) = aux;
                j = j-h;
                comp = comp + 1;
            end
        end
    end

end