
#ifndef SHARED_H
#define SHARED_H

#include <string>
using namespace std;
// These variables are defined in ttt_func.cpp
// ttt.hpp is just passing them to ttt.cpp
extern string player_name_1;
extern string player_name_2;
extern char player_1;
extern char player_2;
extern char winner;
#endif

// prints the TIC TAC TOE board
void printboard();
// prints the game intro and rules
void gameIntro();
// assigns player names
void playerNames();
// gets the player's move and checks to make sure it is valid
int makeMove(char player);
// checks to see if there is a winner
bool isWinner(char player);
// prints the winner
void showwinner();