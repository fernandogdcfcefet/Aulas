#include <iostream>

using namespace std;

int main()
{

    int *pt;

    int x;  

    cout << "Digite o valor de x: ";
    cin >> x;

    pt = &x;

    cout << "Endereco de pt: " << pt << endl;
    cout << "Endereco de x : " << &x << endl;

    *pt = (*pt)*10;

    cout << "Valor de X multiplicado por 10: " << x << endl;

    pt = pt + 10;

    cout << "Endereco de pt: " << pt << endl;    

    return 0;
}
