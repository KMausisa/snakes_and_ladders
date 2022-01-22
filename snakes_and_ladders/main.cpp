using namespace std;
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>


// import the class header files
#include "Player.h"
#include "Snake.h"
#include "Ladder.h"

// this function creates a die that each player will roll
int rollDie() {
	srand(time(NULL));
	return rand() % 6 + 1;
}

int main() {
	// set the max board space to 100
	int maxSpace = 100;

	// declare a variable to hold the number of players
	int numOfPlayers;

	// ask how many players will play (up to 4)
	cout << "How many people are playing? (Up to 4) \n";

	// store the number of players in a variable
	cin >> numOfPlayers;

	// create a list to hold Player objects
	Player players[4];
	// Create a loop to register each player
	for (int i = 0; i < numOfPlayers; i++) {
		string playerName;
		cout << "Hello Player " << i + 1 << ". Enter your name: ";
		cin >> playerName;
		// Create an object for each player
		Player player("playerName");
		// Store the player in the players list
		players[i] = playerName;
	}

	// create five snake objects
	Snake snake1(36, 6);
	Snake snake2(32, 10);
	Snake snake3(62, 18);
	Snake snake4(88, 24);
	Snake snake5(95, 56);
	// Create an array that holds the snakes on the board
	Snake snakes[5] = {snake1, snake2, snake3, snake4, snake5};

	// create five ladder objects
	Ladder ladder1(38, 1);
	Ladder ladder2(14, 4);
	Ladder ladder3(76, 28);
	Ladder ladder4(67, 50);
	Ladder ladder5(92, 71);
	// Create an array that holds the ladders on the board
	Ladder ladders[5] = { ladder1, ladder2, ladder3, ladder4, ladder5 };

	// Game Loop
	bool playerWon = false;
	while (!playerWon) {
		for (int i = 0; i < numOfPlayers; i++) {
			// store current player in a variable
			Player &currentPlayer = players[i];

			// declare a variable to store the number rolled on the dice
			int numberRolled = 0;

			// declare a variable to store user input
			string rolled;

			// grab the name of the player
			string playerName = currentPlayer.getName();
			cout << "\nIt is " << playerName << "'s turn. Please roll the dice (Type: Roll): ";
			cin >> rolled;
			// Validate the user input
			if (rolled == "Roll" || rolled == "roll") {
				// Roll a random number between 1 and 6
				numberRolled = rollDie();
				// Display the number the player rolled
				cout << playerName << " you rolled " << numberRolled << ".\n";
				
				// validate if the player won
				if (currentPlayer.getSpace() >= 94) {
					// store the number the player needs to roll to win
					int numberNeeded = maxSpace - currentPlayer.getSpace();
					if (numberRolled == numberNeeded) {
						cout << "\nCongratulations " << currentPlayer.getName() << " you won!\n";
						currentPlayer.move(numberRolled);
						playerWon = currentPlayer.checkWinner();
						break;
					} else if (numberRolled < numberNeeded) {
						currentPlayer.move(numberRolled);
					} else {
						cout << "\nYou need to roll a " << numberNeeded << " to win.\n";
					}
				}
				else {
					currentPlayer.move(numberRolled);
				}
				// Display the new space the player is on
				cout << "\n" << playerName << " is now on space " << currentPlayer.getSpace() << ".\n";
			}
			// get the space the player is currently on
			int playerSpace = currentPlayer.getSpace();

			// Loop through the snakes to see if a player is on a head
			for (int i = 0; i < 5; i++) {
				// get the head of the snake
				int head = snakes[i].getHead();

				// if the player is on the head, set their space to the tail
				if (playerSpace == head) {
					currentPlayer.setSpace(snakes[i].getTail());
					cout << "\nOh no! You landed on a snake head!\nYou go down to space " << currentPlayer.getSpace() << ".\n";
				}
			}
			// Loop through the ladders to see if a player is on the bottom
			for (int i = 0; i < 5; i++) {
				// get the bottom of the ladder
				int bottom = ladders[i].getBottomRung();

				// if the player is on the head, set their space to the tail
				if (playerSpace == bottom) {
					currentPlayer.setSpace(ladders[i].getTopRung());
					cout << "\nYesssirrrrr! You landed on the bottom of ladder.\nAll the way up!! You are now on space " << currentPlayer.getSpace() << ".\n";
				}
			}
		}

		// for testing
		// playerWon = true;
	}
	return 0;
}