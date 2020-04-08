#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);

    dummyHead->next = dummyTail;
    dummyHead->prev = nullptr;
    dummyTail->next = nullptr;
    dummyTail->prev = dummyHead;
}

IntList::~IntList() {
    IntNode* curNode = dummyHead;
    while (curNode != nullptr) {
        IntNode* temp = curNode;
        curNode = curNode->next;
        delete temp;
    }
} 

void IntList::push_front(int value) {
    IntNode* newNode = new IntNode(value);
    IntNode* firstNode = dummyHead->next;
    newNode->next = dummyHead->next;
    newNode->prev = dummyHead;
    dummyHead->next = newNode;
    if (firstNode != nullptr) {
        firstNode->prev = newNode;
    }
}

void IntList::pop_front() {
    if (dummyHead->next == dummyTail)
        return;
    else {
        IntNode* temp = dummyHead->next;
        dummyHead->next = temp->next;
        temp->next->prev = dummyHead;
        delete temp;
    }
}

void IntList::push_back(int value) {
    IntNode* newNode = new IntNode(value);
    IntNode* prevNode = dummyTail->prev;
    prevNode->next = newNode;
    newNode->next = dummyTail;
    dummyTail->prev = newNode;
    newNode->prev = prevNode;
}

void IntList::pop_back() {
   if (dummyHead->next == dummyTail)
        return;
    else {
        IntNode* temp = dummyTail->prev;
        dummyTail->prev = temp->prev;
        temp->prev->next = dummyTail;
        delete temp;
    } 
}

bool IntList::empty() const {
    if (dummyHead->next == dummyTail)
        return true;
    return false;
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode* curNode = rhs.dummyHead->next;
    while (curNode != rhs.dummyTail) {
        if (curNode == rhs.dummyTail->prev) {
            out << curNode->data;
        }
        else {
            out << curNode->data << " ";
        }
        curNode = curNode->next;
    }
    return out;
}

void IntList::printReverse() const {
    IntNode* curNode = dummyTail->prev;
    while (curNode != dummyHead) {
        if (curNode->prev == dummyHead) {
            cout << curNode->data;
        }
        else {
            cout << curNode->data << " ";
        }
        curNode = curNode->prev;
    }
}

void IntList::printAll() const {
    IntNode* curNode = dummyHead;
    while(curNode != nullptr) {
        cout << curNode->data << " ";
        curNode = curNode->next;
    }
}
