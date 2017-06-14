

/* Nim Game Midterm Project. Haroldo Altamirano
A game where one player competes with the computer
The game is about taking or avoding to take the last coin of a "pile."
The game has a settings menu
The game is based on a repeating menu with validation for correct intervals
(that is rejecting taking an invalid number of coins from the pile).
The settings determine: win/lose condition if last coin is taken,
the starting amount of coins in a pile,
and how many coins can be taken per opportunity (the max is changeable, and the minimum is always 0).

The dumb version: Has no "AI" and will always only grab one coin
The smart version: Computer has ability to pick optimal moves, and random moves. The computer favors optimal moves.
The coach version: Computer has above abilities and informs user if their moves are optimal, and if the computers moves are optimal.
In addition, if an optimal move exists and the user does not take the move, the program offers the user to try a different move instead.
In addition, the computer will always ask if instead of performing the optimal move, a random one should be overriden for it. */



#include <iostream>  //inclusion of support for doing input & output

using namespace std; //declare access to standard stuff like cin, cout



// displayMenu - for displaying a repeating menu

void displayMenu(int startingCoins, int maxCoinsEachTurn, bool lastCoinTakenWins, bool userMakesFirstMove)
{
	cout << "Nim Game Coach Version  	Key commands: n,m, w,l, c,u, p,q: \n \n"

		<< "xxxxxxxxxxxxxxxxxxxxxxxxx About Coins xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx \n"

		<< "n: set the NUMBER of coints in the BEGINNING of the game \n"
		<< "m: set the MAXIMUM number of coins allowed to be taken each time \n"
		<< "xxxxxxxxxxxxxxxxxxxxxxxxx About the end game xxxxxxxxxxxxxxxxxxxxxxxx \n"
		<< "w: WIN the game when taking the last coin \n"
		<< "l: LOSE the game when taking the last coint \n"
		<< "xxxxxxxxxxxxxxxxxxxxxxxxx About the first move xxxxxxxxxxxxxxxxxxxxxx \n"
		<< "c: COMPUTER makes the first move \n"
		<< "u: USER makes the first move \n \n"

		<< "xxxxxxxxxxxxxxxxxxxxxxxxx Play the game or Quit xxxxxxxxxxxxxxxxxxxxx \n"
		<< "p: PLAY the game according to the current setting \n"
		<< "q: QUIT the program \n \n"

		<< "xxxxxxxxxxxxxxxxxxxxxxxxx Current Setting xxxxxxxxxxxxxxxxxxxxxxxxxxx \n"
		<< "n=" << startingCoins << ": Number of coins in the beginning \n"
		<< "m=" << maxCoinsEachTurn << ": Maximum number of coins allowed each time: \n";

	if (lastCoinTakenWins) // Variable winning condition (Win or lose if the last coin is taken)
		cout << "WINNER: ";

	else
		cout << "LOSER: ";

	cout << "the player who takes the last coin \n"; // Same sentence as above line, always displayed

	if (userMakesFirstMove) // Variable, who is the first to start, user or computer?

		cout << "USER ";

	else
		cout << "COMPUTER ";


	cout << "to make the first move \n"// Same sentence as above line, always displayed
		<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx \n \n \n";

}



// numCoins function - user sets numbers of coins (Access for settings)

int startingCoinsSelection(int startingCoins) // For being accessed and changing settings for menu and game in main
{
	cout << "How many coins do you want the game to start with? \n";

	cin >> startingCoins;

	return startingCoins; // Returns when called

}



// maxCoins - user sets maximum number of coins that can be taken per turn

int maxCoinsEachTurnSelection(int mCoins, int startingCoins) // For being accessed and changing settings for menu and game in main
{
	cout << "What should be the maximum number of coins allowed to be taken per turn? \n";

	cin >> mCoins;

	while (mCoins > startingCoins)
	{
		cout << "You cannot allow more coins to be taken per turn than the total starting number of coins\n"
			<< "Please enter a number lesser value (i.e. if the starting coins are 12, enter no greater than 11)\n";

		cin >> mCoins;
	}
	return mCoins; // Returns when called
}



// lastCoinWinsSelection - boolean function that determines winning condition (settings)

bool lastCoinTakenWinsSelection(char menuChoice) // Values will be returned to boolean variable in main
{
	if (menuChoice == 'w' ||  menuChoice == 'W') // Last coin wins
		return true;

	if (menuChoice = 'l' || menuChoice == 'L') // Last coin (does not win) loses
		return false;
}



// userMakesFirstMoveSelection - boolean function that determines if computer is the first one to take a move

bool userMakesFirstMoveSelection(char menuChoice) // Values will be returned to boolean variable in main
{
	if (menuChoice == 'c' || menuChoice == 'C') // Computer makes the first move
		return false;

	if (menuChoice = 'u' || menuChoice == 'U') // User makes the first move
		return true;
}



// gameInSession - passes all parameters for settings and starts the game with them. Function ends and delivers who the winner was.

void gameMain(int coinsAtBeginning, int maxCoinsGrabbableEachTurn, bool whoeverGetsLastCoinWins, bool userMakesFirstMove)
{
	// Declare local variables

	int currentCoinsAtPlay = coinsAtBeginning;	// current coins at play, what is in coin pile; initialized from user settings

	bool gameIsInSession = true; // for telling while loop when to stop

	bool usersTurn = userMakesFirstMove; // for telling while loop if it is the user's turn (true) or the computer's turn (false); initialized from user settings
	
	int turnNumber = 1; // for listing what turn the move is made in

	int coinChoice;	// for user & computer to store how many coins to take away from the coin pile at play

	int futureCoinPile = currentCoinsAtPlay; // for storing hypothetical values of k next turn, for validation of user moves

	bool turnsOver = false; // for ending all turns, so that the winner can be announced

	char regretCharacter; // for regretting a move or not

	bool userDoesNotRegret = false; // for storing if user wants to keep his move the same when an optimal move exists

	char endingCharacter; // for storing input, so that the ending message can be seen by the user when the game is over


	// Declare function prototype for computer "input" function (decision tree)

	int computerChoice(int, bool, int); // for decision tree about computer's move

	bool optimalMovePossible(bool, int, int, int); // for testing if no moves are optimal, and prompting the user accordingly

	bool userMoveIsOptimal(bool, int, int, int); // for testing if user's move is optimal

	// Game (turns and win message)

	while (gameIsInSession)
	{
		// Display end game message if there are 0 coins left

		if (turnsOver) // turns are over when there are 0 coins in the pile
		{
			cout << "Computer's comment: ";

			// Display who won based on who took the last turn
			if (usersTurn && whoeverGetsLastCoinWins) // Player was last one to go before coins were 0 (user took last coin)
			{
				cout << "You just took the last coin \n"
					<< "What a great player you are. You won!\n";
			}
			
			if (usersTurn == false && whoeverGetsLastCoinWins) // Computer was last one to go before coins were 0 (computer took last coin)
			{
				cout << "I just took the last coin \n"
					<< "You lost. But we played a good game!\n";
			}

			// Or display who won based on NOT taking the last coin
			if (usersTurn && whoeverGetsLastCoinWins == false) // Player was the last one to go before coins were 0 (user took last coin)
			{
				cout << "You just took the last coin \n"
					<< "You lost. But we played a good game!\n";
			}

			if (usersTurn == false && whoeverGetsLastCoinWins == false) // Computer was last one to go before coins were 0 (computer took last coin)
			{
				cout << "I just took the last coin \n"
					<< "What a great player you are. You won!\n";
			}

			// Display message before quitting game and ask for input

			cout << "Enter c to continue. ";

			cin >> endingCharacter;

			gameIsInSession = false; // end function and return to menu in main
		}
		

		// For Turns (Actions each turn, input/output)

		while (usersTurn && turnsOver == false) // For user's turn
		{
			cout << endl
				<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx \n \n"


				<< turnNumber << ". User's Turn: How many coins do you want to take? "; // Lists turn and asks for input

			cin >> coinChoice; // user input


			// Initialize next turn's situation for testing (make sure user's move will not make pile negative)

			futureCoinPile = currentCoinsAtPlay - coinChoice;

			while (!(coinChoice > 0 && coinChoice <= maxCoinsGrabbableEachTurn) && futureCoinPile < 0) // choice validation, choice must be in range (1 to max), 
				                                                                                   // coin pile must not be negative (activates if true, invalid)
			{
				cout << "You have made an invalid choice.\n"
					<< "Please select to take at least 1 coin and no more than " << maxCoinsGrabbableEachTurn;

				cin >> coinChoice; // reenter user input

			// Recheck that the user's move will not result in a negative coin pile

			futureCoinPile = currentCoinsAtPlay - coinChoice;
			}

			// tests if no good move exists
			
			if (optimalMovePossible(whoeverGetsLastCoinWins, currentCoinsAtPlay, maxCoinsGrabbableEachTurn, coinChoice) == false)
			{
				cout << "There is no good move for the user\n";
			}

			else // if a good move exists then tests if the move played by user matches it or not
			{
				// tests if user's choice is the best move
				if (userMoveIsOptimal(whoeverGetsLastCoinWins, currentCoinsAtPlay, maxCoinsGrabbableEachTurn, coinChoice))
				{
					cout << "Computer's comment: Good job! That is the best move.\n\n"; // Comment it is a good move
				}

				while (userMoveIsOptimal(whoeverGetsLastCoinWins, currentCoinsAtPlay, maxCoinsGrabbableEachTurn, coinChoice) == false
					&& userDoesNotRegret == false)
				{
					cout << "Well! That is NOT the best move.\n"
						<< "Do you want to try again?\n"
						<< "Enter y for yes, anything else to skip: ";

					cin >> regretCharacter; // store y or any character

					cout << endl; // space for clarity

					if (regretCharacter == 'y' || regretCharacter == 'Y') // start process of entering an optimal move instead
					{
						cout << "How many coins would you like to take instead? ";

						cin >> coinChoice;

						// Validate if new move is optimal
						if (userMoveIsOptimal(whoeverGetsLastCoinWins, currentCoinsAtPlay, maxCoinsGrabbableEachTurn, coinChoice))
							cout << "Good job. The best move is indeed " << coinChoice << "\n\n";

						// Validate if new move is valid (coin pile not negative, move is less than max)

						while (currentCoinsAtPlay - coinChoice < 0 || coinChoice > maxCoinsGrabbableEachTurn)
						{
							cout << "That move is invalid!. It results in having a negative number of coins next turn\n"
								<< "Or you are attempting to take more coins allowed than the game options specify. \n\n"
								<< "Please make a different move that will result in a coin pile that\n"
								<< "is 0 or greater\n"
								<< "Also make sure you do not take more coins than " << maxCoinsGrabbableEachTurn << endl;

							cin >> coinChoice;
						}
					}
					else
					{
						userDoesNotRegret = true; // user decides to not regret

						// Validate if new move is valid (coin pile not negative, move is less than max)

						while (currentCoinsAtPlay - coinChoice < 0 || coinChoice > maxCoinsGrabbableEachTurn)
						{
							cout << "That move is invalid!. It results in having a negative number of coins next turn\n"
								<< "Or you are attempting to take more coins allowed than the game options specify. \n\n"
								<< "Please make a different move that will result in a coin pile that\n"
								<< "is 0 or greater\n"
								<< "Also make sure you do not take more coins than " << maxCoinsGrabbableEachTurn << endl;

							cin >> coinChoice;
						}
					}
				}
			}
			cout << "You took " << coinChoice << " from " << currentCoinsAtPlay << " coins;"; // displays user input and remaining coins in the pile
																							// (before any deductions are made from the pile)

			// Take away from the pile

			currentCoinsAtPlay = currentCoinsAtPlay - coinChoice;

			// Continue displaying output

			cout << " now " << currentCoinsAtPlay << " coins are left\n\n";

			if (currentCoinsAtPlay > 0) // If the game has not ended, switch the turn to the computer
			{
				usersTurn = false;
				turnNumber++; // Update turn number for next player
			}
			else
				turnsOver = true;	// There can be no more turns (0 in coin pile)

			// Reset testing variable

			futureCoinPile = currentCoinsAtPlay;
		}



		while (usersTurn == false && turnsOver == false)	//For computer's turn
		{
			cout << endl
				<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx \n \n";


			// Get computer's move

			coinChoice = computerChoice(maxCoinsGrabbableEachTurn, whoeverGetsLastCoinWins, currentCoinsAtPlay); 

			cout << turnNumber << ". Computer's Turn: " // Lists turn, starts sentence
			<< "Took " << coinChoice << " from " << currentCoinsAtPlay << " coins;"; // displays computer input and remaining coins in the pile
																						// (before any deductions are made from the pile)

			// Take away from the pile

			currentCoinsAtPlay = currentCoinsAtPlay - coinChoice;

			// Continue displaying output

			cout << " now " << currentCoinsAtPlay << " coins are left\n\n";

			if (currentCoinsAtPlay > 0) // If the game has not ended, switch the turn to the user
			{
				usersTurn = true;
				turnNumber++; // Update turn number for next player
			}
			else
				turnsOver = true;	// There can be no more turns (0 in coin pile)

		}
	}
	
}



// computerChoice - returns amount of coins to be taken during game turns for computer

int computerChoice(int maxCoinsGrabbableEachTurn, bool whoeverGetsLastCoinWins, int currentCoinsAtPlay) // relevant game settings passed, and current coins at play
{
	// Declare local variables

	bool optimalMoveExists = false; // for storing if a best move exists

	int bestMove;	// reserved for storing the optimal move

	char moveCharacter;	// for storing if the user wants to allow the computer to make the best move

	int opponentsCoinsAtPlay; // for storing a temporary value (what will be the opponent's situation next turn)

	int count = 0; // for counting the number of attemps to get a valid random move

	int possibleRandomMove;	// for storing a random move that will be tested, so that it does not result in a negative coin pile

	// Choose differently according to win condition

	if (whoeverGetsLastCoinWins)
	{

		if (currentCoinsAtPlay % (maxCoinsGrabbableEachTurn + 1) != 0) // k % (m+1) != 0, an optimal move exists, do an optimal move
		{
			// Find optimal move: Test each move to see if one will make opponent be in a bad position, start from maximum coins allowed (faster game)
			// End search when the highest allowed optimal move is found

			for (int possibleMove = maxCoinsGrabbableEachTurn; possibleMove > 0 && optimalMoveExists == false; possibleMove--)
			{
				opponentsCoinsAtPlay = currentCoinsAtPlay - possibleMove; // For testing the future outcome of taking this number of coins


				if (opponentsCoinsAtPlay % (maxCoinsGrabbableEachTurn + 1) == 0 && opponentsCoinsAtPlay >= 0) // This future situation will
																									// be bad for opponent and is a legal move
				{
					optimalMoveExists = true; // flag for ending for loop

					bestMove = possibleMove; // This is an optimal move, store it to play this in the game
				}

				if (opponentsCoinsAtPlay == 0) // This is the best move because it will win the game (grab all coins in the pile immediately
				{
					optimalMoveExists = true; // flag for ending for loop

					bestMove = possibleMove; // assign winning move
				}
			}
		}
	}

	else if (whoeverGetsLastCoinWins == false) // When win condition is last coin loses the game, computer performs different strategy
	{

		if ((currentCoinsAtPlay - 1) % (maxCoinsGrabbableEachTurn + 1) != 0) // (k-1) % (m+1) != 0, an optimal move exists, do an optimal move
		{
			// Find optimal move: Test each move to see if one will make opponent be in a bad position, start from maximum coins allowed (faster game)
			// End search when the highest allowed optimal move is found

			for (int possibleMove = maxCoinsGrabbableEachTurn; possibleMove <= maxCoinsGrabbableEachTurn && optimalMoveExists == false; possibleMove--)
			{
				opponentsCoinsAtPlay = currentCoinsAtPlay - possibleMove; // For testing the future outcome of taking this number of coins

				if ((opponentsCoinsAtPlay - 1) % (maxCoinsGrabbableEachTurn + 1) == 0 && opponentsCoinsAtPlay >= 0) // This future situation will be bad for opponent
																												// and is a legal viable move (coin pile cannot be negative)
				{
					optimalMoveExists = true; // flag for ending for loop

					bestMove = possibleMove; // This is an optimal move, store it to play this in the game
				}
			}
		}

	}
	

	// inform user about optimal move for acceptance/rejectal and coaching functionality

	if (optimalMoveExists)
	{
		cout << "I am going to make the best move: take " << bestMove << endl
			<< "Do you want me to make a random move instead? \n"
			<< "Enter y for yes, anything else to skip: ";

		cin >> moveCharacter; // store y or any character

		cout << endl; // space for clarity


		if (moveCharacter == 'y' || moveCharacter == 'Y')
		{	// return a random move instead

			possibleRandomMove = rand() % maxCoinsGrabbableEachTurn + 1; // according to given formula


			if (currentCoinsAtPlay - possibleRandomMove >= 0)	// return a random move instead, coin pile at least 0
				return possibleRandomMove;
			else
			{
				while (currentCoinsAtPlay - possibleRandomMove >= 0, count > 5)
				{
					possibleRandomMove = rand() % maxCoinsGrabbableEachTurn + 1; // keep generating a random move until one is viable

					count++;

					if (currentCoinsAtPlay - possibleRandomMove >= 0) // if valid move found return it
						return possibleRandomMove;
				}

				if (count = 5)
					return 1;	// if it takes too long return a value that will always work
			}
		}
		else
			return bestMove; // return optimal move as computer's choice in the game turn
	}

	else // No good move exists, do a random move
	{
		cout << "There is no good move for the Computer\n";

		// return a random move instead

		possibleRandomMove = rand() % maxCoinsGrabbableEachTurn + 1; // according to given formula


		if (currentCoinsAtPlay - possibleRandomMove >= 0)	// return a random move, coin pile at least 0 after
			return possibleRandomMove;
		else
		{
			while (currentCoinsAtPlay - possibleRandomMove >= 0, count > 5)
			{
				possibleRandomMove = rand() % maxCoinsGrabbableEachTurn + 1; // keep generating a random move until one is viable

				count++;

				if (currentCoinsAtPlay - possibleRandomMove >= 0) // if valid move found return it
					return possibleRandomMove;
			}

			if (count = 5)
				return 1;	// if it takes too long return a value that will always work
		}
	}
}



// userMoveIsOptimal - Tests if a move is optimal for user

bool userMoveIsOptimal(bool whoeverGetsLastCoinWins, int currentCoinsAtPlay, int maxCoinsGrabbableEachTurn, int coinChoice) // Win condition,
																								/// max coins allowed, current coins in pile
{
	// Declare local variable

	bool optimalMoveExists = false; // trigger for ending the for loop once optimal move is found

	int bestMove; // for storing the best calculated move and comparing it to user's choice

	int opponentsCoinsAtPlay; // for storing a temporary value (what will be the opponent's situation next turn)

	if (whoeverGetsLastCoinWins)
	{

		if (currentCoinsAtPlay % (maxCoinsGrabbableEachTurn + 1) != 0) // k % (m+1) != 0, an optimal move exists, do an optimal move
		{
			// Find optimal move: Test each move to see if one will make opponent be in a bad position, start from maximum coins allowed (faster game)
			// End search when the highest allowed optimal move is found

			for (int possibleMove = maxCoinsGrabbableEachTurn; possibleMove > 0 && optimalMoveExists == false; possibleMove--)
			{
				opponentsCoinsAtPlay = currentCoinsAtPlay - possibleMove; // For testing the future outcome of taking this number of coins


				if (opponentsCoinsAtPlay % (maxCoinsGrabbableEachTurn + 1) == 0 && opponentsCoinsAtPlay >= 0) // This future situation will
					// be bad for opponent and is a legal move
				{
					optimalMoveExists = true; // flag for ending for loop

					bestMove = possibleMove; // This is an optimal move, store it to play this in the game
				}

				if (opponentsCoinsAtPlay == 0) // This is the best move because it will win the game (grab all coins in the pile immediately
				{
					optimalMoveExists = true; // flag for ending for loop

					bestMove = possibleMove; // assign winning move
				}


			}
		}
		else
			optimalMoveExists = false; // Optimal move cannot exist if above is not true. k % (m+1) == 0
	}

	else if (whoeverGetsLastCoinWins == false) // When win condition is last coin loses the game, computer performs different strategy
	{

		if ((currentCoinsAtPlay - 1) % (maxCoinsGrabbableEachTurn + 1) != 0) // (k-1) % (m+1) != 0, an optimal move exists, do an optimal move
		{
			// Find optimal move: Test each move to see if one will make opponent be in a bad position, start from maximum coins allowed (faster game)
			// End search when the highest allowed optimal move is found

			for (int possibleMove = maxCoinsGrabbableEachTurn; possibleMove <= maxCoinsGrabbableEachTurn && optimalMoveExists == false; possibleMove--)
			{
				opponentsCoinsAtPlay = currentCoinsAtPlay - possibleMove; // For testing the future outcome of taking this number of coins

				if ((opponentsCoinsAtPlay - 1) % (maxCoinsGrabbableEachTurn + 1) == 0 && opponentsCoinsAtPlay >= 0) // This future situation will be bad for opponent
																											// and will not result in an invalid negative coin pile
				{
					optimalMoveExists = true; // flag for ending for loop

					bestMove = possibleMove; // This is an optimal move, store it to play this in the game
				}
			}
		}

		else
			optimalMoveExists = false; // Optimal move cannot exist if above is not true. (k-1) % (m+1) = 0

	}

	// Compare calculated optimal move to user's

	// 
	if (optimalMoveExists == true && coinChoice == bestMove)
	{
		return true; // user move is optimal
	}

	else
		return false; // user move is not optimal
}


// 

bool optimalMovePossible(bool whoeverGetsLastCoinWins, int currentCoinsAtPlay, int maxCoinsGrabbableEachTurn, int coinChoice) // Win condition,
	/// max coins allowed, current coins in pile
{
	// Declare local variable

	bool optimalMoveExists = false; // flag for ending for loop (search for optimal move) nad returning a value at end of function

	int opponentsCoinsAtPlay; // for storing a temporary value (what will be the opponent's situation next turn)

	if (whoeverGetsLastCoinWins)
	{

		if (currentCoinsAtPlay % (maxCoinsGrabbableEachTurn + 1) != 0) // k % (m+1) != 0, an optimal move exists, do an optimal move
		{
			// Find optimal move: Test each move to see if one will make opponent be in a bad position, start from maximum coins allowed (faster game)
			// End search when the highest allowed optimal move is found

			for (int possibleMove = maxCoinsGrabbableEachTurn; possibleMove > 0 && optimalMoveExists == false; possibleMove--)
			{
				opponentsCoinsAtPlay = currentCoinsAtPlay - possibleMove; // For testing the future outcome of taking this number of coins


				if (opponentsCoinsAtPlay % (maxCoinsGrabbableEachTurn + 1) == 0 && opponentsCoinsAtPlay >= 0) // This future situation will
																									// be bad for opponent and is a legal move
				{
					optimalMoveExists = true; // flag for ending for loop

				}

				if (opponentsCoinsAtPlay == 0) // This is the best move because it will win the game (grab all coins in the pile immediately
				{
					optimalMoveExists = true; // flag for ending for loop
				}
			}
		}
	}

	else if (whoeverGetsLastCoinWins == false) // When win condition is last coin loses the game, computer performs different strategy
	{

		if ((currentCoinsAtPlay - 1) % (maxCoinsGrabbableEachTurn + 1) != 0) // (k-1) % (m+1) != 0, an optimal move exists, do an optimal move
		{
			// Find optimal move: Test each move to see if one will make opponent be in a bad position, start from maximum coins allowed (faster game)
			// End search when the highest allowed optimal move is found

			for (int possibleMove = maxCoinsGrabbableEachTurn; possibleMove <= maxCoinsGrabbableEachTurn && optimalMoveExists == false; possibleMove--)
			{
				opponentsCoinsAtPlay = currentCoinsAtPlay - possibleMove; // For testing the future outcome of taking this number of coins

				if ((opponentsCoinsAtPlay - 1) % (maxCoinsGrabbableEachTurn + 1) == 0 && opponentsCoinsAtPlay >= 0) // This future situation will be bad for opponent
																												// And is a legal move (coin pile cannot be negative)
				{
					optimalMoveExists = true; // flag for ending for loop
				}
			}
		}

	}
	
	return optimalMoveExists;
}
// Beginning of main function

int main()

{

	// Declaration of variables

	bool menuInProcess = 1;	// determines if menu should continue running

	char menuChoice;             // for selecting settings, playing or quitting

	// Settings variables:

	int startingCoins = 12;	// coins at the start of the game, default 12

	int maxCoinsEachTurn = 3; // maximum amount of coins to be taken per turn, default 3

	bool lastCoinTakenWins = true;	/* for storing what the win condition is,
									 default = player who take last coin wins */

	bool userMakesFirstMove = true;



	// display repeating menu

	while (menuInProcess)
	{
		displayMenu(startingCoins, maxCoinsEachTurn, lastCoinTakenWins, userMakesFirstMove); // Passes all stored settings as parameters

		if (!(cin >> menuChoice)) // For invalid data types
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "That is an invalid option. \n"
				<< "Please enter anyone of the valid key commands listed. \n";
		}

		switch (menuChoice)
		{
		case 'n': // fallthrough
		case 'N': startingCoins = startingCoinsSelection(startingCoins); // prompts for user defined setting, coins at beginning; sets the coins at the beginning
			break;

		case 'm': // fallthrough
		case 'M': maxCoinsEachTurn = maxCoinsEachTurnSelection(maxCoinsEachTurn, startingCoins); // prompts for user defined setting, max coins each turn; sets max coins per turn 
			break;

		case 'w': // fallthrough
		case 'W': lastCoinTakenWins = lastCoinTakenWinsSelection(menuChoice); // changes the win condition settings of the game (Last coin taken wins the game
			break;															// based on the character entered previously (for the menu selection)

		case 'l': // fallthrough
		case 'L': lastCoinTakenWins = lastCoinTakenWinsSelection(menuChoice); // changes the win condition settings of the game (Last coin taken loses the game)
			break;															// based on the character entered previously (for the menu selection)

		case 'c': // fallthrough
		case 'C': userMakesFirstMove = userMakesFirstMoveSelection(menuChoice); // changes the first player settings of the game (Computer goes first)
			break;															// based on the character entered previously (for the menu selection)

		case 'u': // fallthrough
		case 'U': userMakesFirstMove = userMakesFirstMoveSelection(menuChoice); // changes the first player settings of the game (User goes first)
			break;															// based on the character entered previously (for the menu selection)

		case 'p': // fallthrough
		case 'P': gameMain(startingCoins, maxCoinsEachTurn, lastCoinTakenWins, userMakesFirstMove); // Start playing the game
			break;

		case 'q': // fallthrough
		case 'Q': return 0;	// Quit the program
			break;

		default:
			cout << "You have entered an invalid choice. Please enter one of key commands (n, m, w, l, c, u, p, q\n";
		}
	}


	// Display a good-bye message

	cout << "It is a pleasure to do this mile-to-kilometer conversion for you." << endl;

	cout << "Please enter any charcter and a return to quit the program." << endl;



	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;




}

//End of the main function.



