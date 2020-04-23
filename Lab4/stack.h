#ifndef STACK_H
#define STACK_H

const int MAX_SIZE = 20;

using namespace std;

template<typename T> 
class stack {
    private:
        T data[MAX_SIZE];
        int size;
    public:
        stack() {
            size = 0;
        }
        
        void push(T val) {
            if (size == MAX_SIZE) {
                throw overflow_error("Called push on full stack.");
            }
            for (int i = size; i > 0; --i) {
                data[i] = data[i-1];
            }
            data[0] = val;
            size++; 
        }

        void pop() {
            if (size == 0) {
                throw out_of_range("Called pop on empty stack.");
            }
            for (int i = 0; i < size; ++i) {
                data[i] = data[i+1];
            }
            size--;
        }

        T top(){
            if (size == 0) {
                throw underflow_error("Called top on empty stack.");
            }
            return data[0];
        }

        bool empty() {
            if (size == 0)  
                return true;
            return false;
        }
};

#endif