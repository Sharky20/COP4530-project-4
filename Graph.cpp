#include "Graph.hpp"

void Graph::addVertex(std::string label) {
    adjList[label] = std::list<Edge>();
}

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
    adjList[label1].push_back({label2, weight});
    adjList[label2].push_back({label1, weight});
}

void Graph::removeEdge(std::string label1, std::string label2) {
    adjList[label1].remove_if([&](const Edge& e) {
        return e.to == label2;
    });
    adjList[label2].remove_if([&](const Edge& e) {
        return e.to == label1;
    });
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {

}