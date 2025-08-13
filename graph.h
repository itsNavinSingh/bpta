#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <set>
class Graph {
    private:
    int size;
    std::vector<std::set<int>> graphData;
    bool valid_node(int);
    public:
    Graph(int);
    int max_node();
    int node_count();
    void add_edge(int, int);
    void remove_edge(int, int);
    void remove_node(int);
    int degree(int);
    int getMaxDegreeNode();
    int getMinDegreeNode();
    bool hasEdge(int, int);
    bool isDisconnected();
    bool isComplete();
    std::vector<int> adjecent(int);
    int adjDegreeSum(int);
};
#endif