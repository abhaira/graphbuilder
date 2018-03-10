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

	Node(std::string& strNodeName) : strNode(strNodeName) {}
	Node(std::string& strNodeName, std::list<std::pair<Node, int>> childs) : strNode(strNodeName),
		childs(childs) {}
	Node(const Node& node)
	{
		strNode = node.strNode;
		childs = node.childs;
		bTraversed = node.bTraversed;
	}
	Node(Node&& node)
	{
		strNode = std::move(node.strNode);
		childs = std::move(node.childs);
		bTraversed = bTraversed;
	}
  Node& operator = (const Node& other)
  {
     if(this != &other)
     {
        strNode = other.strNode;
        childs = other.childs;
        bTraversed = other.bTraversed;
     }
     return *this;
  }
};

struct Graph
{
	std::list<Node> nodes;
	void printNodes();
};
#endif
