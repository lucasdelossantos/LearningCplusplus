//============================================================================
// Name        : VectorSorting.cpp
// Author      : Lucas de los Santos
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Vector Sorting Algorithms
//============================================================================

#include <algorithm>
#include <iostream>
#include <ctime>
#include <vector>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid : public error_code {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;

    Bid() {
        amount = 0.0;
    }
};

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(const Bid& bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
         << bid.fund << endl;
}

/**
 * Prompt user for bid information using console (std::in)
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
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
vector <Bid> loadBids(string csvPath) {
    cout << "Loading CSV file " << csvPath << endl;

    // Define a vector data structure to hold a collection of bids.
    vector <Bid> bids;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    try {
        // loop to read rows of a CSV file
        for (int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bids.push_back(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
    return bids;
}

// FIXME (2a): Implement the quick sort logic over bid.title

/**
 * Partition the vector of bids into two parts, low and high
 *
 * @param bids Address of the vector<Bid> instance to be partitioned
 * @param begin Beginning index to partition
 * @param end Ending index to partition
 */

/**
 * Experimented wth setting the pivot to end and beginning but due to size of the total vector the performance was slower
 * From reading a few articles it is best for performance to find a middle point if both ends are very small or large. Used pivot = (begin + (end-begin)/2 to avoid arithermic overflow.
 * Source: https://www.quora.com/Why-is-it-a-bad-idea-to-make-start+end-2-the-pivot-in-merge-sort
*/
int partition(vector <Bid>& bids, int begin, int end) {
    //cout << begin << endl;
    //cout << end << endl;
    int pivot = (begin + (end - begin) / 2);
    //cout << pivot << endl;
    bool finished = false;

    /** While loops increments the title low element as long as it's below the pivot element
    *   Also while not finished it decrements the high element when it is above the pivot element
     *   Utlizing string::compare due to bid.title being a string object (https://www.cplusplus.com/reference/string/string/compare/)
    */
    while(!finished) {

        while(bids[begin].title.compare(bids[pivot].title) < 0) {
            ++begin;
        }

        while(bids[pivot].title.compare(bids[end].title) < 0) {
            --end;
        }

        /** Comparing begin to end. If begin is greater than or equal to end variable finished equals true and breaks the while loop.
        * However, if begin is not greater than or equal to end the elements are swapped.
        * Begin is then incremented and end is decremented and thus bringing the points closer
        */
        if (begin >= end) {
            finished = true;

        } else {
            swap(bids[begin] , bids[end]);
            ++begin;
            --end;
        }
    }
    return end;
}


/**
 * Perform a quick sort on bid title
 * Average performance: O(n log(n))
 * Worst case performance O(n^2))
 *
 * @param bids address of the vector<Bid> instance to be sorted
 * @param begin the beginning index to sort on
 * @param end the ending index to sort on
 */

/**
 * quickSort utilizes int partition, it sets a middle variable that is eqyal to the outcome of partition.
 * 1st call post middle set sorts the beginning element to the middle element
 * 2nd call takes middle plus 1 as its start point and sorts to end element
 * Outcome of sort alphabetizes the list.
 */

void quickSort(vector <Bid>& bids, int begin, int end) {
    unsigned int middle = 0;

    /**
     * Verifies whether begin is greater than or equal to end.
     * Once true the algorithm stops running if there are 1 or 0 bids left to sort
    */

    if (begin >= end) {
        return;
    }

    /**
     * Calls partition to break total loaded elements into two sections: high and low
     */
    middle = partition(bids, begin, end);
    // cout << middle << endl;

    /**
     * Call 1 sorting elements from beginning element to middle element
     * Call 2 sorting elements from middle +1 to end element
     */
    quickSort(bids, begin, middle);
    quickSort(bids, middle + 1, end);

}



// FIXME (1a): Implement the selection sort logic over bid.title

/**
 * Perform a selection sort on bid title
 * Average performance: O(n^2))
 * Worst case performance O(n^2))
 *
 * @param bid address of the vector<Bid>
 *            instance to be sorted
 */
void selectionSort(vector <Bid> &bids) {
    /**
     * Setting minimum and maximum size of vector to use in for loop for sorting
     */
    unsigned int smallest;
    unsigned int largest = bids.size();
    // cout << largest << endl;

    /**
    * Place sets the position at which bids are sorted/unsorted and increments place by 1 every loop
    */
    for (unsigned place = 0; place < largest; ++place) {
        smallest = place;
        // cout << smallest << endl;
        /**
         * Find the minimum element in unsorted array
         */
        for (unsigned j = place + 1; j < largest; ++j) {
            if (bids[j].title.compare(bids[smallest].title) < 0) {
                smallest = j;
            }
        }
        /**
         * Swap the found minimum element with the first element
         */
        if (smallest != place)
            swap(bids[place], bids[smallest]);
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
 */
int main(int argc, char *argv[]) {

    // process command line arguments
    string csvPath;
    switch (argc) {
        case 2:
            csvPath = argv[1];
            break;
        default:
            csvPath = "../eBid_Monthly_Sales.csv";
    }

    // Define a vector to hold all the bids
    vector <Bid> bids;

    // Define a timer variable
    clock_t ticks;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Selection Sort All Bids" << endl;
        cout << "  4. Quick Sort All Bids" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                // Initialize a timer variable before loading bids
                ticks = clock();

                // Complete the method call to load the bids
                bids = loadBids(csvPath);

                cout << bids.size() << " bids read" << endl;

                // Calculate elapsed time and display result
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

                break;

            case 2:
                // Loop and display the bids read
                for (auto & bid : bids) {
                    displayBid(bid);
                }
                cout << endl;

                break;

                // FIXME (1b): Invoke the selection sort and report timing results
            case 3:
                ticks = clock();

                // call selectionSort method to sort the loaded bids
                selectionSort(bids);

                cout << bids.size() << " bids read" << endl;

                // Calculate elapsed time and display result
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

                break;

                // FIXME (2b): Invoke the quick sort and report timing results
            case 4:
                ticks = clock();
                // call quickSort method to sort the loaded bids
                quickSort(bids, 0, bids.size() - 1);
                cout << bids.size() << " bids read" << endl;

                // Calculate elapsed time and display result
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

                break;

        }
    }

    cout << "Good bye." << endl;

    return 0;
}
