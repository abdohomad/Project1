#include <string>
using namespace std;

class DataReader{

    private:
       
        int data[10][10];
        int count;

    public:
        void readData(string fileName);
        pair<int, int> findNumber(int number);
        void addNumber(int number);
        void modifyNumber(int index, int number);
        void RemoveNumber(int index);

};
