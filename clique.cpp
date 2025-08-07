#include "clique.h"

std::vector<int> Clique(Graph graph) {
    std::vector<int> output;
    while (!graph.isComplete()) {
        int minNode = graph.getMinDegreeNode();
        graph.remove_node(minNode);
    }
    int bestDegree = graph.node_count()-1;
    int size = graph.max_node();
    for (int i=0; i<size; i++) {
        if (graph.degree(i) == bestDegree) {
            output.push_back(i);
        }
    }
    return output;
}