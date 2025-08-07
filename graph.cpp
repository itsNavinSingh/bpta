#include "graph.h"

Graph::Graph(int node){
    size = node;
    graphData = std::vector<std::set<int>>(size);
}
bool Graph::valid_node(int node) {
    return (node >= 0 && node < size);
}
void Graph::add_edge(int node1, int node2) {
    if (valid_node(node1) && valid_node(node2)){
        graphData[node1].insert(node2);
        graphData[node2].insert(node1);
    }
}
void Graph::remove_edge(int node1, int node2) {
    if (valid_node(node1) && valid_node(node2)) {
        graphData[node1].erase(node2);
        graphData[node2].erase(node1);
    }
}
void Graph::remove_node(int node) {
    if (!valid_node(node)) return;
    for (int conNode : graphData[node]){
        graphData[conNode].erase(node);
    }
    graphData[node].clear();
}
int Graph::degree(int node) {
    if (!valid_node(node)) return 0;
    return graphData[node].size();
}

bool Graph::hasEdge(int node1, int node2){
    if (valid_node(node1) && valid_node(node2)) {
        return graphData[node1].find(node2) != graphData[node1].end();
    }
    return false;
}

int Graph::getMaxDegreeNode() {
    int nodeNumber = 0;
    int maxDegree = degree(0);
    for (int i = 1; i < size; i++){
        if (degree(i) > maxDegree) {
            maxDegree = degree(i);
            nodeNumber = i;
        }
    }
    return nodeNumber;
}

int Graph::getMinDegreeNode(){
    int minDegreeNode = getMaxDegreeNode();
    int minDegree = degree(minDegreeNode);
    if (minDegree <= 1) return minDegreeNode;
    for (int i=0; i<size; i++){
        int currDegree = degree(i);
        if (currDegree < minDegree && currDegree != 0) {
            minDegree = currDegree;
            minDegreeNode = i;
        }
    }
    return minDegreeNode;
}

bool Graph::isDisconnected() {
    for(int i = 0; i < size; i++){
        if(degree(i) != 0) return false;
    }
    return true;
}

int Graph::node_count() {
    int nodecount = 0;
    for (int i=0; i<size; i++){
        if (degree(i) > 0) nodecount++;
    }
    return nodecount;
}

bool Graph::isComplete() {
    int nonZeroNode = node_count();
    // if nonzero node number is 0 or 1 then it is by default complete
    if (nonZeroNode <= 1) {
        return true;
    }
    nonZeroNode--;
    for (int i=0; i<size; i++) {
        if (degree(i) != nonZeroNode && degree(i) != 0) return false;
    }
    return true;
}

int Graph::max_node() {
    return size;
}