 #include <stdio.h>
 #include <stdlib.h>

 int **Alocar_matriz (int m, int n)
 {
    int i;
    if (m < 1 || n < 1){
        printf ("** Erro: Parametro invalido **\n");
        return (NULL);
    }

    int **matriz = (int **)calloc (m, sizeof(int*));

    if (matriz == NULL){
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }

    for (i = 0; i < m; i++ )
    {
        matriz[i] = (int*)calloc (n, sizeof(int));
        if (matriz[i] == NULL){
            printf ("** Erro: Memoria Insuficiente **");
            return (NULL);
        }
    }

    return (matriz);
}

void Liberar_matriz (int m, int n, int **mat) {
    int i;
    if (mat != NULL) {
        if (m < 1 || n < 1)
            printf ("** Erro: Parametro invalido **\n");
        else {
            for (i=0; i<m; i++)
                free (mat[i]);
            free (mat);
        }
    }
}

int main (void){
    int i, j;
    int TAM_M, TAM_N;

    printf("Digite o tamanho de TAM_M (> 0): ");
    scanf("%d", &TAM_M);

    printf("Digite o tamanho de TAM_N (> 0): ");
    scanf("%d", &TAM_N);

    int **MATRIZ = Alocar_matriz(TAM_M,TAM_N);

    for (i=0; i<TAM_M; i++)
        for (j=0; j<TAM_N; j++)
            MATRIZ[i][j] = i + j;

    for (i=0; i<TAM_M; i++){
        for (j=0; j<TAM_N; j++)
            printf("%d ",MATRIZ[i][j]);
        printf("\n");
    }

    Liberar_matriz(TAM_M,TAM_N,MATRIZ);

    return 0;
}

