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
	std::list<std::pair<Node, int>> childs = {};
	bool bTraversed = false;

	Node(std::string& strNodeName);
	Node(std::string& strNodeName, std::list<std::pair<Node, int>> childs);
	Node(const Node& node);
	Node(Node&& node);
	Node& operator = (const Node& other);
};

struct Graph
{
	std::list<Node> nodes;
	void printNodes();
	void untraversGraph();
};
#endif
