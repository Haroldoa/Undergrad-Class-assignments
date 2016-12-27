

// Handout #1: Source code of a C++ Program, which

// converts distance in miles to kilometers.



#include <iostream>  //inclusion of support for doing input & output

using namespace std; //declare access to standard stuff like cin, cout



// Beginning of main function

int main()

{

	// Declaration of variables

		// Menu Options

	char L = 'L' ; // Leap year option

	char D = 'D' ; // Distance conversion (miles to km) option

	char Q = 'Q' ; // Quit option

	char option; // What option is input

	bool isInService = true ; // To terminate menu

		// Leap year

		int userYear; // for input of year to be tested

		char Continue; // user controlled variable for continuing to test leap years

		// Distance

		double miles, kms;	// distance, miles and kilometers

		double KM_PER_MILE = 1.609;    // for storing a constant: 1.609 km equals a mile



	// Display Menu Choices

		while (isInService == true)
		{
			cout << "Hello, this program can perform three things for you! \n" <<
				"It can: \n \n" <<
				"1. Tell you if a year is a leap year \n" <<
				"2. Convert miles to kilometers for a given distance \n" <<
				"3. Quit this program \n" <<
				"================================================================================ \n"
				"Please enter L for a leap year test \n" <<
				"D for a distance conversion \n" <<
				"Or Q to quit." << endl << endl;

			cin >> option;

			isInService = false;



			while (option != L && option != D && option != Q) // Reenter if invalid input
			{
				cout << "You have entered an invalid character. \n" <<
					"Please enter L for a leap year test \n" <<
					"D for a distance conversion \n" <<
					"Or Q to quit." << endl << endl;

				cin >> option;
			}
			;

			// Process input in menu



			if (option == L) 	// Choice 1 (leap year)
			{
				do
				{
					// Ask for input

					cout << "Enter a year and I will test if it is a leap year \n";

					cin >> userYear;




					// Test

					if (userYear < 0) // invalid
						cout << "Please only enter years greater or equal to 0. \n";


					else if (userYear % 4 == 0 && (userYear % 100 != 0 || (userYear % 100 == 0 && userYear % 400 == 0))) // Test if leap year (any year divisible by 4, but not divisible by 100 unless also divisible by 400)
						cout << "That is indeed a leap year." << endl;


					else if (!(userYear % 4 == 0 && (userYear % 100 == 0 && userYear % 400 == 0))) // is leap year false? 
						cout << "This is not a leap year." << endl;



					// Ask if they would like to test again

					cout << "Would you like to test another year? \n" <<
						"Please enter Y if you would like to continue \n" <<
						"Or any other character if you would like to return to the main menu \n \n";

					cin >> Continue;
				} 
				while (Continue == 'Y')
				;

				if (Continue != 'Y') // If user does not wish to continue, return them to the main menu.
					isInService = true;

			}



			if (option == D) // Choice 2 Distance convertion option
			{
				do
				{
					// Get the input of distance in miles.

					cout << "What is the distance in miles?" << endl;

					cin >> miles;

					cout << "The distance in miles is " << miles << endl;



					// Convert the distance to kilometers and store the result.

					kms = KM_PER_MILE * miles;



					// Display the distance in kilometers.

					cout << "The distance in kilometers is " << kms << endl << endl;



					// Ask if they would like to test again

					cout << "Would you like to test another year? \n" <<
						"Please enter Y if you would like to continue \n" <<
						"Or any other character if you would like to return to the main menu \n \n";

					cin >> Continue;
				} while (Continue == 'Y')
					;

				if (Continue != 'Y') // If user does not wish to continue, return them to the main menu.
					isInService = true;
			}
		}	// End of main while loop

	


	// Quit

	cout << "Please enter any character and a return to quit the program." << endl;



	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;




}

//End of the main function.



