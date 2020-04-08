#include <iostream>
#include <string>
using namespace std;
#include "IntList.h"

int main() {
    IntList list;
    cout << "instantiated IntList list" << endl;
    //list.printAll();

    cout << "list is empty: " << list.empty() << endl;

    cout << "push_front 3, push_front 2, push_front 1" << endl;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    cout << "print list: " << list << endl;

    cout << "list is empty: " << list.empty() << endl;

    cout << "push_back 6, push_back 5, push_back 4, " << endl;
    list.push_back(6);
    list.push_back(5);
    list.push_back(4);
    cout << "print list: " << list << endl;

    cout << "pop_front" << endl;
    list.pop_front();
    cout << "print list: " << list << endl;
    cout << "pop_back" << endl;
    list.pop_back();
    cout << "print list: " << list << endl;
    cout << "print reverse: ";
    list.printReverse();
    


    //list.printAll();
    
    //list.printReverse();
}