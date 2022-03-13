#include <iostream>

using namespace std;

int main(){
    int gryffindor = 0;
    int hufflepuff = 0;
    int ravenclaw = 0;
    int slytherin = 0;

    int answer1 = 0;
    int answer2 = 0;
    int answer3 = 0;
    int answer4 = 0;

    int max = 0;
    string house;

    cout << "===============================" << endl;
    cout << "The Sorting Hat Quiz has begun!" << endl;
    cout << "===============================" << endl;
    cout << "Q1) When I'm dead, I want people to remember me as: " << endl;
    cout << "1) The Good" << endl;
    cout << "2) The Great" << endl;
    cout << "3) The Wise" << endl;
    cout << "4) The Bold" << endl;
    cout << "Choose Wisely: ";
    cin >> answer1;
    if (answer1 == 1) {
        hufflepuff++;
        cout << "1 point for HufflePuff!" << endl;
    }
    else if (answer1 == 2) {
        slytherin++;
        cout << "1 point for Slytherin!" << endl;
    }
    else if (answer1 == 3) {
        ravenclaw++;
        cout << "1 point for Ravenclaw!" << endl;
    }
    else if (answer1 == 4) {
        gryffindor++;
        cout << "1 point for Gryffindor!" << endl;
    }
    else {
        cout << "Invalid input" << endl;
    }
    cout << "Q2) Dawn or Dusk?" << endl;
    cout << "1) Dawn" << endl;
    cout << "2) Dusk" << endl;
    cout << "Choose Wisely: ";
    cin >> answer2;
    if (answer2 == 1) {
        gryffindor++;
        ravenclaw++;
    }
    else if (answer2 == 2) {
        hufflepuff++;
        slytherin++;
    }
    else {
        cout << "Invalid input" << endl;
    }
    cout << "Q3) Which kind of instrument most pleases your ear?" << endl;
    cout << "1) The violin" << endl;
    cout << "2) The trumpet" << endl;
    cout << "3) The piano" << endl;
    cout << "4) The drum" << endl;
    cout << "Choose Wisely: ";
    cin >> answer3;
    if (answer3 == 1) {
        slytherin++;
        cout << "1 point for Slytherin!" << endl;
    }
    else if (answer3 == 2) {
        hufflepuff++;
        cout << "1 point for Hufflepuff!" << endl;
    }
    else if (answer3 == 3) {
        ravenclaw++;
        cout << "1 point for Ravenclaw!" << endl;
    }
    else if (answer3 == 4) {
        gryffindor++;
        cout << "1 point for Gryffindor!" << endl;
    }
    else {
        cout << "Invalid input" << endl;
    }
    cout << "Q4) Which road tempts you most?" << endl;
    cout << "1) The wide, sunny grassy lane" << endl;
    cout << "2) The narrow, dark, lantern-lit alley" << endl;
    cout << "3) The twisting, leaf-strewn path through woods" << endl;
    cout << "4) The cobbled street lined (ancient buildings)" << endl;
    cout << "Choose Wisely: ";
    cin >> answer4;
    if (answer4 == 1) {
        hufflepuff++;
        cout << "1 point for Hufflepuff!" << endl;
    }
    else if (answer4 == 2) {
        slytherin++;
        cout << "1 point for Slytherin!" << endl;
    }
    else if (answer4 == 3) {
        gryffindor++;
        cout << "1 point for Gryffindor!" << endl;
    }
    else if (answer4 == 4) {
        ravenclaw++;
        cout << "1 point for Ravenclaw!" << endl;
    }
    else {
        cout << "Invalid input" << endl;
    }

    if (gryffindor > max) {

        max = gryffindor;
        house = "Gryffindor";

    }

    if (hufflepuff > max) {

        max = hufflepuff;
        house = "Hufflepuff";

    }

    if (ravenclaw > max) {

        max = ravenclaw;
        house = "Ravenclaw";

    }

    if (slytherin > max) {

        max = slytherin;
        house = "Slytherin";

    }

    cout << house << "!\n";

}