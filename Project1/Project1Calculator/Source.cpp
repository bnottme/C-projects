//Developer: Brett Nottmeier
//Date: 9/17/2023
//Course: CS-210
//Purpose: To create a clock for CHADA Tech
#include <iostream>
#include <string>
using namespace std;

//Create a clockVariables class for variables to be used in the clock
class clockVariables {
private:
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;

public:
	clockVariables(unsigned int h, unsigned int m, unsigned int s) : hours(h), minutes(m), seconds(s) {}

	unsigned int getHours() const { return hours; }
	unsigned int getMinutes() const { return minutes; }
	unsigned int getSeconds() const { return seconds; }

	void setHours(unsigned int h) { hours = h; }
	void setMinutes(unsigned int m) { minutes = m; }
	void setSeconds(unsigned int s) { seconds = s; }


};
//Function to create a repetition of the character c based on n size
string charstring(size_t n, char c) {
	return string(n, c);
}

//Function to convert int to a two digit string
string twoDigitString(unsigned int n) {
	if (n >= 0 && n <= 9) {
		return "0" + to_string(n);
	}
	else {
		return to_string(n);
	}
}
//Creates a function to format in 24-hour time format
string format24Hour(unsigned int h, unsigned int m, unsigned int s) {
	string formattedHours = twoDigitString(h);
	string formattedMinutes = twoDigitString(m);
	string formattedSeconds = twoDigitString(s);

	string formatted24Time = formattedHours + ":" + formattedMinutes + ":" + formattedSeconds;

	return formatted24Time;
}
//Creates a function to format in 12-hour time format
string format12Hour(unsigned int h, unsigned int m, unsigned int s) {
	string formattedHours = twoDigitString(h);
	string formattedMinutes = twoDigitString(m);
	string formattedSeconds = twoDigitString(s);
	string timeOfDay = (h >= 12) ? "PM" : "AM";

	//Determine if its AM OR PM
	if (h >= 0 && h <= 11) {
		if (h == 0) {
			formattedHours = "12";
		}
		else {
			formattedHours = twoDigitString(h);
		}
		timeOfDay = "AM";
	}
	else {
		if (h == 12) {
			formattedHours = "12";
		}
		else {
			formattedHours = twoDigitString(h - 12);
		}
		timeOfDay = "PM";
	}

	string formatted12Time = formattedHours + ":" + formattedMinutes + ":" + formattedSeconds + timeOfDay;

	return formatted12Time;
}
//Function to get menu choice from the user
unsigned int MenuChoice(unsigned int maxChoice) {
	unsigned int choice;

	do {
		cout << "Enter your choice 1-" << maxChoice << ": " << endl;
		cin >> choice;

		if (choice < 1 || choice > maxChoice) {
			cout << "Invalid please Enter a number between 1 and " << maxChoice << endl;

		}
	} while (choice < 1 || choice > maxChoice); {

		return choice;
	}
}
//Function to display clock
void clockDisplay(const clockVariables& currentTime) {
	//Get formatted time for both 12-hour format and 24-hour format
	string formatted12Hour = format12Hour(currentTime.getHours(), currentTime.getMinutes(), currentTime.getSeconds());

	string formatted24Hour = format24Hour(currentTime.getHours(), currentTime.getMinutes(), currentTime.getSeconds());

	//Clocks display using charstring and the formatted time above
	cout << charstring(30, '~') << "    " << charstring(30, '~') << endl;;
	cout << "~     12-Hour Clock          ~    ~      24-Hour Clock         ~" << endl;
	cout << "~       " << formatted12Hour << "           ~    ~         " << formatted24Hour << "           ~" << endl;
	cout << charstring(30, '~') << "    " << charstring(30, '~') << endl;;
}
//Add one hour to the clock
void oneHour(clockVariables& currentTime) {

	unsigned int currentHour = currentTime.getHours();
	currentTime.setHours((currentHour + 1) % 24);
}
//Add one minute to the clock
void oneMinute(clockVariables& currentTime) {

	unsigned int currentMinute = currentTime.getMinutes();

	if (currentMinute >= 59) {
		currentTime.setMinutes((currentMinute + 1) % 60);
		oneHour(currentTime);
	}
	else {
		currentTime.setMinutes(currentMinute + 1);
	}
}

// Add one second to the clock
void oneSecond(clockVariables& currentTime) {

	unsigned int currentSecond = currentTime.getSeconds();

	if (currentSecond >= 59) {
		currentTime.setSeconds((currentSecond + 1) % 60);
		oneMinute(currentTime);
	}
	else {
		currentTime.setSeconds(currentSecond + 1);
	}
}

//Display the menu and handle users input for menu
void Menu() {
	clockVariables currentTime(0, 0, 0); //Sets the starting time for clock


	unsigned int choice;

	do {
		clockDisplay(currentTime);//Display clock

		cout << charstring(21, '~') << endl;
		cout << "~ 1. Add One Hour   ~" << endl;
		cout << "~ 2. Add One Minute ~" << endl;
		cout << "~ 3. Add One Second ~" << endl;
		cout << "~ 4. Exit Program   ~" << endl;
		cout << charstring(21, '~') << endl;

		//Gets choice from user
		choice = MenuChoice(4);

		switch (choice) {

		case 1:
			oneHour(currentTime);
			break;

		case 2:
			oneMinute(currentTime);
			break;

		case 3:
			oneSecond(currentTime);
			break;

		case 4:
			cout << "Leaving Program Goodbye!" << endl;
			break;
		}

	} while (choice != 4);
}

int main() {
	Menu();
	return 0;
}