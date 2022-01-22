#pragma once

using namespace std;
#include <iostream>
#include <string>


class Board 
{
	// Declare an array to hold the player objects
	Player playerList[];
	// Declare an array to hold the snake objects
	Snake snakeList[];
	// Declare an array to hold the ladder objects
	Ladder ladderList[];
	public:
		Board(Player players[], Snake snakes[], Ladder ladders[]) {
			playerList = players;
			snakeList = snakes;
			ladderList = ladders;
		};
};

