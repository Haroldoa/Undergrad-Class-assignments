

/* Programming 5C: Haroldo Altamirano.
A program that revises Program # 3, birthdate validation for User and Parents
This program will use functions to make code more readable and easier to understand.
*/



#include <iostream>  //inclusion of support for doing input & output

using namespace std; //declare access to standard stuff like cin, cout



//Define the isLeapYear function

//Return true if year represents a leap year;
//otherwise, return false.

bool isLeapYear(int userYear)
{
	if (userYear % 4 == 0 && (userYear % 100 != 0 || (userYear % 100 == 0 && userYear % 400 == 0))) // Test if leap year (any year divisible by 4, but not divisible by 100 unless also divisible by 400)
		return true;

	else
		return false;
}



//Define the isValidDate function
//It should return true
//if month, day, and year together represents a valid date;
//otherwise, it should return false.

bool isValidDate(int month, int day, int year)
{
	
	if (year > 0) // Check year: Year must be positive. If true continue checking
	{

		if (month > 0 && month < 13) // Check month: Must be between 1 and 12
		{
			// Check days for validity: See below (range depends on what month and if leap year or not)

			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) // For any of these months
			{

				if (day > 0 && day < 32) // range can be from 1 to 31 days
					return true; // is valid!
				else
					return false;
			}

			if (month == 4 || month == 6 || month == 9 || month == 11) // For any of these other months
			{

				if (day > 0 && day < 31) // range can be from 1 to 30 days
					return true; // is valid!
				else
					return false;
			}

			if (month == 2 && isLeapYear(year) == false) // For February when not leap year
			{
				if (day > 0 && day < 29) // range can be from 1 to 28 days
					return true; // is valid!
				else
					return false;
			}
			if (month == 2 && isLeapYear(year) == true)  // For February when in leap year
			{
				if (day > 0 && day < 30) // range can be from 1 to 29 days
					return true; // is valid!
				else
					return false;
			}
		}
		else // month out of range
			return false;
	}

	else // For any negative year or 0
		return false;

}



// Beginning of main function

int main()

{
	//Declare local variables
	
	int month, day, year; // For dates to be validated


	do // loop for user's birthdate validation
	{
		cout << "\nHello!\n"
			<< "Please enter your birthdate and I will confirm if it is a valid date \n"
			<< "I will check that the day, month and year are possible \n"
			<< "I will also report if you were born on a leap year! \n \n"

			<< "Please enter your date in the following format (with spaces): \n"
			<< "MM DD YYYY (For example: 02 01 1975)\n";

		cin >> month >> day >> year; // user inputs date

		if (isValidDate(month, day, year) == false) // invalid date, return invalid message
		{
			cout << "The date you have entered is invalid. \n"
				<< "Please enter another date in the format: \n"
				<< "MM DD YYYY \n";
		}

		else if (isLeapYear(year) == true) // date is valid and year was a leap year
		{
			cout << "That is a valid date!\n"
				<< "Did you know you were born on a leap year? \n";
		}

		else if (isLeapYear(year) == false) // date is valid and year is not leap year
		{
			cout << "That is a valid date!\n"
				<< "The year you were born on was not a leap year \n";
		}
	} 
	while (isValidDate(month, day, year) == false); // Repeat until date is valid

	// ------------------------------------------------------------------------------------------------------------------

	// Repeat similar loop for both parents, start with father and then mother

	do // loop for father's birthdate validation (same as user but with different pronouns)
	{
		cout << "\nHello!\n"
			<< "Please enter your father's birthdate and I will confirm if it is a valid date \n"
			<< "I will check that the day, month and year are possible \n"
			<< "I will also report if he was were born on a leap year! \n \n"

			<< "Please enter your date in the following format (with spaces): \n"
			<< "MM DD YYYY (For example: 02 01 1975)\n";

		cin >> month >> day >> year; // user inputs date

		if (isValidDate(month, day, year) == false) // invalid date, return invalid message
		{
			cout << "The date you have entered is invalid. \n"
				<< "Please enter another date in the format: \n"
				<< "MM DD YYYY \n";
		}

		else if (isLeapYear(year) == true) // date is valid and year was a leap year
		{
			cout << "That is a valid date!\n"
				<< "Did you know he was born on a leap year? \n";
		}

		else if (isLeapYear(year) == false) // date is valid and year is not leap year
		{
			cout << "That is a valid date!\n"
				<< "The year he was born on was not a leap year \n";
		}
	} 
	while (isValidDate(month, day, year) == false); // Repeat until date is valid

	//-------------------------------------------------------------------------------------------------------------------

	do // loop for mother's birthdate validation (same as user but with different pronouns)
	{
		cout << "\nHello!\n"
			<< "Please enter your mother's birthdate and I will confirm if it is a valid date \n"
			<< "I will check that the day, month and year are possible \n"
			<< "I will also report if she was were born on a leap year! \n \n"

			<< "Please enter your date in the following format (with spaces): \n"
			<< "MM DD YYYY (For example: 02 01 1975)\n";

		cin >> month >> day >> year; // user inputs date

		if (isValidDate(month, day, year) == false) // invalid date, return invalid message
		{
			cout << "The date you have entered is invalid. \n"
				<< "Please enter another date in the format: \n"
				<< "MM DD YYYY \n";
		}

		else if (isLeapYear(year) == true) // date is valid and year was a leap year
		{
			cout << "That is a valid date!\n"
				<< "Did you know she was born on a leap year? \n";
		}

		else if (isLeapYear(year) == false) // date is valid and year is not leap year
		{
			cout << "That is a valid date!\n"
				<< "The year she was born on was not a leap year \n";
		}
	} 
	while (isValidDate(month, day, year) == false); // Repeat until date is valid



	// Display a good-bye message

	cout << "\nIt is a pleasure to validate these dates for you." << endl;

	cout << "Please enter any character and a return to quit the program." << endl;



	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;




}

//End of the main function.



