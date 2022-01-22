#pragma once

using namespace std;
#include <iostream>
#include <string>

class Player
{
	// declare the name of the player
	string name;
	// declare the space that the player will hold on the board
	int space;
	// declare a boolean that holds if the player has won or not
	bool win;

	public:
		// default class constructor
		Player() {};
		// class constructor
		Player(string playerName) {
			/*
			 * This constructor initializes the member variables 
			 * that were declared above. All players will start on space 0.
			 * 
			 * Parameters:
			 *	string name => The name of the player
			 */
			name = playerName;
			space = 0;
			win = false;
		}

		int getSpace() const {
			// This method returns the space the player is currently on.
			return space;
		}

		string getName() {
			// This method returns the name of the player
			return name;
		}

		void setSpace(int newSpace) {
			// This method returns a new spce if the player lands on a snake or ladder
			space = newSpace;
		}

		void move(int numberRolled) {
			// This method moves the player depending on the amount they rolled.
			space += numberRolled;
		}

		bool checkWinner() {
			// This method returns true if the player won
			return (space == 100) ? win = true : win = false;
		}


};

