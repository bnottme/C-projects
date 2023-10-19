#include "Banking.h"
#include <iostream>

using namespace std;

int main() {
	char choice;

	do {
		InvestmentCalculator calculator; //Create an instance of InvestmentCalculator class

		//Displays header
		cout << "**********************************" << endl;
		cout << "*********** Data Input ***********" << endl;

		calculator.getInput(); //Gets user input for investment

		calculator.calculateWithoutDeposits(); //Calculate and display investment results without monthly deposits.
		calculator.calculateWithDeposits(); //Calculate and display investment results with monthly deposits.

		cout << "Would you like to continue Y/N:"; //Asks user if they would like to continue
		cin >> choice;
		cout << endl << endl;

	} while (choice == 'Y' || choice == 'y'); //Continue loop if user enter Y or y
	return 0;
}
