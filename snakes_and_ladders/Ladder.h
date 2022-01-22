#pragma once

using namespace std;
#include <iostream>
#include <string>

class Ladder
{
	// declare the top of the ladder
	int top;
	// declare the bottom of the ladder
	int bottom;

	public:
		// default class constructor
		Ladder() {};
		// class constructor
		Ladder(int topRung, int bottomRung) {
			top = topRung;
			bottom = bottomRung;
		}

		// create a method that returns the top of the ladder
		int getTopRung() { return top; }
		// create a method that returns the bottom of the ladder
		int getBottomRung() { return bottom; }
};

