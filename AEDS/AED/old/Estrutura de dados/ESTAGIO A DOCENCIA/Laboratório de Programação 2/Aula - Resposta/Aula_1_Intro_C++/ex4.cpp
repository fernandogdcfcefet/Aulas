#include <iostream>

using namespace std;

bool EhPrimo(int n)
{
    for(int i=2; i <= n/2; i++)
    {
        if(n%i == 0)
            return false;
    }

    return true;
}


int main()
{
    int n;

    cout << "Digite o valor de N:" << endl;
    cin >> n;

    if(EhPrimo(n))
        cout << "O numero " << n << " eh primo!" << endl;
    else
        cout << "O numero " << n << " NAO eh primo!" << endl;

	return 0;

}
