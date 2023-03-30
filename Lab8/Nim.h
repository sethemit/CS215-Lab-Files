/*
 * Course: CS215-00x
 * Project: Lab 8 (as part of Project 2)
 * File: Nim.h
 * Purpose: it declares the class named Nim
 *
 */
#ifndef NIM_H
#define NIM_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

const int PILE_MAX = 250;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10;   // for layout purpose
const int PILE_SIZE_TEST = 50;		//the pile size for testing purpose in Lab8 only

class Nim
{
public:
	//default constructor
	Nim() {
        pileSize = 7; // Initialize with a default pile size
    }

	//constructor
	Nim(int iniSize) {
        if (iniSize < PILE_MIN || iniSize > PILE_MAX) {
        	std::cout << "Invalid pile size. Defaulting to " << PILE_MIN << "." << std::endl;
        	pileSize = PILE_MIN;
    	}
    	else {
        	pileSize = iniSize;
    	}
    }

	//set the current size of the pile 
	void setPileSize(int size) {
        pileSize = size;
    }

	//get how many marbles on the pile
	int getPileSize() const {
        return pileSize;
    }

	//if it is computer's turn to play
	//computer takes a legal move, and takes off some marbles
	//computer alwasys takes "perfect stategy" trying to win
	void computer_play() {
		int legal_moves[PILE_MAX / 2]; // array to store the legal moves
    	int num_legal_moves = 0;       // number of legal moves
    	// find all legal moves
    	for (int i = 1; i <= pileSize / 2; i++) {
        	if (pileSize - i != i) {
            	legal_moves[num_legal_moves++] = i;
        	}
    	}
    	// if there are no legal moves, take one marble
    	if (num_legal_moves == 0) {
        	pileSize--;
    	}
    	else {
        	// calculate the bitwise xor of all the legal moves
        	int xor_sum = 0;
        	for (int i = 0; i < num_legal_moves; i++) {
            	xor_sum ^= legal_moves[i];
        	}
        	// if the xor sum is 0, take a random legal move
        	if (xor_sum == 0) {
            	int index = rand() % num_legal_moves;
            	pileSize -= legal_moves[index];
        	}
        	else {
            	// find the largest power of 2 that is less than or equal to xor_sum
            	int largest_pow_2 = 1;
            	while (largest_pow_2 <= xor_sum) {
                	largest_pow_2 *= 2;
            	}
            	largest_pow_2 /= 2;
            	// take the largest legal move that is less than or equal to largest_pow_2
            	int move = 0;
            	for (int i = 0; i < num_legal_moves; i++) {
                	if (legal_moves[i] & largest_pow_2) {
                    	move = legal_moves[i];
                    	break;
                	}
            	}
            	pileSize -= move;
        	}
    	}
	}

	//if it is human player's (the user's) turn to play
	//comment out in Lab8 only
	//you still need to define this member function in Project2
	//void player_play();

	//display the current marbles on the pile
	void print() const{
		int remainingMarbles = pileSize;
    	int remainingColumns = WIDTH;
    	std::cout << "  ";
    	while (remainingMarbles > 0) {
        	if (remainingColumns > 0) {
            	std::cout << MARBLE << " ";
            	remainingColumns--;
            	remainingMarbles--;
        	} 
			else {
            std::cout << std::endl << "  ";
            remainingColumns = WIDTH;
        	}
    	}
    	std::cout << std::endl;
	}

private:
	int pileSize;	// represents how many marbles on the 
};
#endif	/* NIM_H */
