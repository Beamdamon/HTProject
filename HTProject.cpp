#include <iostream>
#include <List>
using namespace std;

class HT
{
    int numIndexes;
    list<int>* hashTable;

public:
    HT(int V); //Constructor
    void insertItem(int x);
    void deleteItem(int key);
    void display();
    int hash(int x)
    {
        return (x % 598); // Prime Number 
    }
};

HT::HT(int b)
{
    this->numIndexes = b;
    hashTable = new list<int>[numIndexes];
}

void HT::insertItem(int key)
{
    int index = hash(key);
    hashTable[index].push_back(key);
}

int main()
{

}
