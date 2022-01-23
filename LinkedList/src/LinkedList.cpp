//============================================================================
// Name        : LinkedList.cpp
// Author      : Lucas de los Santos
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 3-3 Lists and Searching
//============================================================================

#include <algorithm>
#include <iostream>
#include <ctime>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

//============================================================================
// Linked-List class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a linked-list.
 */
class LinkedList {

private:
    // FIXME (1): Internal structure for list entries, housekeeping variables
    struct Node {
        Bid data;
        Node* nextNode{};
    };
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList();
    virtual ~LinkedList();
    void Append(Bid bid);
    void Prepend(Bid bid);
    void PrintList();
    void Remove(string bidId);
    Bid Search(string bidId);
    int Size() const;
};

/**
 * Default constructor
 */
LinkedList::LinkedList() {
    // FIXME (2): Initialize housekeeping variables
    // Setting from NULL to nullptr as it is a function that tests if a pointer reference is null before the reference is used.
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/**
 * Destructor
 */
LinkedList::~LinkedList() = default;

/**
 * Append a new bid to the end of the list
 */
void LinkedList::Append(Bid bid) {
    // FIXME (3): Implement append logic
    // Create and allocate node
    Node* newNode = new Node;
    //Assign data to the node
    newNode->data = bid;
    // set next pointer of new node to null as it is the last node
    newNode->nextNode = nullptr;

    if(head == nullptr){
        head = tail = newNode;
        ++size;
    }
    else{
        tail->nextNode = newNode;
        tail = newNode;
        ++size;
    }
}

/**
 * Prepend a new bid to the start of the list
 */
void LinkedList::Prepend(Bid bid) {
    // FIXME (4): Implement prepend logic
    // Create and allocate node
    Node* newNode = new Node;
    //Assign data to the node
    newNode->data = bid;
    // set next pointer of new node to null as it is the last node
    newNode->nextNode = nullptr;

    // Test if pointer head is empty
    if(head == nullptr){
        head = tail = newNode;
        ++size;
    }
    // Adding new node to front of list
    else{
        newNode->nextNode = head;
        head = newNode;
        ++size;
    }

}

/**
 * Simple output of all bids in the list
 */
void LinkedList::PrintList() {
    // FIXME (5): Implement print logic
    // set temp as head node
    Node* tmp = head;
    // while tmp, head node of list,  is not null print the info for each node's data in the list
    while(tmp != nullptr){
        cout << tmp->data.bidId << " | " << tmp->data.title << " | " << tmp->data.amount << " | " << tmp->data.fund << endl;
        tmp = tmp->nextNode;
    }
}

/**
 * Remove a specified bid
 *
 * @param bidId The bid id to remove from the list
 */
void LinkedList::Remove(string bidId) {
    // FIXME (6): Implement remove logic
    Node* tmp = head;
    Node* prevNode;
    // test if tmp, set to head, is empty
    if(tmp == nullptr){
        return;
    }
    // if head data matches value for bidId and the next node is null. then delete head.
    else if(head->data.bidId == bidId && head->nextNode == nullptr){
        head = tail = nullptr;
        cout << tmp << endl;
        delete tmp;
    }
    else{
        /** while head is not equal to bidID search using while loop till BidId matches.
         * If during search bidID matches with tmp value then delete node.
         */
        while(tmp->data.bidId != bidId){
            prevNode = tmp;
            tmp = tmp->nextNode;
            // cout << "test" << endl;
            if(tmp->data.bidId == bidId) {
                prevNode->nextNode = tmp->nextNode;
                cout << tmp << endl;
                delete tmp;
            }
        }
    }
}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid LinkedList::Search(string bidId) {
    // FIXME (7): Implement search logic
    Node* tmp = head;
    Node* holder = new Node;
    holder->data.bidId = "";
    // Searches from head node until it finds bidID from command line argument and then returns it to output.
    while(tmp != nullptr){
        cout << tmp->data.bidId << endl;
        if(tmp->data.bidId == bidId){
            return tmp->data;
        }
        tmp = tmp->nextNode;
    }
    /** Use Case: User runs Remove Bid ( Case 5) and then runs Find Bids (Case 4)
     * If BidId has been removed the return statement allows Search to complete.
     * It then moves to the cout output in the case 4 under main.
     * Without this return in place user would get a exit139
     */
    return holder->data;
}

/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size() const {
    return size;
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount
         << " | " << bid.fund << endl;
}

/**
 * Prompt user for bid information
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Load a CSV file containing bids into a LinkedList
 *
 * @return a LinkedList containing all the bids read
 */
void loadBids(string csvPath, LinkedList *list) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser
    csv::Parser file = csv::Parser(csvPath);

    try {
        // loop to read rows of a CSV file
        for (int i = 0; i < file.rowCount(); i++) {

            // initialize a bid using data from current row (i)
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << bid.bidId << ": " << bid.title << " | " << bid.fund << " | " << bid.amount << endl;

            // add this bid to the end
            list->Append(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 *
 * @param arg[1] path to CSV file to load from (optional)
 * @param arg[2] the bid Id to use when searching the list (optional)
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "../eBid_Monthly_Sales_Dec_2016.csv";
        bidKey = "98109";
    }

    clock_t ticks;

    LinkedList bidList;

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter a Bid" << endl;
        cout << "  2. Load Bids" << endl;
        cout << "  3. Display All Bids" << endl;
        cout << "  4. Find Bid" << endl;
        cout << "  5. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bid = getBid();
            bidList.Append(bid);
            displayBid(bid);

            break;

        case 2:
            ticks = clock();

            loadBids(csvPath, &bidList);

            cout << bidList.Size() << " bids read" << endl;

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " milliseconds" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            cout << "++++++++++++++++++" << endl;

            break;

        case 3:
            bidList.PrintList();
            cout << "++++++++++++++++++" << endl;

            break;

        case 4:
            ticks = clock();

            bid = bidList.Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (bid.bidId !="") {
                displayBid(bid);
            } else {
            	cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            cout << "++++++++++++++++++" << endl;

            break;

        case 5:
            // Making a meaningful error vs an exit 139 when trying to use Case 5 more than once for same BidId
            bid = bidList.Search(bidKey);
            if (!bid.bidId.empty()) {
                cout << "Removing " << bidKey << endl;
                bidList.Remove(bidKey);
                cout << "++++++++++++++++++" << endl;
            } else {
                cout << "Bid ID " << bidKey << " not found." << endl;
                cout << "-++++++++++++++++++" << endl;
            }



            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
