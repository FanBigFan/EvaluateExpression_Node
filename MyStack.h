//
// Created by FanBig on 2023/3/19.
//

#ifndef EVALUATEEXPRESSION_NODE_MYSTACK_H
#define EVALUATEEXPRESSION_NODE_MYSTACK_H


/*
    MyStack_h
*/

#ifndef MyStack_h
#define MyStack_h

#include <cstddef>

template<class T>
class MyStack {
public:
    T arr[100];
    int topIndex;

    MyStack() {
        topIndex = 0;
    }

    bool isEmpty() {
        return topIndex == 0;
    }

    void push(T n) {
        arr[topIndex] = n;
        topIndex++;
    }

    T pop() {
        if (isEmpty()) {
            return NULL;
        }
        topIndex--;
        return arr[topIndex];
    }

    T top() {
        if (isEmpty()) {
            return NULL;
        }
        return arr[topIndex - 1];
    }
};

#endif

//template<class T>
//class MyStack {
//public:
//    T arr[100];
//    int topIndex;
//
//    MyStack();
//
//    bool isEmpty();
//
//    void push(T n);
//
//    T pop();
//
//    T top();
//};


#endif //EVALUATEEXPRESSION_NODE_MYSTACK_H
