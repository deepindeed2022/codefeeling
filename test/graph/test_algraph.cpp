#include <gtest/gtest.h>
#include <graph/graph.h>
#include "../test_api.h"

TEST(Graph, CreateAndOutput)
{
    std::string graph_path = test_path("../test/graph/algraph.txt");
    ALGraph<char> g(graph_path);
    g.print_Graph(std::cout);
    // std::vector<char> result = g.get_arcNodes(2);
    // for(auto& r : result) {
    //     fprintf(stderr, "%c ", r);
    // }
	// fprintf(stderr, "\n");
}