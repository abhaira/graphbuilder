#ifndef __graph_h__
#define __graph_h__
#include <list>
#include <string>

struct ErrorInvalidGraph
{
};

struct Node
{
	std::string strNode;
	std::list<std::pair<Node, int>> childs;
};

struct Graph
{
	std::list<Node> nodes;
	void printNodes();
};
#endif
