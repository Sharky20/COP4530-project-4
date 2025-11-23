// COP4530 Min Heap Implementation

#include "MinHeap.hpp"
#include <string>

template class MinHeap<int>;
template class MinHeap<std::pair<unsigned long, std::string>>;

// returns if element at given index has a left child
template <typename T>
bool MinHeap<T>::hasLeftChild(int index) {
    return getLeftChildIndex(index) < v.size();
}

// returns if element at given index has a right child
template <typename T>
bool MinHeap<T>::hasRightChild(int index) {
    return getRightChildIndex(index) < v.size();
}

// returns if element at given index has a parent element
template <typename T>
bool MinHeap<T>::hasParent(int index) {
    return index > 0;
}

// recursive heapify down function for maintaining heap property
template <typename T>
void MinHeap<T>::heapifyDown(int index) {
    int min = index;
    int left = getLeftChildIndex(index);
    int right = getRightChildIndex(index);

    if (left < v.size() && v[left] < v[min]) min = left;
    if (right < v.size() && v[right] < v[min]) min = right;

    if (min != index) {
        std::swap(v[min], v[index]);
        heapifyDown(min);
    }
}

// recursive heapify up function for maintaining heap property
template <typename T>
void MinHeap<T>::heapifyUp() {
    int index = v.size() - 1;
    while (hasParent(index) && v[index] < v[getParentIndex(index)]) {
        std::swap(v[index], v[getParentIndex(index)]);
        index = getParentIndex(index);
    }
}

// returns left child index of given index
template <typename T>
int MinHeap<T>::getLeftChildIndex(int index) {
    return 2*index + 1;
}

// returns right child index of given index
template <typename T>
int MinHeap<T>::getRightChildIndex(int index) {
    return 2*index + 2;
}

// gets parent index of given index
template <typename T>
int MinHeap<T>::getParentIndex(int index) {
    return (index - 1) / 2;
}

// returns current min 
template <typename T>
T MinHeap<T>::MinHeap::min() const {
    return v.at(0);
}

// removes the current min and reheapifies
template <typename T>
void MinHeap<T>::removeMin() {
    if (v.size() < 1) return;
    std::swap(v[0], v[v.size() - 1]);
    v.pop_back();
    heapifyDown(0);
}

// inserts element of type T into the heap
template <typename T>
void MinHeap<T>::insert(T d) {
    v.push_back(d);
    heapifyUp();
}

// returns if the heap is empty
template <typename T>
bool MinHeap<T>::empty() {
    return v.empty();
}

// returns the current size of the heap
template <typename T>
int MinHeap<T>::size() {
    return v.size();
}