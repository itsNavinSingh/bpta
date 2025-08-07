#include "vcp.h"

std::vector<int>VertexCoverProblem(Graph graph){
    std::vector<int>output;
    int node = 0;
    while (!graph.isDisconnected())
    {
        // get maxdegree node
        node = graph.getMaxDegreeNode();
        // push node to output
        output.push_back(node);
        // remove the node
        graph.remove_node(node);
    }
    
    return output;
}