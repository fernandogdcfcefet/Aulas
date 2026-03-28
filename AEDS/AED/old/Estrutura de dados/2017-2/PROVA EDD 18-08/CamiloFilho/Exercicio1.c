#include<stdio.h>
#include<math.h>
#define N 10

float desvioPadrao(int *v){
    int i;
    float r, med;
    for(i=0;i<N;i++)
        med = (med*i+ v[i])/(i+1);
    for(i=0;i<N;i++)
        r+= (v[i]-med)*(v[i]-med);

    return sqrt(r/(N-1));
}

int main(){
    int v[N]={4,6,5,6,4,7,6,8,9,6};

    printf("%f",desvioPadrao(v));

    return(0);
}
