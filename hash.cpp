#include "hash.h"
#include <string>

using namespace std;
Hash::Hash()
{
  for(int i =0; i<tableSize; i++){

      HashTable[i] = new item;
      HashTable[i]->name= "empty";
      HashTable[i]->drink = "empty";
      HashTable[i]->next = NULL;
  }
}

int Hash::hash(string key)
{
    int hashValue = 0;
    int index;

    index = key.length();

    for(int i =0; i<index; i++)
    {
        hashValue = hashValue +(int)key[i];

    }

    index = hashValue % tableSize;


//    cout<< "key[0]= " << (int)key[0] <<endl;
//    cout<< "key[1]= " << (int)key[1] <<endl;
//    cout<< "key[2]= " << (int)key[2] <<endl;
//    cout<< "key[3]= " << (int)key[3] <<endl;



    return index;


}

void Hash::AddItem(string name, string drink){
    int index= hash(name);

    if(HashTable[index]->name=="empty")
    {
        HashTable[index]->name= name;
        HashTable[index]->drink= drink;
    }
    else
    {
        item* Ptr = HashTable[index]; // For traversing through the list
        item* n = new item;
        n->name = name;
        n->drink =drink;
        n->next= NULL;
        while(Ptr->next != NULL){
            Ptr = Ptr->next;
        }
        Ptr->next = n;

    }
}

int Hash::NumberOfItemsInIndex(int index){

    int count=0;

    if(HashTable[index]->name=="empty"){
        return count;
    }
    else {
        count=1;
        item* Ptr = HashTable[index];

        while(Ptr->next != NULL){
            Ptr = Ptr->next;
            count++;
        }
    }
    return count;
}

void Hash::printTable(){
    int number;
    int count=0;

    for (int i=0; i<tableSize; i++){
        number = NumberOfItemsInIndex(i);
        cout << "---------------\n";
        cout << "Index: " << i <<endl;
        cout << HashTable[i]->name <<endl;
        cout << HashTable[i]->drink<<endl;
        cout << "# of items = " << number <<endl;
        cout << "---------------\n";

        if(number!=0)
        {
            item* Ptr = HashTable[i];
            while(Ptr->next!=NULL)
            {   count++;
                Ptr=Ptr->next;
                cout << "   **********\n";
                cout << "   List Index: " << count <<endl;
                cout <<"   " <<Ptr->name <<endl;
                cout <<"   " <<Ptr->drink<<endl;
            }
            cout << "   **********\n";
        }
    }
}

void Hash::FindDrink(string name){
    int index = hash(name);
    bool foundName=false;
    string drink;

    item* Ptr = HashTable[index];
    while(Ptr !=NULL)
    {
        if (Ptr->name==name){
            foundName=true;
            drink=Ptr->drink;
        }
        Ptr=Ptr->next;
    }

    if(foundName == true)
    {
        cout << "Favourite Drink= "<< drink <<endl;
    }
    else
    {
        cout << "Drink not listed." <<endl;
    }
}
