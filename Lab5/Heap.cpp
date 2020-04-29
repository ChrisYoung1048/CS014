#include "Heap.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Heap::Heap() {
    numItems = 0;
}

void Heap::enqueue(PrintJob* printJob) {
    if (numItems >= MAX_HEAP_SIZE) {
        return; // throw out_of_range("Called enqueue on a full heap");
    }
    
    arr[numItems] = printJob;
    percolateUp(numItems);
    numItems++;
} 

void Heap::dequeue() {
    if (numItems < 0)
        return; // throw out_of_range("Called dequeue on an empty heap");
    arr[0] = arr[numItems-1]; 
    numItems--;
    trickleDown(0);
}

PrintJob* Heap::highest() {
    if (numItems < 0)
        return NULL;     
    return arr[0];
}

void Heap::print() {
    PrintJob* job = arr[0];
    cout << "Priority: " << job->getPriority();
    cout << ", Job Number: " << job->getJobNumber();
    cout << ", Number of Pages: " << job->getPages() << endl;
}

void Heap::percolateUp(int nodeIndex) {
    while (nodeIndex > 0) {
        int parentIndex =  (nodeIndex - 1) / 2;
        if (arr[nodeIndex]->getPriority() <= arr[parentIndex]->getPriority()) { // if priority is less than that of parent
            return;
        } else { // if priority is greater than that of parent
            PrintJob* temp = arr[nodeIndex];
            arr[nodeIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            nodeIndex = parentIndex;
        }
    }
}

void Heap::trickleDown(int nodeIndex) {
    int childIndex = 2 * nodeIndex + 1;
    int nodePriority = arr[nodeIndex]->getPriority();

    while (childIndex < numItems) {
        int topPriority = nodePriority;
        int topIndex = -1;
        for (int i = 0; i < 2 && i + childIndex < numItems; i++) { // traverse both children
            if (arr[i+childIndex]->getPriority() > topPriority) { // if child priority is greater than current top priority
                topPriority = arr[i+childIndex]->getPriority(); // set child priority to top priority
                topIndex = i + childIndex; // update the index of top priority
            }
        }
        if (topPriority == nodePriority) { // if top priority is greater than both children
            return;
        }
        else {
            PrintJob* temp = arr[nodeIndex];
            arr[nodeIndex] = arr[topIndex];
            arr[topIndex] = temp;
            nodeIndex = topIndex;
            childIndex = 2 * nodeIndex + 1;
        }
    }
}


