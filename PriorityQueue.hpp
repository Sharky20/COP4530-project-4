#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include "MinHeap.hpp"

template <typename T>
class PriorityQueue {
private:
    MinHeap<T> hp;
public:
    PriorityQueue(){}
    ~PriorityQueue(){}

    bool empty();
    void insert(T e);
    T front();
    void pop();
};

#endif