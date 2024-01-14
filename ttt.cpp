#include <iostream>
#include "ttt.hpp"
// ttt.hpp header file bring in the following variables: player_name_1, player_name_2, winner

using namespace std;

int main()
{
    gameIntro();
    playerNames();

    while (winner == ' ')
    {
        printboard();
        cout << player_name_1 << " turn" << endl;
        makeMove(player_1);
        printboard();

        if (!isWinner(player_1))
        {
            cout << player_name_2 << " turn" << endl;
            makeMove(player_2);
            printboard();
            isWinner(player_2);
        }
    }
    // shows the winner if there is one
    showwinner();
}
