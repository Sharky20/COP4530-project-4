#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <string>
#include <vector>

class Graph {
private:
public:
    void addVertex(std::string label);
    void addEdge(std::string label1, std::string label2, unsigned long weight);
    void removeEdge(std::string label1, std::string label2);
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
};


#endif