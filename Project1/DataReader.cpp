#include "DataReader.h"
#include <iostream>
#include<fstream>
using namespace std;


void DataReader::readData(string fileName)
{
    count = 0;
    ifstream fileReder;
    fileReder.open(fileName);
    if (!fileReder) {
        cout << "Error opening input file: " << fileName << endl;
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

pair<int, int> DataReader::findNumber(int number)
{
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (data[i][j] == number) {
                    return make_pair(i, j);
                }
            }
        }
        return make_pair(-1, -1);
}

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
            cout << "The number: "<< " " << number << " has been added successfully" << endl;
        }
        
    }
    catch (const char* e) {
        cout << e << endl;
    }
}

void DataReader::modifyNumber(int index, int number)
{
    try {
        if (index < 0 || index >= count) {
            throw ("Index out of range.");
        }
        int oldValue = data[index / 10][index % 10];
        data[index / 10][index % 10] = number;
        cout << "Old value: " << oldValue << endl;
        cout << "New value: " << number << endl;
    }
    catch (const char* e) {
        cout << e<< endl;
    }
}

void DataReader::RemoveNumber(int index)
{

    try{
        if (index < 0 || index >= count) {
            throw ("Index out of range.");
        }
        int oldValue = data[index / 10][index % 10];

        for (int i = index; i < count - 1; i++) {
            data[i / 10][i % 10] = data[(i + 1) / 10][(i + 1) % 10];
        }
        count--;

        cout << "The value: " << " " << oldValue << " " << "has been removed." << endl;
    }

    catch (const char* e) {
            cout << e << endl;
    }
}
