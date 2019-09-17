#include <gtest/gtest.h>
#include <graph/graph.h>
#include <polygon/polygon.h>
#include "test_api.h"

TEST(Graph, CreateAndOutput)
{
	std::string graph_path = test::test_path("graph/algraph.txt");
	ALGraph<char> g(graph_path);
	g.print_Graph(std::cout);
	// std::vector<char> result = g.get_arcNodes(2);
	// for(auto& r : result) {
	//     fprintf(stderr, "%c ", r);
	// }
	// fprintf(stderr, "\n");
}


TEST(Polygon, Area) {
	Polygon<int> g(test::test_path("graph/polygon_area_5.txt"));
	std::cout << g.Area() << std::endl;
	ASSERT_FLOAT_EQ(10250, g.Area());

	Polygon<int> g2(test::test_path("graph/polygon_area.txt"));
	std::cout << g2.Area() << std::endl;
	ASSERT_FLOAT_EQ(198, g2.Area());
}