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
	std::list<std::pair<std::list<Node>::iterator, int>> childs = {};
	bool bTraversed = false;

	Node(std::string& strNodeName);
};

struct Graph
{
	std::list<Node> nodes;
	void printNodes();
	void untraversGraph();
};
#endif
