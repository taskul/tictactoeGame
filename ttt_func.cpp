#include <iostream>
#include <limits>
#include "ttt.hpp"

using namespace std;

int row;
int col;
// These variables are declared in ttt.hpp
string player_name_1;
string player_name_2;
int winner = 0;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// prints the TIC TAC TOE board
void printboard()
{
    cout << "  0   1   2" << endl; // "   0   1   2
    cout << "0 " << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << endl;
    cout << "  __________" << endl;
    cout << "1 " << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << endl;
    cout << "  __________" << endl;
    cout << "2 " << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << endl;
}

// prints the game intro and rules
void gameIntro()
{
    cout << "Welcome to the game!" << endl
         << "TIC TAC TOE!" << endl
         << "How to play:" << endl
         << "Enter the number for the column and then the row to identify the square you want to play in." << endl
         << endl;
}

// assigns player names
void playerNames()
{
    cout << "Player 1, enter your name:";
    cin >> player_name_1;
    cout << "Hello " << player_name_1 << ", you are X." << endl;
    cout << "Player 2, enter your name:";
    cin >> player_name_2;
    cout << "Hello " << player_name_2 << ", you are O." << endl;
}

// gets the player X's move and checks to make sure it is valid
int movex()
{
    while (true)
    {
        cout << "Column:";
        if (!(cin >> col))
        {
            // Input operation failed (non-integer entered)
            cout << "Invalid input. Please enter an integer for the column." << endl;
            cin.clear();                                         // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            continue;
        }

        cout << "Row:";
        if (!(cin >> row))
        {
            // Input operation failed (non-integer entered)
            cout << "Invalid input. Please enter an integer for the row." << endl;
            cin.clear();                                         // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            continue;
        }

        if (col >= 0 && col <= 2 && row >= 0 && row <= 2 && board[col][row] == ' ')
        {
            board[col][row] = 'X';
            return 0; // This return statement breaks out of the loop
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

// gets the player O's move and checks to make sure it is valid
int moveo()
{
    while (true)
    {
        cout << "Column:";
        if (!(cin >> col))
        {
            // Input operation failed (non-integer entered)
            cout << "Invalid input. Please enter an integer for the column." << endl;
            cin.clear();                                         // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            continue;
        }

        cout << "Row:";
        if (!(cin >> row))
        {
            // Input operation failed (non-integer entered)
            cout << "Invalid input. Please enter an integer for the row." << endl;
            cin.clear();                                         // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            continue;
        }

        if (col >= 0 && col <= 2 && row >= 0 && row <= 2 && board[col][row] == ' ')
        {
            board[col][row] = 'O';
            return 0; // This return statement breaks out of the loop
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

// checks to see if there is a winner
void checkwinner()
{
    if (board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0])
    {
        if (board[0][0] == 'X')
        {
            winner = 1;
        }
        else
        {
            winner = 2;
        }
    }
    else if (board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] == board[2][1])
    {
        if (board[0][1] == 'X')
        {
            winner = 1;
        }
        else
        {
            winner = 2;
        }
    }
    else if (board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2])
    {
        if (board[0][2] == 'X')
        {
            winner = 1;
        }
        else
        {
            winner = 2;
        }
    }
    else if (board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2])
    {
        if (board[0][0] == 'X')
        {
            winner = 1;
        }
        else
        {
            winner = 2;
        }
    }
    else if (board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2])
    {
        if (board[1][0] == 'X')
        {
            winner = 1;
        }
        else
        {
            winner = 2;
        }
    }
    else if (board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2])
    {
        if (board[2][0] == 'X')
        {
            winner = 1;
        }
        else
        {
            winner = 2;
        }
    }
    else if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == 'X')
        {
            winner = 1;
        }
        else
        {
            winner = 2;
        }
    }
    else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == 'X')
        {
            winner = 1;
        }
        else
        {
            winner = 2;
        }
    }
}

// prints the winner
void showwinner()
{
    if (winner == 1)
    {
        cout << "Congrats " << player_name_1 << "! X wins!" << endl;
        system("PAUSE>nul");
    }
    else if (winner == 2)
    {
        cout << "Congrats " << player_name_2 << "! O wins!" << endl;
        system("PAUSE>nul");
    }
}