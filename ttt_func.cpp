#include <iostream>
#include <limits>
#include <vector>
#include "ttt.hpp"

using namespace std;

int row;
int col;
// These variables are declared in ttt.hpp
string player_name_1;
string player_name_2;
char player_1 = 'X';
char player_2 = 'O';
char winner = ' ';

// creates the board
vector<vector<char>> board(3, vector<char>(3, ' '));

// prints the TIC TAC TOE board
void printboard()
{
    int row_header = 0;
    cout << "    0   1   2\n";
    for (const auto &row : board)
    {
        cout << row_header;
        for (char cell : row)
        {
            cout << " | " << cell;
        }
        cout << '\n';
        row_header++;
    }
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

// gets the player move and checks to make sure it is valid
int makeMove(char player)
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

        if (col >= 0 && col <= 2 && row >= 0 && row <= 2 && board[row][col] == ' ')
        {
            board[row][col] = player;
            return 0; // This return statement breaks out of the loop
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

// checks to see if there is a winner
bool isWinner(char player)
{
    // check rows and columns for winner
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            winner = player;
            return true;
        }
    }

    // check diagonals for winner
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        winner = player;
        return true;
    }

    return false;
}

// prints the winner
void showwinner()
{
    if (winner == 'X')
    {
        cout << "Congrats " << player_name_1 << "! X wins!" << endl;
        system("PAUSE>nul");
    }
    else if (winner == 'O')
    {
        cout << "Congrats " << player_name_2 << "! O wins!" << endl;
        system("PAUSE>nul");
    }
}