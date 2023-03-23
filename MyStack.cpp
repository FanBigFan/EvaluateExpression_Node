/*
//
// Created by FanBig on 2023/3/19.
//

#include "MyStack.h"


template<class T>
MyStack<T>::MyStack() {
    topIndex = 0;
}

template<class T>
bool MyStack<T>::isEmpty() {
    return topIndex == 0;
}

template<class T>
void MyStack<T>::push(T n) {
    arr[topIndex] = n;
    topIndex++;
}

template<class T>
T MyStack<T>::pop() {
    if (isEmpty()) {
        return nullptr;
    }
    topIndex--;
    return arr[topIndex];
}

template<class T>
T MyStack<T>::top() {
    if (isEmpty()) {
        return nullptr;
    }
    return arr[topIndex - 1];
}*/
