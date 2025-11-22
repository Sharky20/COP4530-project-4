#include "Graph.hpp"
#include "PriorityQueue.hpp"
#include <climits>
#include <algorithm>

void Graph::addVertex(std::string label) {
    adjList[label] = std::list<Edge>();
}

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
    adjList[label1].push_back({label2, weight});
    adjList[label2].push_back({label1, weight});
}

void Graph::removeEdge(std::string label1, std::string label2) {
    if (adjList.count(label1)) {
        adjList[label1].remove_if([&](const Edge& e) {
            return e.to == label2;
        });
    }
    if (adjList.count(label2)) {
        adjList[label2].remove_if([&](const Edge& e) {
            return e.to == label1;
        });
    }
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
    // returns inf if start or end vertex do not exist
    if (!adjList.count(startLabel) || !adjList.count(endLabel)) {
        return ULONG_MAX;
    }
    
    // returns 0 if start and end vertex are the same
    if (startLabel == endLabel) {
        path = {startLabel};
        return 0;
    }

    // standard Dijkstra's algorithm
    PriorityQueue<std::pair<unsigned long, std::string>> pq;
    std::map<std::string, unsigned long> dist;
    std::map<std::string, std::string> prev;

    for (auto &p : adjList) {
        dist[p.first] = ULONG_MAX;
    }

    dist[startLabel] = 0;
    pq.insert({0, startLabel});

    while (!pq.empty()) {
        auto top = pq.front();
        pq.pop();
        unsigned long d = top.first;
        std::string u = top.second;
        
        if (d > dist[u]) {
            continue;
        }

        for (auto &edge : adjList[u]) {
            unsigned long newDist = d + edge.weight;
            if (newDist < dist[edge.to]) {
                dist[edge.to] = newDist;
                prev[edge.to] = u;
                pq.insert({newDist, edge.to});
            }
        }
    }

    if (dist[endLabel] == ULONG_MAX) {
        return ULONG_MAX;
    }

    path.clear();
    for (std::string at = endLabel; at != startLabel; at = prev[at]) {
        path.push_back(at);
    }
    path.push_back(startLabel);
    std::reverse(path.begin(), path.end());
    return dist[endLabel];
}