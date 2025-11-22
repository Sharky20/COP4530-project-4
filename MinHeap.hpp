#ifndef MINHEAP_HPP
#define MINHEAP_HPP
#include <vector>

template <typename T>
class MinHeap {
private:
    std::vector<T> v;
    bool hasLeftChild(int index);
    bool hasRightChild(int index);
    bool hasParent(int index);
    void heapifyDown(int index);
    void heapifyUp();
    int getLeftChildIndex(int index);
    int getRightChildIndex(int index);
    int getParentIndex(int index);
public:
    T min() const;
    int size();
    void removeMin();
    void insert(T d);
    bool empty();
};

#endif