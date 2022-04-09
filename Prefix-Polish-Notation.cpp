#include<iostream>
#include<string>
#include "MyStack.h"



using namespace std;
int main() {
	string infixNotation = "";
	cout << "Dati forma infixata:";

	getline(cin, infixNotation);
	int choice = 0;

	while (true) {

		cout << "\t Meniu      \n";
		cout << "1. Infix --> Postfix      \n";
		cout << "2. Infix --> Prefix        \n";
		cout << "3. Evaluare forma infixata introdusa      \n";
		cout << "4. Evaluarea unei alte forme infixate    \n";
		cout << "5. Iesire                   \n";
		cout << "Alegeti o comanda:";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Forma postfixata este:" << reversePolish(infixNotation) << endl;
			break;
		case 2:
			cout << "Forma prefixata este:" << polish(infixNotation) << endl;
			break;
		case 3: {
			cout << "Evaluare: " << evaluate(reversePolish(infixNotation)) << endl;
			break;
		}
		case 4: {
			cin.ignore(1, '\n');
			string evaluateNotation = "";
			cout << "Introduceti forma infixata:";
			getline(cin, evaluateNotation);
			cout << "Evaluare: " << evaluate(reversePolish(evaluateNotation)) << endl;
			break;
		}
		case 5:
			exit(-1);
		default:
			cout << "Comanda este gresita!\n";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}