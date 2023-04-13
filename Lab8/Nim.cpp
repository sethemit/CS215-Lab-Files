#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Nim.h"

using namespace std;

Nim::Nim(int initializeSize) {
    if (initializeSize < PILE_MIN || initializeSize > PILE_MAX) {
        cout << "Invalid size for pile. Using " << PILE_MIN << " instead." << endl;
        pileSize = PILE_MIN;
    }
    else {
        pileSize = initializeSize;
    }
}
int Nim::getPileSize() const {
    return pileSize;
}
void Nim::print() const {
    int remainingMarbles = pileSize;
    int remainingColumns = WIDTH;
    cout << "There are " << pileSize << " marbles in the pile." << endl;
    cout << "  ";
    while (remainingMarbles > 0) {
        if (remainingColumns > 0) {
            cout << MARBLE << " ";
            remainingColumns--;
            remainingMarbles--;
        } else {
            cout << endl << "  ";
            remainingColumns = WIDTH;
        }
    }
    cout << endl;
}
void Nim::computer_play()
{
    int pow2Table[PILE_MAX]; // array to store the powers of 2
    int computerMoves[PILE_MAX / 2]; // array to store the moves
    int numMoves = 0;       // number of moves         
    int pow2 = 0;           // the largest power of 2
    int move = 0;           // the move to take
    int tempPileSize = 0;   // placeholder for pileSize

    // find all legal moves
    for (int i = 0; i < pileSize; i++) {
        if (pileSize - i != i) {
            computerMoves[numMoves++] = i;
        }
    }

    for (int i = 0; i <= pileSize / 2; i++) {
        pow2Table[i] = ((pow(2, i)) - 1);
        for (int j = 0; j <= pileSize / 2; j++) {
            if (pow2Table[j] == (pileSize-pow2Table[j])) {
                pow2 = pow2Table[j];
                break;
            }
            else {
                if (pow2Table[i] != pileSize) {
                    int randomNum = rand() % pileSize;
                    pow2 = randomNum;
                }
            }
        }
    }
    tempPileSize = pileSize;
    pileSize = pow2;
    move = tempPileSize - pow2;
    cout << "The computer takes " << move << " marbles.\n" << endl;
}