#include <iostream>
#include "NameList.h"
using namespace std;

NameList::NameList() { // Circularly Linked List
    dummyHead = new StrNode("DUMMYNODE");
    dummyTail = new StrNode("DUMMYNODE");

    dummyHead->next = dummyTail;
    dummyHead->prev = dummyTail;
    dummyTail->next = dummyHead;
    dummyTail->prev = dummyHead;
}

NameList::~NameList() { 
    StrNode* curNode = dummyHead;
    while (curNode != dummyTail) {
        StrNode* temp = curNode;
        curNode = curNode->next;
        delete temp;
    }
    delete curNode;
}

void NameList::push_back(string name) {
    StrNode* newNode = new StrNode(name);
    StrNode* prevNode = dummyTail->prev;
    prevNode->next = newNode;
    newNode->next = dummyTail;
    dummyTail->prev = newNode;
    newNode->prev = prevNode;
}

void NameList::CommitJosephus(int n, int p, int k) {
    StrNode* curNode = dummyHead->next;
    for (int i = 1; i < p; ++i) {
        curNode = curNode->next;
    }
    //cout << "start position: " << curNode->data;

    while (n > 1) {
        for (int i = 1; i < k; ++i) {
            if (curNode == dummyTail->prev) {
                curNode = dummyHead->next;
            } else {
                curNode = curNode->next;  
            }   
        }

        StrNode* prevNode = curNode->prev;
        StrNode* sucNode = curNode->next;
        prevNode->next = sucNode;
        sucNode->prev = prevNode;

        delete curNode;
        curNode = sucNode;
        if (curNode == dummyTail || curNode == dummyHead) {
            curNode = dummyHead->next;
        }
        n--;
        //printAll();
    }
}

ostream & operator<<(ostream &out, const NameList &rhs) {
    StrNode* curNode = rhs.dummyHead->next;
    while (curNode != rhs.dummyTail) {
        if (curNode == rhs.dummyTail->prev) {
            out << curNode->data;
        }
        else {
            out << curNode->data << ", ";
        }
        curNode = curNode->next;
    }
    return out;
}

void NameList::printAll() const {
    StrNode* curNode = dummyHead;
    do {
        cout << curNode->data << " ";
        curNode = curNode->next;
    } while (curNode != dummyHead);
}
