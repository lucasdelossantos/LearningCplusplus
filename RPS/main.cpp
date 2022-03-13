/**
 * Rock, Paper, Scissors
 */
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main() {

    srand(time(nullptr));

    int computer = rand() % 3 + 1;

    int user = 0;
    cout << "====================\n";
    cout << "rock paper scissors!\n";
    cout << "====================\n";

    cout << "1) rock" << endl;
    cout << "2) paper" << endl;
    cout << "3) scissors" << endl;

    cout << "shoot! ";
    cin >> user;

    if (user == 1) {
        cout << "You throw out rock" << endl;
    }
    else if (user ==2) {
        cout << "You throw out paper" << endl;
    }
    else {
        cout << "You throw out scissors" << endl;
    }

    if (computer == 1) {
        cout << "Computer threw out rock" << endl;
    }
    else if (computer ==2) {
        cout << "Computer threw out paper" << endl;
    }
    else {
        cout << "Computer threw out scissors" << endl;
    }

    /*
     * Rock = 1
     * Paper = 2
     * Scissors = 3
     */

    if (user == computer) {
        cout << "It's a tie. Try again?" << endl;
    }
    else if (user == 1) {
        if (computer == 2) {
            cout << "Loser!" << endl;
        }
        if (computer == 3) {
            cout << "You have destroyed the NPC's scissors!" << endl;
        }
    }

    else if (user == 2) {
        if (computer == 1) {
            cout << "Paper covers Rock! You win!" << endl;
        }
        if (computer == 3) {
            cout << "Loser!" << endl;
        }
    }

    else if (user == 3) {
        if (computer == 1) {
            cout << "Loser!" << endl;
        }
        if (computer == 2) {
            cout << "You have sheared your opponents flimsy paper!" << endl;
        }
    }
}
