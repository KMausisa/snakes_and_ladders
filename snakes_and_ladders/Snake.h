#pragma once

using namespace std;
#include <iostream>
#include <string>

class Snake
{
	// declare the head of the snake
	int head;
	// declare the tail of the snake	
	int tail;

	public:
		// default class constructor
		Snake() {};
		// class constructor
		Snake(int snakeHead, int snakeTail) {
			head = snakeHead;
			tail = snakeTail;
		}

		// create a method that returns the head
		int getHead() { return head; }
		// create a method that returns the tail
		int getTail() { return tail; }
		
};


