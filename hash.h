#ifndef HASH_H
#define HASH_H

#include <iostream>

using namespace std;

class Hash
{
public:
    Hash();
    int hash(string key);
    void AddItem(string name, string drink);
    int NumberOfItemsInIndex(int index);
    void printTable();
    void FindDrink(string name);

private:
    static const int tableSize=40;

    struct item{
        string name;
        string drink;
        item* next;
    };

    item* HashTable[tableSize];
};

#endif // HASH_H
