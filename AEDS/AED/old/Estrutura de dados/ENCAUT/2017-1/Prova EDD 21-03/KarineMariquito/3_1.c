typedef struct{
    char rua[100];
}endereco;

typedef struct{
    char nome[100];
    endereco end;
    char telefone[100];
}pessoa;

// LINHA 23 :

// Ela compara a string endereço de pessoa na posição "i" com o endereço da pessoa na posição "j", que é a pessoa da proxima posição no vetor, iguala a zero pra ver se são iguais.
// Depois ela verifica se o nome da pessoa que acabou de ser verificado é igual, pois se for, a comparação esta entre a mesma pessoa, e nao é esse o objetivo.
