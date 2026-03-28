#include <iostream>

using namespace std;

void troca(int *a, int *b)
{
    int aux = *a;   //variavel auxiliar que recebe o valor que o ponteiro a aponta
    *a = *b;        //a recebe o valor que b aponta
    *b = aux;       //b recebe o valor armazenado na variavel auxiliar
}


int main()
{
    int p = 4;
    int q = 9;

    cout << "Antes da troca" << endl;
    cout << "Valor de p: " << p << endl;
    cout << "Valor de q: " << q << endl;

    troca(&p, &q);

    cout << "Depois da troca" << endl;
    cout << "Valor de p: " << p << endl;
    cout << "Valor de q: " << q << endl;

    return 0;
}
