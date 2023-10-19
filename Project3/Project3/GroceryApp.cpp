#include "GroceryApp.h"
#include <iostream>
#include <fstream>

using namespace std;



GroceryApp::GroceryApp() {
	ifstream inputFile("CS210_project_three_input_file.txt"); // Constructor reads and process data from input file
	if (inputFile.is_open()) {
		string item;
		while (getline(inputFile, item)) {
			item = trim(item); //removes white spaces
			if (!item.empty()) {
				itemFrequencyMap[item]++; // Counts each item
			}
		}
		inputFile.close();
	}
}

void GroceryApp::searchItemFrequency() { //Searches for frequency of a specific item
	string itemToSearch;
	cout << "Enter an item to search for: ";
	cin >> itemToSearch;
	if (itemFrequencyMap.find(itemToSearch) != itemFrequencyMap.end()) {
		cout << "Frequency of " << itemToSearch << ": " << itemFrequencyMap[itemToSearch] << endl;
	}
	else {
		cout << "Item not found." << endl;
	}
}


void GroceryApp::printItemFrequencies() { // Prints all items and frequencies
	for (const auto& entry : itemFrequencyMap) {
		cout << entry.first << " " << entry.second << endl;
	}
}


void GroceryApp::printItemFrequencyHistogram() { // Prints all items with a histogram visual
	for (const auto& entry : itemFrequencyMap) {
		cout << entry.first << " ";
		for (int i = 0; i < entry.second; ++i) {
			cout << "*";
		}
		cout << endl;
	}
}

void GroceryApp::saveItemFrequencyData() { // Saves item frequencies to back up file frequency.dat
	ofstream outputFile("frequency.dat");
	if (outputFile.is_open()) {
		for (const auto& entry : itemFrequencyMap) {
			outputFile << entry.first << " " << entry.second << endl;
		}
		outputFile.close();
		cout << "Data saved to frequency.dat" << endl;
	}
	else {
		cout << "Error: Unable to save data to frequency.dat" << endl;
	}
}


void GroceryApp::run() { //User main menu
	int choice;
	while (true) {
		cout << "\nMenu:\n1. Search for an item\n2. Print item frequencies\n3. Print item frequency histogram\n4. Save data\n5. Exit\n";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			searchItemFrequency();
			break;
		case 2:
			printItemFrequencies();
			break;
		case 3:
			printItemFrequencyHistogram();
			break;
		case 4:
			saveItemFrequencyData();
			break;
		case 5:
			cout << "Exiting the program." << endl;
			return;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}
}
string GroceryApp::trim(const string& str) { // Function to remove whitespaces
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first) {
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}