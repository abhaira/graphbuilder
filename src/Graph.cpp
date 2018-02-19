#include "Graph.h"
#include <algorithm>
#include <iostream>

void Graph::printNodes()
{
	std::for_each(nodes.begin(), nodes.end(), [](const Node & node)
	{
		std::cout << node.strNode << " :: {" ;
		std::for_each(node.childs.begin(), node.childs.end(),
		[](std::pair<Node, int> child) { std::cout << std::get<0>(child).strNode << ",";});
		std::cout << "}" << std::endl;
	});
}
