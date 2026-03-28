int classifica(mat[N]N]){
    int i, j;

    for(i=1;i<N;i++){
        for(j=1;j<N;j++){
            if(mat[i][j] != mat[j][i]){
                return -1; //quando retornar -1, implica que os grafos são orientados
            }
        }
    }
    return 1; //quando retornar 1, implica que os grafos são não-orientados
}

int soma(mat[N][N]){
    int i, j, total = 0;
    if(classifica(mat[N][N])==-1){
        for(i=1;i<N;i++){
            for(j=1;j<N;j++){
                int total = total + mat[i][j];
            }
        }
        return total;
    }

    else{

    }
}
