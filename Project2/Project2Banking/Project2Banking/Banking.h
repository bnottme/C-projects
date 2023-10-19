#pragma once
class InvestmentCalculator
{
private:
	float startingInvestment; //Inital investment amount
	float monthlyDeposit; //Monthly deposit amount
	float interestRate; //Annual interest rate
	float years; //Number of years
	float totalAmount; //Total amount after calculating
	float interestAmount; //Interest earned
	float yearlyInterest; //Total interest earned in a year

public:
	InvestmentCalculator();
	void getInput(); //Function to get user input for investments
	void calculateWithoutDeposits(); //Function to calculate and display investments without monthly deposits
	void calculateWithDeposits(); //Function to calculate and display investments with monthly deposits
};

