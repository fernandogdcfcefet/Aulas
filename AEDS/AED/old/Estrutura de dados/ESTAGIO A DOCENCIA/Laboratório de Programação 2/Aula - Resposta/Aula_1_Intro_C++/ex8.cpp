#include <iostream>
#include <cmath>

using namespace std;

float soma(int n, float x)
{
    float resultado = 0.0;
    for(int i=0; i<=n; i++)
        resultado+=pow(x,i);

    return resultado;
}


int main()
{
    int n;
    float x;
    float s;

    cout << "Digite o numero N: " << endl;
    cin >> n;
    cout << "Digite o numero X: " << endl;
    cin >> x;

    s = soma(n,x);

    cout << "Resultado da soma: " << s << endl;

    return 0;
}
