#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <queue>
#include <stack>
#include "WordLadder.h"

using namespace std;

WordLadder::WordLadder(const string &fileName) {
    ifstream inFS;
    inFS.open(fileName);
    if (!inFS.is_open()) {
        throw runtime_error("Cannot to open file.");
    }

    string data;
    while (!inFS.eof()) {
        getline(inFS, data);
        if (data.size() == 5) {  // if data is 5 characters, pushback
            dict.push_back(data);
        }
        else if (data.size() != 0) { // if data isn't a newline
            //cout << "data: ";
            throw runtime_error("Invalid string length(s).");
        }    
    }   
    inFS.close();
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    ofstream outFS;
    outFS.open(outputFile);
    if (!outFS.is_open()) {
        throw runtime_error("Cannot to open file.");
    } if (!checkValidity(start) || !checkValidity(end)) {// if either start or end are invalid
        throw runtime_error("Incorrect start/end word input.");
    } if (start == end) {
        outFS << end;
        outFS.close();
        return;
    }
    
    stack<string> startLadder;
    startLadder.push(end);
    //dict.remove(start);
    queue<stack<string>> ladderQueue;
    ladderQueue.push(startLadder);

    while (!ladderQueue.empty()) {
        string topWord = ladderQueue.front().top();
        list<string>::iterator i;
        for (i = dict.begin(); i != dict.end(); ++i) {
            if (findLetterDifference(*i, topWord) == 1) {
                //cout << "test";
                stack<string> newLadder = ladderQueue.front();
                newLadder.push(*i);
                if (*i == start) {
                    while (!newLadder.empty()) {
                        outFS << newLadder.top() << " ";
                        newLadder.pop();
                    }
                    break;
                } else {
                    ladderQueue.push(newLadder);
                    //dict.remove(*i);
                    i = dict.erase(i);
                    --i;
                }
            }
        }
        if (*i == start) {
            break;
        }
        ladderQueue.pop();
    }

    
    if (ladderQueue.empty()) {
        outFS << "No Word Ladder Found.";
    } 
    // else {
    //     stack<string> wordLadder = ladderQueue.front();
    //     while (!wordLadder.empty()) {
    //         outFS << wordLadder.top() << " ";
    //         wordLadder.pop();
    //     }
    //     //outFS << wordLadder.top();
    // }
    outFS.close();
}

bool WordLadder::checkValidity(const string &word) {
    list<string>::iterator i;
    for (i = dict.begin(); i != dict.end(); ++i) {
        if (word == *i)
            return true;
    }
    return false;
}

int WordLadder::findLetterDifference(const string &word1, const string &word2) {
    if (word1 == word2)
        return 0;
    else {
        int difference = 0;
        for (unsigned i = 0; i < 5 ; ++i) {
            //cout << "word1: " << word1.at(i) << "word2: " << word2.at(i) << endl;
            if (word1.at(i) != word2.at(i))
                difference++;
        }
        return difference;
    }
}
