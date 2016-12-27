

// Program #1: Source code of a C++ Program, which

// converts US Dollars to Taiwanese Dollars.



#include <iostream>  //inclusion of support for doing input & output

using namespace std; //declare access to standard stuff like cin, cout



// Beginning of main function

int main()

{

	// Declaration of three US Cent variables

	int Pennies, Nickles, Dimes, Quarters;



	// Get the input of US Cents

	cout << "Please enter the amount of U.S. cents you wish to convert.\n" 
		<< "Use this format: Pennies Nickles Dimes Quarters \n"
		<< "And press Enter!" << endl;

	cin >> Pennies >> Nickles >> Dimes >> Quarters;

		cout << "\nYou have a total of:\n"
		<< Pennies << " Pennies\n"
		<< Nickles << " Nickles\n"
		<< Dimes << " Dimes\n"
		<< Quarters << " Quarters" << endl;



	// Declaration of US Cents in terms of Pennies (One Cent)

	int Nickles_as_Cents, Dimes_as_Cents, Quarters_as_Cents;



	// Convert Cents to terms of Pennies (One Cent)

	Nickles_as_Cents = Nickles * 5;

	Dimes_as_Cents = Dimes * 10;

	Quarters_as_Cents = Quarters * 25;



	// Get total amount of US Cents

	int TotalCents = Pennies + Nickles_as_Cents + Dimes_as_Cents + Quarters_as_Cents;

	cout << "In total you have " << TotalCents << " U.S. cents!" << endl;



	// Get US cents in terms of US dollars and remainding cents (ie: 20 dollars and 30 cents)

	int	TotalDollars = TotalCents / 100;

	int RemainderCents = TotalCents % 100;

		cout << "Which is " << TotalDollars << " U.S. dollars and " << RemainderCents << " cents. \n\n";

	

	// Convert US cents to Taiwanese cents

	int TWTotalCents = TotalCents * 33;

		cout << "If you exchanged to Taiwanese Dollars, you would have:\n" << TWTotalCents << " Taiwanese cents!\n";


	//Get Taiwanese cents in terms of US dollars and remainding cents

	int TWTotalDollars = TWTotalCents / 100;

	int TWRemainderCents = TWTotalCents % 100;

	cout << "Which is " << TWTotalDollars << " Taiwanese dollars and " << TWRemainderCents << " cents." << endl;



	// Display a good-bye message

		cout << "\nIt was a pleasure to do this U.S. dollar to Taiwanese dollar conversion for you." << endl;

		cout << "Please enter any character and a return to quit the program." << endl;



	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;




}

//End of the main function.



