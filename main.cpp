#include <iostream>
#include <vector>
#include <string>
#include "Graph.hpp"
#include <climits>

using namespace std;

void printTest(string lbl1, string lbl2, Graph g) {
    vector<string> path;

    cout << lbl1 << " to " << lbl2 << endl;
    unsigned long dist = g.shortestPath(lbl1, lbl2, path);
    int count = 0;
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << "->";
        }
        count++;
    }
    if (count != 0) {
        cout << endl;
    }
    if (dist == ULONG_MAX) {
        cout << "No path" << endl;
        cout << "Shortest path distance: ∞" << endl << endl;
    }
    else {
        cout << "Shortest path distance: " << dist << endl << endl;
    }
    
}

void test1() {
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

    printTest("A", "B", g);
    printTest("A", "C", g);
    printTest("A", "D", g);
    printTest("A", "E", g);
    printTest("A", "F", g);
}

void test2() {
    Graph g;

    // Create vertices A–F
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addVertex("F");
    g.addVertex("G");
    g.addVertex("H");
    g.addVertex("I");
    g.addVertex("J");
    g.addVertex("K");

    // Add weighted undirected edges
    g.addEdge("A", "B", 7);
    g.addEdge("A", "C", 9);
    g.addEdge("A", "F", 14);
    g.addEdge("B", "C", 10);
    g.addEdge("J", "D", 15);
    g.addEdge("C", "D", 11);
    g.addEdge("C", "F", 2);
    g.addEdge("D", "E", 6);
    g.addEdge("F", "J", 16);
    g.addEdge("D", "G", 1);
    g.addEdge("D", "H", 5);
    g.addEdge("B", "I", 19);
    g.addEdge("E", "I", 8);
    g.addEdge("C", "H", 4);

    // Print paths
    printTest("B", "A", g);
    printTest("B", "C", g);
    printTest("B", "D", g);
    printTest("B", "E", g);
    printTest("B", "F", g);
    printTest("B", "K", g);
}

void test3() {
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
    g.addEdge("B", "C", 10);
    g.addEdge("B", "D", 15);
    g.addEdge("A", "C", 9);
    g.addEdge("C", "D", 11);
    g.addEdge("A", "F", 14);
    g.addEdge("C", "F", 2);
    g.addEdge("E", "F", 9);
    g.addEdge("D", "E", 6);

    // Print paths
    printTest("A", "B", g);
    printTest("A", "C", g);
    printTest("A", "D", g);
    printTest("A", "E", g);
    printTest("A", "F", g);

}

int main() {
    string space = "--------------------------------------------";
    cout << "Test 1" << endl << space << endl;
    test1();

    cout << endl << "Test 2" << endl << space << endl;
    test2();

    cout << endl << "Test 3 (Same as example in slides)" << endl << space << endl;
    test3();

    return 0;
}
