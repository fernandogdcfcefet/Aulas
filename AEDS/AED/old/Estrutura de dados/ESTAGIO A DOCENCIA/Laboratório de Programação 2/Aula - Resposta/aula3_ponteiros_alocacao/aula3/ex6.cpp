#include <iostream>

using namespace std;


float prodEscalar(int n, float x[], float y[])
{
    float resultado = 0.0;

    for(int i = 0; i < n; i++)
        resultado += x[i]*y[i];

    return resultado;
}

int main()
{

    int N;
    float escalar;

    cout << "Digite o tamanho do vetor:" << endl;
    cin >> N;

    float *x = new float[N];
    float *y = new float[N];

    cout << "Digite os valores do vetor x:" << endl;
    for(int i = 0; i < N; i++)
    {
        cin >> x[i];
    }

    cout << "Digite os valores do vetor y:" << endl;
    for(int i = 0; i < N; i++)
    {
        cin >> y[i];
    }

    escalar = prodEscalar(N, x, y);

    cout << "Resultado do produto escalar: " << escalar << endl;

    delete [] x;
    delete [] y;

    return 0;
}
