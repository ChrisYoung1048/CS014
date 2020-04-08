#ifndef NAMELIST_H
#define NAMELIST_H

#include <iostream>
using namespace std;

struct StrNode {
    string data;
    StrNode *prev;
    StrNode *next;
    StrNode(string data) : data(data), prev(0), next(0) {}
};

class NameList {
    private:
        StrNode* dummyHead;
        StrNode* dummyTail;
    public:
        NameList();
        ~NameList();
        void push_back(string name);
        //void remove(string name);
        void CommitJosephus(int n, int start, int k);
        friend ostream & operator<<(ostream &out, const NameList &rhs);
        void printAll() const;
};

#endif