#include <gtest/gtest.h>
#include <graph/graph.h>

TEST(Graph, CreateAndOutput)
{
    std::string graph_path = "graph/algraph.txt";
    ALGraph<char> g(graph_path);
    g.print_Graph(std::cout);
}