#include "DataReader.h"
#include <iostream>
#include<fstream>


//read data from a file into an array
void DataReader::readData(std::string fileName)
{
    count = 0;
    std::ifstream fileReder;
    fileReder.open(fileName);
    if (!fileReder) {
        std::cout << "Error opening input file: " << fileName << std::endl;
        return;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fileReder >> data[i][j];
            count++;
        }
    }
    fileReder.close();

}

//Check if a certain integer exist
std::pair<int, int> DataReader::findNumber(int number)
{
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (data[i][j] == number) {
                    return std::make_pair(i, j);
                }
            }
        }
        return std::make_pair(-1, -1);
}

//A function that adds a new integer to the end of the array if the array not full
void DataReader::addNumber(int number)
{
    try {
        if (count >= 100) {
            throw ("Array is full.");
        }
        else
        {
            int row = count / 10;
            int col = count % 10;
            data[row][col] = number;
            count++;
            std::cout << "The number: "<< " " << number << " has been added successfully" << std::endl;
        }
        
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }
}

//A function that can modify the value of an integer when called with the index of the integer in
// the array and return the new value and old value back to the user.
void DataReader::modifyNumber(int index, int number)
{
    try {
        if (index < 0 || index >= count) { // Check if the index is within the range of the array
            throw ("Index out of range.");
        }
        int oldValue = data[index / 10][index % 10]; // Save the old value at the index
        data[index / 10][index % 10] = number;
        std::cout << "Old value: " << oldValue << std::endl;
        std::cout << "New value: " << number << std::endl;
    }
    catch (const char* e) { // Catch invalid argument exceptions and display custome msg. 
        std::cout << e<< std::endl;
    }
}

//
void DataReader::RemoveNumber(int index)
{

    try{
        if (index < 0 || index >= count) {// Check if the index is within the range of the array
            throw ("Index out of range.");
        }
        int oldValue = data[index / 10][index % 10]; // Save the old value at the index

        for (int i = index; i < count - 1; i++) {
            data[i / 10][i % 10] = data[(i + 1) / 10][(i + 1) % 10];
        }
        count--; // Decrement the count of integers in the array

        std::cout << "The value: " << " " << oldValue << " " << "has been removed." << std::endl;
    }

    catch (const char* e) {  // Catch invalid argument exceptions and display custome msg. 
        std::cout << e << std::endl;
    }
}
