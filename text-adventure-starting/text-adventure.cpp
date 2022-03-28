/*
 * Text Adventure Coding Challenge
 */
#include <iostream>

using namespace std;

struct Page {
    string text;
    int options;
    int nextpage[10];
};

const Page gamePages[] = {
{
       "Test. Choose 1 or 2: ",
       2,
       {1,2}
    },
{
        "You've reached choice 1",
        0,
        {}
    },
{
        "You've reached choice 2",
        0,
        {}
    }
};
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

int doPage(int page){
    cout << gamePages[page].text;
    if(gamePages[page].options <= 0)
        return -1;
    int selection;
    cin >> selection;
    while(selection < 1 || selection > gamePages[page].options){
        cout << "That is an invalid selection. Please try again" << endl;
        cin >> selection;
    }
    return gamePages[page].nextpage[selection-1];
}

int storyTest(){
    int currentPage = 0;
    while(currentPage >= 0) {
        currentPage = doPage(currentPage);
    }
    return 0;
}

int main(){
    storyBegins();
    characterCreation();
    storyTest();
}