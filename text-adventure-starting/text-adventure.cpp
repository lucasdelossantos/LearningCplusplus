/*
 * Text Adventure Coding Challenge
 */
#include <iostream>

using namespace std;


void storyBegins() {
    cout << "Welcome brave soul to a challenge worthy of the heroes of fables." << endl;
    cout << "On this journey your choice will spell your victory or your doom" << endl;
    cout << "However I implore you to remember, the fate of the Gods is inescapable" << endl;
}

void characterCreation() {
    int characterSet = 0;
    cout << "Now it is time to choose your character" << endl;
    cout << "1. Berserker" << endl;
    cout << "2. Archer" << endl;
    cout << "3. Mage" << endl;
    retry:
    cout << "Enter your choice: ";
    cin >> characterSet;

    if (characterSet == 1) {
        cout << "You have chosen Berserker. Let us begin!" << endl;
    }
    else if (characterSet == 2) {
        cout << "You have chosen Archer. Let us begin!" << endl;
    }
    else if (characterSet ==3){
        cout << "You have chosen Mage. Let us begin!" << endl;
    }
    else {
        cout << "You don't listen to instructions very well do you? Chose 1, 2 or 3!" << endl;
        goto retry;
    }
}

int main(){
    storyBegins();
    characterCreation();
}