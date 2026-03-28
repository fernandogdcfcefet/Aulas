#include <iostream>

using namespace std;


void divisao(int num, int div, int *q, int *r)
{
    *q = num / div;
    *r = num % div;
}

int main()
{
    int num = 14;
    int div = 5;
    int q;
    int r;

    divisao(num, div, &q, &r);

    cout << "Dividendo: " << num << "\nDivisor: " << div << "\nQuociente: " << q << "\nResto: " << r << endl;
    return 0;
}
