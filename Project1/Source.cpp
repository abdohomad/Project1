#include <iostream>
#include "DataReader.h"


void displayMenu();

int main() {
    DataReader datareader{};
    std::string fileName = "data.txt";
    int choice;
    int number;
    int index;
    std::pair<int, int> result;
    datareader.readData(fileName);
    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        
        case 1:
            std::cout << "Enter a number to find: ";
            std::cin >> number;
            result = datareader.findNumber(number);
            if (result.first == -1) {
                std::cout << "Number not found." << std::endl;
            }
            else {
                std::cout << "Number found at index [" << result.first << "][" << result.second << "]." << std::endl;
            }
            break;
        case 2:
            std::cout << "Enter a new number to add: ";
            std::cin >> number;
            datareader.addNumber(number);
            break;
        case 3:
            std::cout << "Enter an index to modify: ";
            std::cin >> index;
            std::cout << "Enter a new number: ";
            std::cin >> number;
            datareader.modifyNumber(index, number);
            break;
        case 4:
            std::cout << "Enter an index to remove a value: ";
            std::cin >> index;
            
            datareader.RemoveNumber(index);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    }

    return 0;
}

void displayMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Find a number in the array" << std::endl;
    std::cout << "2. Add a new number to the end of the array" << std::endl;
    std::cout << "3. Modify a number at a specific index" << std::endl;
    std::cout << "4. Remove data from the array" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}
