#include "PriorityQueue.hpp"
#include <string>

template class PriorityQueue<int>;
template class PriorityQueue<std::pair<unsigned long, std::string>>;

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

template <typename T>
int PriorityQueue<T>::size() {
    return hp.size();
}