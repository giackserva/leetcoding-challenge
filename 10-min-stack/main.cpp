/*
                            - Min Stack -

Design a stack that supports push, pop, top, and retrieving the minimum element
in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include<bits/stdc++.h>

using namespace std;

class MinStack {
    stack<int> data_;
    stack<int> min_;
public:
    MinStack()
    : data_{}
    , min_ {}
    {

    }
    void push(int x) {
        data_.push(x);
        if(min_.empty() || x <= min_.top()) {
            min_.push(x);
        }
    }

    void pop() {
        if(data_.top() == min_.top()) {
            min_.pop();
        }
        data_.pop();
    }

    int top() {
        return data_.top();
    }

    int getMin() {
        return min_.top();
    }
};

int main (){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(minStack.getMin() == -3);
    minStack.pop();
    assert(minStack.top() == 0);
    assert(minStack.getMin() == -2);
}