#include <iostream>
#include <string>	

using namespace std;


int procuraCharNaString(string str, char ch)
{
	for(int i=0; i < str.size(); i++)
	{
		if(str[i] == ch)
			return i;
	}
	return -1;	
}

int main()
{
	string nome;
	cout << "Digite o seu nome: ";
	cin >> nome;

	char ch;
	cout << "Digite um caractere para procurar: ";
	cin >> ch;
	
	int res = procuraCharNaString(nome,ch);
	if(res != -1)
		cout << "Encontrou" << endl;
	else
		cout << "NAO encontrou" << endl;
	
	return 0;
}
