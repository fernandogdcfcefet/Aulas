#include <iostream>

using namespace std;

int main()
{
    int n;
    int tmp;
    float soma = 0.0;
    float media = 0.0;


    cout << "Digite o valor de N:" << endl;
    cin >> n;

    cout << "Digite os valores:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        soma += tmp;
    }

    media = soma/n;

    cout << "A media dos numeros e: " << media << endl;

	return 0;
}
