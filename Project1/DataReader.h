#include <string>
#include <string>

class DataReader{

    private:
       
        int data[10][10];
        int count;

    public:
        void readData(std::string fileName);
        std::pair<int, int> findNumber(int number);
        void addNumber(int number);
        void modifyNumber(int index, int number);
        void RemoveNumber(int index);

};
