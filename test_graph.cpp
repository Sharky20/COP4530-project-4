#include <iostream>
#include <vector>
#include <string>
#include "Graph.hpp"
#include <climits>

using namespace std;

bool samePath(const vector<string>& a, const vector<string>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void printResult(const string& testName, bool passed) {
    cout << testName << ": " << (passed ? "Correct" : "Wrong") << endl;
}

int main() {
    Graph g;

    // Create vertices A–F
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addVertex("F");

    // Add weighted undirected edges
    g.addEdge("A", "B", 7);
    g.addEdge("A", "C", 9);
    g.addEdge("A", "F", 14);
    g.addEdge("B", "C", 10);
    g.addEdge("B", "D", 15);
    g.addEdge("C", "D", 11);
    g.addEdge("C", "F", 2);
    g.addEdge("D", "E", 6);
    g.addEdge("E", "F", 9);

    vector<string> path;
    unsigned long dist;

    // ****** Test 1: A -> E ******
    vector<string> expectedPathToE = {"A", "C", "F", "E"};
    unsigned long expectedDistToE = 20;

    dist = g.shortestPath("A", "E", path);
    printResult("Distance A->E", dist == expectedDistToE);
    printResult("Path A->E", samePath(path, expectedPathToE));

    // ****** Test 2: A -> D ******
    vector<string> expectedPathToD = {"A", "C", "D"};
    unsigned long expectedDistToD = 20; // 9 + 11

    dist = g.shortestPath("A", "D", path);
    printResult("Distance A->D", dist == expectedDistToD);
    printResult("Path A->D", samePath(path, expectedPathToD));

    // ****** Test 3: Start = End ******
    vector<string> expectedPathSame = {"C"};
    dist = g.shortestPath("C", "C", path);
    printResult("Distance C->C", dist == 0);
    printResult("Path C->C", samePath(path, expectedPathSame));

    // ****** Test 4: Vertex does not exist ******
    dist = g.shortestPath("A", "Z", path);
    printResult("Non-existent vertex A->Z", dist == ULONG_MAX);

    cout << "---- Tests Completed ----" << endl;
    return 0;
}
