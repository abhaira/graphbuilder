#include "Graph.h"
#include <algorithm>
#include <iostream>

Node::Node(std::string& strNodeName) : strNode(strNodeName)
{}
Node::Node(std::string& strNodeName,
					 std::list<std::pair<Node, int>> childs) : strNode(strNodeName),
	childs(childs) {}
Node::Node(const Node& node)
{
	strNode = node.strNode;
	childs = node.childs;
	bTraversed = node.bTraversed;
}
Node::Node(Node&& node)
{
	strNode = std::move(node.strNode);
	childs = std::move(node.childs);
	bTraversed = bTraversed;
}
Node& Node::operator = (const Node& other)
{
	if (this != &other)
	{
		strNode = other.strNode;
		childs = other.childs;
		bTraversed = other.bTraversed;
	}

	return *this;
}

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

void Graph::untraversGraph()
{
	for(auto& node : nodes) { node.bTraversed = false; };
}
