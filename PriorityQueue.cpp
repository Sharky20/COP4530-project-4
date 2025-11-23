// COP4350 Final Project Priority Queue Implementation
// Implemented Using a Min Heap

#include "PriorityQueue.hpp"
#include <string>

// template initializations for using in Graph class
template class PriorityQueue<int>;
template class PriorityQueue<std::pair<unsigned long, std::string>>;

// returns if the queue is empty or not
template <typename T>
bool PriorityQueue<T>::empty() {
    return hp.empty();
}

// inserts element of type T into the queue
template <typename T>
void PriorityQueue<T>::insert(T e) {
    hp.insert(e);
}

// returns the front of the queue
template <typename T>
T PriorityQueue<T>::front() {
    return hp.min();
}

// pops the front of the queue
template <typename T>
void PriorityQueue<T>::pop() {
    hp.removeMin();
}

// returns the current size of the queue
template <typename T>
int PriorityQueue<T>::size() {
    return hp.size();
}