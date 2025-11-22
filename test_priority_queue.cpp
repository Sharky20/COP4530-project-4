#include <iostream>
#include <vector>
#include <cassert>
#include "PriorityQueue.hpp"

using namespace std;

void test_basic_insert_pop() {
    PriorityQueue<int> pq;

    assert(pq.size() == 0);

    pq.insert(10);
    pq.insert(5);
    pq.insert(20);

    assert(pq.size() == 3);
    assert(!pq.empty());
    assert(pq.front() == 5);

    pq.pop();
    assert(pq.size() == 2);
    assert(pq.front() == 10);

    pq.pop();
    assert(pq.size() == 1);
    assert(pq.front() == 20);

    pq.pop();
    assert(pq.empty());
    assert(pq.size() == 0);

    cout << "[PASS] Basic insert/pop + size test" << endl;
}

void test_random_data() {
    PriorityQueue<int> pq;
    vector<int> data = {3, 17, 6, 25, 2, 30, 1, 8};

    for (int x : data) pq.insert(x);
    assert(pq.size() == data.size());

    int prev = pq.front();
    pq.pop();

    while (!pq.empty()) {
        int now = pq.front();
        pq.pop();
        assert(prev <= now);
        prev = now;
    }

    cout << "[PASS] Random ordering test" << endl;
}

void test_duplicates() {
    PriorityQueue<int> pq;

    pq.insert(10);
    pq.insert(10);
    pq.insert(10);
    assert(pq.size() == 3);

    assert(pq.front() == 10);
    pq.pop();
    assert(pq.front() == 10);
    pq.pop();
    assert(pq.front() == 10);
    pq.pop();

    assert(pq.size() == 0);
    assert(pq.empty());

    cout << "[PASS] Duplicate values test" << endl;
}

void test_single_element() {
    PriorityQueue<int> pq;

    pq.insert(42);
    assert(pq.size() == 1);
    assert(!pq.empty());
    assert(pq.front() == 42);
    pq.pop();

    assert(pq.size() == 0);
    assert(pq.empty());

    cout << "[PASS] Single element test" << endl;
}

int main() {
    test_basic_insert_pop();
    test_random_data();
    test_duplicates();
    test_single_element();

    cout << "\n All tests passed successfully!" << endl;
    return 0;
}
