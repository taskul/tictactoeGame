
#ifndef SHARED_H
#define SHARED_H

#include <string>
using namespace std;
// These variables are defined in ttt_func.cpp
// ttt.hpp is just passing them to ttt.cpp
extern string player_name_1;
extern string player_name_2;
extern int winner;
#endif

// prints the TIC TAC TOE board
void printboard();
// prints the game intro and rules
void gameIntro();
// assigns player names
void playerNames();
// gets the player X's move and checks to make sure it is valid
int movex();
// gets the player O's move and checks to make sure it is valid
int moveo();
// checks to see if there is a winner
void checkwinner();
// prints the winner
void showwinner();