#include "MinHeap.hpp"

template <typename T>
bool MinHeap<T>::hasLeftChild(int index) {
    return getLeftChildIndex(index) < v.size();
}

template <typename T>
bool MinHeap<T>::hasRightChild(int index) {
    return getRightChildIndex(index) < v.size();
}

template <typename T>
bool MinHeap<T>::hasParent(int index) {
    return index > 0;
}

template <typename T>
void MinHeap<T>::heapifyDown(int index) {
    int min = index;
    int left = getLeftChildIndex(index);
    int right = getRightChildIndex(index);

    if (left < v.size() && v[left] < v[min]) min = left;
    if (right < v.size() && v[right] < v[min]) min = left;

    if (min != index) {
        std::swap(v[min], v[index]);
        heapifyDown(min);
    }
}

template <typename T>
void MinHeap<T>::heapifyUp() {
    int index = v.size() - 1;
    while (hasParent(index) && v[index] < v[getParentIndex(index)]) {
        std::swap(v[index], v[getParentIndex(index)]);
        index = getParentIndex(index);
    }
}

template <typename T>
int MinHeap<T>::getLeftChildIndex(int index) {
    return 2*index + 1;
}

template <typename T>
int MinHeap<T>::getRightChildIndex(int index) {
    return 2*index + 2;
}

template <typename T>
int MinHeap<T>::getParentIndex(int index) {
    return (index - 1) / 2;
}

template <typename T>
T MinHeap<T>::MinHeap::min() const {
    return v.at(0);
}

template <typename T>
void MinHeap<T>::removeMin() {
    if (v.size() < 1) return;
    std::swap(v[0], v[v.size() - 1]);
    v.pop_back();
    heapifyDown(0);
}

template <typename T>
void MinHeap<T>::insert(T d) {
    v.push_back(d);
    heapifyUp();
}

template <typename T>
bool MinHeap<T>::empty() {
    return v.empty();
}