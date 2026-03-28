function [] = main(op)

    min = 10000;
    max = 100000;
    passo = 10000;
    
    hold on;
    
    tam = (max + passo - min)/passo;
    c1(tam) = 0;
    c2(tam) = 0;
    X(tam) = 0;
    
    if(op == 1)    
        indx = 1;
        for i=min:passo:max
            vetor(i) = 0;
            for j=1:i
                vetor(j) = j;
            end
            c1(indx) = insercao(vetor);
            c2(indx) = shell(vetor);
            X(indx) = i;
            indx = indx+1;
        end
        plot(X,c1,'blue');
        plot(X,c2,'red');
        
    elseif(op == 2)
        indx = 1;
        for i=min:passo:max
            vetor(i) = 0;
            for j=1:i
                vetor(j) = i-j;
            end
            c1(indx) = insercao(vetor);
            c2(indx) = shell(vetor);
            X(indx) = i;
            indx = indx+1
        end
        plot(X,c1,'blue');
        plot(X,c2,'red');
        
    elseif(op == 3)
        indx = 1;
        for i=min:passo:max
            vetor(i) = 0;
            for j=1:i
                vetor(j) = randi(i);
            end
            c1(indx) = insercao(vetor);
            c2(indx) = shell(vetor);
            X(indx) = i;
            indx = indx+1
        end
        plot(X,c1,'blue');
        plot(X,c2,'red');
    end

end