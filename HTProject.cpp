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
    void retrieveItem(int key);
    void display();
    int hash(int x)
    {
        return (x % 101); // Prime Number Modulo
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

void HT::retrieveItem(int key)
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
        cout << key << " Is in the table at index: " << index;

    if (i == hashTable[index].end())
    {
        cout << key << " Is not in the table. " << index;
    }
}

void HT::display()
{
    // Loops through to the end of the list and displays the index and key
    for (int i = 0; i < numIndexes; i++)
    {
        cout << i;
        for (auto x : hashTable[i])
            cout << " --> " << x;
        cout << endl;
    }
}


int main()
{
    //Main Program

    int key = 0;

    //Creates a HT with a value of 100
    HT h(100);

    //Adds 1-100 to the hash table
    for (int i = 0; i < 100; i++)
    {
        h.insertItem(rand());
    }

    h.display();

    while (key != -1)
    {
        cout << endl << "Menu" << endl;
        cout << "1 = Display the Hash Table" << endl;
        cout << "2 = Insert a value" << endl;
        cout << "3 = Delete a value" << endl;
        cout << "4 = Retrieve a value" << endl;
        cout << "-1 = Exit" << endl;
        cin >> key;

        switch (key)
        {
        case 1:
        {
            cout << endl;
            h.display();
            break;
        }
        case 2:
        {
            cout << endl << "Input the number that you want to add.\n";
            cin >> key;
            h.insertItem(key);
            cout << endl << key << " Was added.\n";
            break;
        }
        case 3:
        {
            cout << endl << "Input the number that you want to delete.\n";
            cin >> key;
            h.deleteItem(key);
            cout << endl << key << " was deleted.";
            break;
        }
        case 4:
        {
            cout << endl << "Input the number that you want to retrieve.\n";
            cin >> key;
            h.retrieveItem(key);
            break;
        }
        }
    }

    return 0;
}
