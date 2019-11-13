

/* Program 5A: Altamirano, H
This is a program which will display a menu and call functions.
The three void functions will be: 
1. the menu,
2. a function that checks for leap years,
3. a function that checks for prime numbers.
*/


#include <iostream>  //inclusion of support for doing input & output

using namespace std; //declare access to standard stuff like cin, cout



//Define the displayMenu function

void displayMenu()
{
		cout << "Hello, this program can perform three things for you! \n" << // Ask user for choice
			"It can: \n \n" <<
			"1. Tell you if a year is a leap year \n" <<
			"2. Tell you if a number you enter is prime \n" <<
			"3. Quit this program \n" <<
			"================================================================================ \n"
			"Please enter L for a leap year test \n" <<
			"D for a prime number check \n" <<
			"Or Q to quit." << endl << endl;\
	
}



//Define the checkLeapYear function

void checkLeapYear()
{
	// Declare local variable

	int userYear;


	// Ask for input

	cout << "Enter a year and I will test if it is a leap year \n";

	cin >> userYear;


	// Test

	if (userYear < 0) // invalid
		cout << "Please only enter years greater or equal to 0. \n";


	else if (userYear % 4 == 0 && (userYear % 100 != 0 || (userYear % 100 == 0 && userYear % 400 == 0))) // Test if leap year (any year divisible by 4, but not divisible by 100 unless also divisible by 400)
		cout << "That is indeed a leap year. \n" << endl;


	else if (!(userYear % 4 == 0 && (userYear % 100 == 0 && userYear % 400 == 0))) // is leap year false? 
		cout << "This is not a leap year. \n" << endl;
}



//Define the check Prime function

void checkPrime()
{
	// Declare local variable

	int userNumber; // Number tested

	int factorCount = 0; // starts at 0
	
	//Part I: Test for factors and display factors and if prime


	cout << "Welcome! \n"
		<< "You may test any natural number, that is, any integer greater than 0, \n" //Welcome prompt
		<< "and I will tell you all its non-trivial factors and if it is a prime number. \n \n"
		<< "Please enter a natural number \n";

	cin >> userNumber;	// User input



	while (userNumber <= 0)
	{
		cout << "Sorry, you have entered an invalid number. \n" // Invalid message
			<< "You may test any natural number, that is, any integer greater than 0, \n"
			<< "and I will tell you all of its non-trivial factors and if it is a prime number. \n"
			<< "Please enter a natural number \n";

		cin >> userNumber;	// User input
	}



	// Part II: Test each factor

	for (int divisor = 2; divisor <= (userNumber - 1); divisor++) //Start loop at 2 and end testing at n-1
	{
		if (userNumber % divisor == 0)	// test if factor
		{
			cout << divisor << " is a factor of " << userNumber << "." << endl;
			factorCount++;
		}
	}

	if (factorCount == 0)
		cout << "The number " << userNumber << " is a prime number. \n \n";

	else cout << userNumber << " is not a prime number. \n";

	cout << userNumber << " has a total of " << factorCount << " factors. \n \n";
}



// Beginning of main function

int main()

{
	// Declare variables

	bool isInService = true;

	char option;

	// Call Menu

	while (isInService == true)
	{
		displayMenu();

		cin >> option;


		switch (option)
		{
		case 'L': // fallthrough
		case 'l': checkLeapYear(); // call
			break;
		case 'D': // fallthrough
		case 'd': checkPrime(); // call
			break;
		case 'Q': // fallthrough
		case 'q': isInService = false; // end menu
			break;
		default: cout << "You have entered an invalid variable. \n \n";
		}

	}
	// Display a good-bye message when menu quits

	cout << "Goodbye!" << endl;

	cout << "Please enter any character and a return to quit the program." << endl;



	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;




}

//End of the main function.



