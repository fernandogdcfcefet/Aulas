#include <iostream>

using namespace std;

int main()
{
    bool x, y, z;

    cout << "Para as variaveis digite 1 para TRUE e 0 para FALSE" << endl;

    cout << "Digite o valor para X" << endl;
    cin >> x;

    cout << "Digite o valor para Y" << endl;
    cin >> y;

    cout << "Digite o valor para Z" << endl;
    cin >> z;

    bool op1 = (x && y) || (x && !z);
    bool op2 = (x || y) && (!x && z);

    cout << "(x && y) || (x && !z) = " << op1 << endl;
    cout << "(x || y) && (!x && z) = " << op1 << endl;

	return 0;
}
