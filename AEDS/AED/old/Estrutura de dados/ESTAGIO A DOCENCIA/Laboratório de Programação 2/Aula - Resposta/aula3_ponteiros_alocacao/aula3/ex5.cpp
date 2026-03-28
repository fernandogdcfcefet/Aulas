#include <iostream>

using namespace std;

int main()
{

    int N;
    float soma = 0.0;
    float media = 0.0;

    cout << "Digite o tamanho do vetor:" << endl;
    cin >> N;

    int *vet = new int[N];

    cout << "Digite os valores:" << endl;
    for(int i = 0; i < N; i++)
    {
        cin >> vet[i];
    }

    for(int i = 0; i < N; i++)
        soma += vet[i];

    media = soma/N;

    cout << "Media dos valores do vetor: " << media << endl;

    delete [] vet;

    return 0;
}
