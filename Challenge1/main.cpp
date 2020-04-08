#include <iostream>
#include <fstream>
#include <string>
#include "NameList.h"

using namespace std;

int main() {
    cout << "Enter name of file:" << endl;
    string fileName;
    cin >> fileName;

    ifstream inFS;
    inFS.open(fileName);
    if (!inFS.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }

    NameList list;

    string name = "";
    while (!inFS.eof()) { // populate list
        getline(inFS, name);
        if (!inFS.fail())
            list.push_back(name);
    }
    cout << "print list: " << list << endl;
    cout << "print all nodes: ";
    list.printAll();
    cout << endl;
    
    cout << "Number of people:" << endl;
    int n;
    cin >> n;
    cout << "Position to start:" << endl;
    int p;
    cin >> p;
    cout << "How many people to skip:" << endl;
    int k;
    cin >> k;

    cout << "purging..." << endl;
    list.CommitJosephus(n, p, k);

    cout << "Survivor: " << list << endl;

    inFS.close();
    return 0;
}