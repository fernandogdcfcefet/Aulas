#include <iostream>

using namespace std;


bool func(int tam, int vet[], int *par, int *impar, int *negativos)
{
    for(int i = 0; i < tam; i++)
    {
        if(vet[i] % 2 == 0)
            *par = *par + 1;
        else
            *impar = *impar + 1;

        if(vet[i] < 0 )
            *negativos = *negativos + 1;
    }

    if(*negativos > 0)
        return true;
    else
        return false;
}




int main()
{

    int tam;
    int par = 0;
    int impar = 0;
    int negativos = 0;

    cout << "Digite o tamanho do vetor:" << endl;
    cin >> tam;

    int vet[tam];

    cout << "Digite os valores:" << endl;
    for(int i = 0; i < tam; i++)
    {
        cin >> vet[i];
    }

    if(func(tam, vet, &par, &impar, &negativos))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "Num pares: " << par << endl;
    cout << "Num impares: " << impar << endl;

    return 0;

}
