

/* Program 6A: Haroldo Altamirano
Specification: This program can help you get the general idea of how software such
as Microsoft WORD is implemented. Program should provide services for the
user to enter test scores from the **keyboard** and store the scores in an array, to **write
(save)** the scores currently stored in the array into a given file, to **read** a collection of
test scores that are already stored in a given file into an array, to **display the scores**
currently stored in the array and to calculate and **display the related statistics** of the
scores. */



#include <iostream>  //inclusion of support for doing input & output

#include <fstream> // inclusion of support for file output & input

#include <string> // inclusion of support for string library



using namespace std; //declare access to standard stuff like cin, cout



// Function prototypes

void scoreStats(int, double []);	// Calculate and display average score, lowest score and highest score


// Beginning of main function

int main()

{
	// Declare variables

	string filename;	// to store file name given by user
	ifstream fin;	// for file input
	ofstream fout;	// for file output
	int numStudents = 0;	// store the number of students involved (before being stored in a permanent file)
	double scores[100];	// for storing students' scores
	bool menuInService = true;	// falg for ending menu display
	char menuOption;	// for a user to select a menu option (what function to access)
	int scoreModified;	// for storing what element/score will be modified by the user

	// Display repeating menu with options for user

	while (menuInService)
	{
		// menu text
		cout << "\nThis menu simulates a WORD program \n"
			<< "It allows you to enter, save, read into the program, display and show statistics\n"
			<< "of:	the number of students\n"
			<< "	and their scores.\n\n"
			<< "Please enter the character (i.e. K) of the option you wish to use\n\n"
			<< "----------------------------------- Options ------------------------------------\n\n"
			<< "K - Enter the number of students and their scores\n"
			<< "W - Write to a file the number of students and their scores (Save your input in a file)\n"
			<< "R - Read new values into the program from a file\n"
			<< "D - Display the number of students, scores and some related statistics\n"
			<< "M - Modify one of the scores\n"
			<< "Q - Quit the program\n\n";

		cin >> menuOption;	// user selection


		switch (menuOption)
		{
		case 'k':	// fallthrough
		case 'K':	// Keyboard entry option (user enters information that will be stored in RAM)
			cout << "Enter the number of students (up to 100)\n";

			cin >> numStudents;

			while (numStudents > 100 || numStudents <= 0)	// validate number (array max elements = 100), cannot have negative amount
			{
				cout << "You cannot enter more than 100 scores\n"
					<< "Enter the number of students\n"
					<< "(Number must be from 1 to 100 students)\n";

				cin >> numStudents;
			}
			cout << "Enter their scores\n";

			for (int index = 0; index < numStudents; index++)
			{
				cout << (index + 1) << ". ";	// lists which score (element number) the user is entering


				cin >> scores[index];	// stores each score in a separate element

				while (scores[index] < 0 || scores[index] > 100) // score validation (-1 and less, 101 and more = invalid)
				{
					cout << "You have entered an invalid score\n"
						<< "Please enter a number that is between 0 and 100\n";

					cin >> scores[index];	// reenter
				}
			}
			break;

		case 'w':	// fallthrough
		case 'W':	// write option
			cout << "I will save the data you have entered through the keyboard in a permanent file\n"
				<< "What name do you want to give the file?\n"
				<< "Please add the extension .txt after the name\n"
				<< "Do not put spaces in the file name\n"
				<< "For example enter: myfilename.txt\n";

			cin >> filename;	// input

			while (filename.length() > 20)	// validate length
			{
				cout << "Your file name is too long!\n"
					<< "Please enter a file name of no more than twenty characters\n"
					<< "Make sure the last of these letters is a .txt extension\n"
					<< "i.e. mystudentsfile.txt\n";

				cin >> filename;
			}

			// Write (save) to file

			fout.open(filename);	// open/create file

			fout << numStudents << endl;	// first line is number of students

			for (int index = 0; index < numStudents; index++)
			{
				fout << scores[index] << endl;
			}
			cout << "Your student scores data has been saved in " << filename << endl;


			fout.close();	// close file when finished
			break;

		case 'r':	// fallthrough
		case 'R':	// Read data from file to variables in program
			cout << "Please enter the file name you wish to read student data from\n"
				<< "For example enter: mystudentsfile.txt\n";

			cin >> filename;

			while (filename.length() > 20)	// validate length
			{
				cout << "Your file name is too long!\n"
					<< "Please enter a file name of no more than twenty characters\n"
					<< "Make sure the last of these letters is a .txt extension\n"
					<< "i.e. mystudentsfile.txt\n";

				cin >> filename;
			}

			fin.open(filename);	// open file

			fin >> numStudents; // first line is number of students

			while (numStudents <= 0 || numStudents > 100)	// number of students validation (for scores array)
			{
				cout << "Your file lists an invalid amount of students\n"
					<< "Please make sure you only read data from files with\n"
					<< "1 to 100 students\n\n"
					<< "Please enter a different filename\n"
					<< "For example: mystudentsfile.txt\n";

				cin >> filename;	// reenter input

				while (filename.length() > 20)	// validate length
				{
					cout << "Your file name is too long!\n"
						<< "Please enter a file name of no more than twenty characters\n"
						<< "Make sure the last of these letters is a .txt extension\n"
						<< "i.e. mystudentsfile.txt\n";

					cin >> filename;

					fin >> numStudents; // first line is number of students
				}
			}

			for (int index = 0; index < numStudents; index++)	// store scores in array, stop with number of scores/students
			{
				fin >> scores[index];
			}

			cout << "The data from " << filename << " has been read into the program\n.";

			break;

		case 'd':	// fallthrough
		case 'D':	// Display the number of students, scores and statistics
			if (numStudents > 0)	// if there is data loaded into the program variables
			{
				cout << "I will display the number of students, their scores, and related statistics\n"
					<< "I will display the data read into the program from a file or keyboard entry\n";

				cout << "There are " << numStudents << " students\n"	// Number of students
					<< "Their scores are:\n";

				for (int index = 0; index < numStudents; index++)	// scores
				{
					cout << (index + 1) << ". " << scores[index] << endl;	// list format (start at "1")
				}

				scoreStats(numStudents, scores);	// return average, highest, and lowest scores
			}
			else	// No data = 0 students
			{
				cout << "Please enter student data through the menu first!\n"
					<< "You may use keyboard entry (option K)\n"
					<< "or read the data from a file (option R)\n";
			}
			break;

		case 'm':	// fallthrough
		case 'M':	// ask user to modify scores
			if (numStudents > 0)	// if there is data loaded into the program variables
			{
				cout << " Which of the scores (from 1 to 100) do you wish to modify?\n";

				cin >> scoreModified;

				while (scoreModified > numStudents)	// input validation
				{
					cout << "You have entered a number outside the range\n"
						<< "Please enter a number from 1 to " << numStudents << endl;

					cin >> scoreModified;	// user reenter input
				}

				cout << "You wish to modify: " << scoreModified << ". " << scores[(scoreModified - 1)] << endl // list format (elements start at 0 so compensate)
					<< "Please enter the new score for student number " << scoreModified << ": ";

				cin >> scores[(scoreModified - 1)];
			}
			else	// No data = 0 students, cannot modify
			{
				cout << "Please enter student data through the menu first!\n"
					<< "You may use keyboard entry (option K)\n"
					<< "or read the data from a file (option R)\n";
			}
			break;

		case 'q':	// fallthrough
		case 'Q': menuInService = false;	// stop displaying menu
			break;

		default: cout << "You have entered an invalid character.\n"
			<< "Please select one of the options (K, W, R, D, M or Q)\n";
		}
	}

	// Display a good-bye message

	cout << "Goodbye!" << endl;

	cout << "Please enter any character and a return to quit the program." << endl;



	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;




}

//End of the main function.



// scoreStats;	// Calculate and display average score, lowest score and highest score (from what is read into program)

void scoreStats(int numStudents, double scores[])
{
	// Declare local variables

	double average, highScore, lowScore;	// statistics

	double total = 0;	// accumulator for doing statistics (average)

	// ******************* Calculate average

	for (int index = 0; index < numStudents; index++)
	{
		total += scores[index];
	}
	average = total / numStudents;	// total divided by n terms

	cout << "The average score is " << average << endl;

	// ****************** Calculate highest score

	highScore = scores[0];	// initialize

	for (int index = 0; index < numStudents; index++)
	{
		if (scores[index] > highScore)	// compare to elements
			highScore = scores[index];	// set highest to high score
	}
	
	cout << "The highest score is " << highScore << endl;

	// ***************** Calculate lowest score

	lowScore = scores[0];	// initialize

	for (int index = 0; index < numStudents; index++)
	{
		if (scores[index] < lowScore)	// compare to elements
			lowScore = scores[index];	// set lowest score to low score
	}

	cout << "The lowest score is " << lowScore << endl;
}
