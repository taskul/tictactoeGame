#include <iostream>
#include "ttt.hpp"
// ttt.hpp header file bring in the following variables: player_name_1, player_name_2, winner

using namespace std;

int main()
{
    gameIntro();
    playerNames();

    while (winner == 0)
    {
        printboard();
        cout << player_name_1 << " turn" << endl;
        movex();
        printboard();
        checkwinner();
        if (winner == 0)
        {
            cout << player_name_2 << " turn" << endl;
            moveo();
            printboard();
            checkwinner();
        }
    }
    showwinner();
}
