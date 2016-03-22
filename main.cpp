#include <iostream>
#include "hash.h"

using namespace std;

int main(int argc, char *argv[])
{
     Hash hashObject;
     string name;
     hashObject.AddItem("Dave", "Pepsi");

     hashObject.AddItem("Jim", "Fanta");

     hashObject.AddItem("Ali", "Coke");

     while(name != "exit")
     {
         cout << "Enter name: ";
         cin >> name;
         if(name!="exit")
         {
             hashObject.FindDrink(name);
         }
     }


    return 0;
}
