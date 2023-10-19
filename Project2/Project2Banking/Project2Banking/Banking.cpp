#include "Banking.h"
#include <iostream>
#include <iomanip>

using namespace std;


InvestmentCalculator::InvestmentCalculator() { //Initialize variables
	startingInvestment = 0.0;
	monthlyDeposit = 0.0;
	interestRate = 0.0;
	years = 0.0;
	totalAmount = 0.0;
	interestAmount = 0.0;
	yearlyInterest = 0.0;
}


void InvestmentCalculator::getInput() { //Gets users input for investments
	cout << "Initial Investment Amount: $";
	cin >> startingInvestment;
	cout << "\nMonthly Deposit: $";
	cin >> monthlyDeposit;
	cout << "\nAnnual Interest (%):";
	cin >> interestRate;
	cout << "\nNumber of years:";
	cin >> years;
	
}

void InvestmentCalculator::calculateWithoutDeposits() { //Function to calculate and display investment without monthly deposits
	totalAmount = startingInvestment;

	cout << "\nBalance and Interest Without Additional Monthly Deposits";
	cout << "\n=================================================================";
	cout << "\nYears          Year End Balance          Year End Earned Interest";
	cout << "\n-----------------------------------------------------------------";

	for (int i = 0; i < years; i++) {
		//Calculate Yearly Interest
		interestAmount = (totalAmount) * (interestRate / 100);

		//Calculate Year End Total
		totalAmount = totalAmount + interestAmount;

		cout << endl << right << (i + 1) << "\t\t$" << fixed << setprecision(2) << setw(10) << totalAmount << "\t\t\t$" << setw(10) << interestAmount << endl; //Displays results
	}
}
void InvestmentCalculator::calculateWithDeposits() { //Function to calculate and display investment with monthly deposits
	totalAmount = startingInvestment;

	cout << "\nBalance and Interest With Additional Monthly Deposits";
	cout << "\n=================================================================";
	cout << "\nYears          Year End Balance          Year End Earned Interest";
	cout << "\n-----------------------------------------------------------------";

	for (int i = 0; i < years; i++) {
		// Calculate Yearly Interest
		yearlyInterest = 0;

		for (int j = 0; j < 12; j++) {
			// Calculate Monthly Interest
			interestAmount = (totalAmount + monthlyDeposit) * (interestRate / 100 / 12);

			// Calculate Monthly Total
			totalAmount = totalAmount + monthlyDeposit + interestAmount;

			// Calculate Yearly Total Interest
			yearlyInterest += interestAmount;
		}

		cout << endl << right << (i + 1) << "\t\t$" << fixed << setprecision(2) << setw(10) << totalAmount << "\t\t\t$" << setw(10) << yearlyInterest << endl; //Display results
	}
}
