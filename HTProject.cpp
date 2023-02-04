#include <iostream>
#include <List>
using namespace std;

class HT
{
    int numIndexes;
    list<int>* hashT;

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

int main()
{

}
