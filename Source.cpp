/*  Carrik McNerlin
	2/9/2021
	This game generates a random number between  and asks player to guess
*/
#include <iostream>
#include <iomanip>
#include <cstdlib> //use for rand() function
using namespace std;


//change these to adjust range of possible answers
const int lowerLimit = 1;
const int upperLimit = 1000;

//prototype classes that will be fleshed out later
int RandomNum(int lower, int upper);
int Guess(int secretNumber);
int Result (int guesses);

int main(){
	int secretNum, guesses; //keep track of guesses
	string replay = "yes"; //set to "yes" to begin the game
	bool firstGame = true;

	cout << "I'm thinking of a number between " << lowerLimit << " and " << upperLimit << endl;
	cout << "Can you guess my number?";

	//will allow the player to continue playing as long as the first letter of their final response begins with a 'y'
	while (replay[0] == 'y' || replay[0] == 'Y') {
		//only show this dialogue if the player has played already
		if (firstGame == false) {
			cout << "Okay. The number will be between " << lowerLimit << " and " << upperLimit << " again." << endl;
		}else {
			// By making it here, the player is playing their first game, meaning the next time we get to this point will not be.
			firstGame = false; 
		}

		secretNum = RandomNum(lowerLimit, upperLimit); //set up number

		guesses = Guess(secretNum); //play the game

		Result(guesses); // Provide sufficient mockery


		//offer to bully them again
		cout << "Would you like to play again? [y/n]" << endl;
		cin >> replay;
	}
}





// ********************************************************************************************************************
// ACTUALLY DEFINING THE FUNCTIONS
// ********************************************************************************************************************


// Create and return a random number from lower limit to upper limit.
int RandomNum(int lower, int upper) {
	int temp = (lower + rand() % upper);
	return temp;
}

// Allow player to guess repeatedly until they find the correct number.
// This function returns the number of guesses it took for the player to find the correct number.
int Guess(int secretNumber) {
	int currGuess = 0;
	int guesses = 0;

	while (currGuess != secretNumber) {
		cout << "Guess a number between " << lowerLimit << " and " << upperLimit << ":" << endl;
		cin >> currGuess;
		guesses++; //new guess made



		// Verify valid user input
		if ((currGuess > upperLimit) || (currGuess < lowerLimit)) {
			cout << "Invalid input. The number is between " << lowerLimit << " and " << upperLimit << "." << endl;
		}
		//Now we start to actually evaluate whether they're close
		else if (currGuess < secretNumber) {
			cout << "Too low. Try again." << endl;
		}
		else if (currGuess > secretNumber) {
			cout << "Too high. Try again." << endl;
		}
		else {
			cout << "You guessed it!" << endl;
		}
	}

	return guesses;
}


// Mock the player appropriately based on how many guesses it took to find the secret number.
int Result(int guesses) {
	if (guesses < 10) {
		cout << "Do you know the secret or are you just lucky? I'm keeping an eye on you... You guessed " << guesses << " times." << endl;
	}
	else if (guesses == 10) {
		cout << "Clever dog! You know the secret, don't you? You guessed " << guesses << " times." << endl;
	}
	else {
		cout << "You should be able to do better. You guessed " <<guesses << " times." << endl;
		cout << "Try guessing in the middle of the possible answers and then keep using that as the new floor or ceiling for future guesses." << endl;
	}

	return 0; //just to deal with demand for a return
}