#include <iostream>
// #include "vcp.h"
#include "clique.h"
#include <fstream>

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "No input file given\nProgram Exited" << std::endl;
        return 1;
    }

    const char* filename = argv[1];
    std::ifstream file(filename);

    if(!file) {
        std::cout << "Error opening file : " << filename << std::endl;
        return 1;
    }
    int numberNode;
    file >> numberNode;
    Graph graph(numberNode);
    int edge1, edge2;
    while(file >> edge1 >> edge2) {
        graph.add_edge(edge1, edge2);
    }
    file.close();
    // std::vector<int> result = VertexCoverProblem(graph);
    std::vector<int> result = Clique(graph);
    std::ofstream output(argv[2]);
    if (!output) {
        std::cout << "Error creating the output file" << std::endl;
        return 1;
    }
    for (int number : result) {
        output << number << "\n";
    }
    output.close();
    std::cout << "Program Computed Successfully" << std::endl;
    return 0;
}