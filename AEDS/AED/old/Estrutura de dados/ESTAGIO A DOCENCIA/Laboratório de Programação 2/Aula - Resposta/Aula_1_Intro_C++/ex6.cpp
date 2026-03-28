#include <iostream>

using namespace std;

int fatorial(int n)
{
    int fat = 1;
    for(int i=1; i <= n; i++)
    {
		fat*=i;
    }

    return fat;
}


int main()
{
    int n;
    cout << "Digite o numero N:" << endl;
    cin >> n;

    int fat = fatorial(n);

    cout << "O fatorial de " << n << " eh: " << fat << endl;

	return 0;
}
