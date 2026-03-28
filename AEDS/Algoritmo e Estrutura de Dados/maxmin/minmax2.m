function [media] = minmax2()

    numVet = 500;

    cont(numVet) = 0;

    for i=1:numVet
        
        vetor = randi(10000, 1, 10000);
        
        maior = vetor(1);
        menor = maior;
                
        for j=2:length(vetor)
            
            cont(i) = cont(i) + 2;
            
            if(vetor(j) > maior)
                maior = vetor(j);
                cont(i) = cont(i) - 1;
            elseif(vetor(j) < menor)
                menor = vetor(j);
            end
            
        end
                
    end
    
    plot((1:numVet), cont);
    media = sum(cont)/numVet;

end