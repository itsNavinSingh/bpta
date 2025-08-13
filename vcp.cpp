#include "vcp.h"

std::vector<int>VertexCoverProblem(Graph graph){
    std::vector<int>output;
    int node = 0;
    while (!graph.isDisconnected())
    {
        // get maxdegree node
        node = selectedNode(&graph);
        // push node to output
        output.push_back(node);
        // remove the node
        graph.remove_node(node);
    }
    
    return output;
}

int selectedNode(Graph *graph) {
    int maxdegree = graph->maxDegree();
    std::vector<int> frequency(maxdegree+1, 0);
    int nodeNo = graph->max_node();
    for (int i=0; i< nodeNo; i++) {
        frequency[graph->degree(i)]++;
    }
    int max_val = 0;
    int idx = 0;
    for (int j=0; j <= maxdegree; j++) {
        frequency[j] = frequency[j]*j;
        if(frequency[j] >= max_val) {
            max_val = frequency[j];
            idx = j;
        }
    }
    // select node with degree idx
    return graph->nodeWithDegree(idx);
}