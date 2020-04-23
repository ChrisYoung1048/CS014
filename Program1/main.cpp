#include <iostream>
#include <stdexcept>
#include "WordLadder.h"

using namespace std;

int main() {
    try { // Populate dict list
        cout << "Enter filename:" << endl;
        string fileName;
        cin >> fileName;
        WordLadder ladder(fileName);

        ladder.outputLadder("abaca","abaca","output.txt");

    } catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
		cout << "Cannot create word ladder." << endl;
    }
    



    return 0;
}