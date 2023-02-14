#include <iostream>
#include <fstream>
#include "DataReader.h"

using namespace std;


void displayMenu();

int main() {
    DataReader datareader{};
    string fileName = "data.txt";
    int choice;
    int number;
    int index;
    pair<int, int> result;
    datareader.readData(fileName);
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        
        case 1:
            cout << "Enter a number to find: ";
            cin >> number;
            result = datareader.findNumber(number);
            if (result.first == -1) {
                cout << "Number not found." << endl;
            }
            else {
                cout << "Number found at index [" << result.first << "][" << result.second << "]." << endl;
            }
            break;
        case 2:
            cout << "Enter a new number to add: ";
            cin >> number;
            datareader.addNumber(number);
            break;
        case 3:
            cout << "Enter an index to modify: ";
            cin >> index;
            cout << "Enter a new number: ";
            cin >> number;
            datareader.modifyNumber(index, number);
            break;
        case 4:
            cout << "Enter an index to remove a value: ";
            cin >> index;
            
            datareader.RemoveNumber(index);
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    return 0;
}

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Find a number in the array" << endl;
    cout << "2. Add a new number to the end of the array" << endl;
    cout << "3. Modify a number at a specific index" << endl;
    cout << "4. Remove data from the array" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}
