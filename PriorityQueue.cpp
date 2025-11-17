#include "PriorityQueue.hpp"

template <typename T>
bool PriorityQueue<T>::empty() {
    return hp.empty();
}

template <typename T>
void PriorityQueue<T>::insert(T e) {
    hp.insert(e);
}

template <typename T>
T PriorityQueue<T>::front() {
    return hp.min();
}

template <typename T>
void PriorityQueue<T>::pop() {
    hp.removeMin();
}