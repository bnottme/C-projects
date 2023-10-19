#pragma once
#include <map>
#include <string>


class GroceryApp
{
public:
	GroceryApp(); // Constructor to initialize application
	void run(); // Main program loop

private:
	// Map to store item frequencies
	std::map<std::string, int> itemFrequencyMap;

	// Function to search and display a specific item frequency
	void searchItemFrequency();

	// Function to print all items and frequencies
	void printItemFrequencies();

	// Function to print histrogram visual of all items
	void printItemFrequencyHistogram();

	// Function to save items to backup file
	void saveItemFrequencyData();

	// Function to trim whitespace
	std::string trim(const std::string& str);
};

