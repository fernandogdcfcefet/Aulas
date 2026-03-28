#include <iostream>

using namespace std;


float LeCalculaMedia()
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

    return media;

}



int main()
{
    float media = LeCalculaMedia();
    cout << "A media dos numeros eh: " << media << endl;

	return 0;
}
