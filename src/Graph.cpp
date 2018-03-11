#include "Graph.h"
#include <algorithm>
#include <iostream>

Node::Node(std::string& strNodeName) : strNode(strNodeName)
{}

void Graph::printNodes()
{
	for(const auto&  node : nodes)
	{
		std::cout << node.strNode << " :: {" ;

		for (auto& child : node.childs)
		{
			std::cout << (std::get<0>(child))->strNode << ",";
		}

		std::cout << "}" << std::endl;
	}
}

void Graph::untraversGraph()
{
	for (auto& node : nodes) { node.bTraversed = false; };
}
