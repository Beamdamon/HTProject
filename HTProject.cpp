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
    // Creates the hash table using a list
    this->numIndexes = b;
    hashTable = new list<int>[numIndexes];
}

void HT::insertItem(int key)
{
    // Inserts a new key into the hash table
    int index = hash(key);
    hashTable[index].push_back(key);
}

void HT::deleteItem(int key)
{
    // Gets the index of the key
    int index = hash(key);

    // Finds the key in the list going from beginning to end of the list
    list <int> ::iterator i;
    for (i = hashTable[index].begin();
        i != hashTable[index].end(); i++) 
    {
        if (*i == key)
            break;
    }

    // Deletes the index
    if (i != hashTable[index].end())
        hashTable[index].erase(i);
}



int main()
{

}
