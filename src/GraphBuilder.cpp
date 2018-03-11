#include <list>
#include <functional>
#include <string>
#include <algorithm>
#include <iostream>
#include <string.h>

#include "Graph.h"
#include "GraphBuilder.h"

GraphBuilder::GraphBuilder(std::string pstrInputPath,
													 std::function<std::list<path>(std::string pstrInputPath)> fnParser)
{
	m_paths = fnParser(pstrInputPath);

	if (true == m_paths.empty())
	{
		throw ErrorInvalidGraph();
	}
}

Graph GraphBuilder::buildALGraph()
{
	Graph graph;

	for (auto path : m_paths)
	{
		auto firstNodeLoc  = std::find_if(graph.nodes.begin(),
		graph.nodes.end(), [&path](const Node & node) { return node.strNode == path.strFirstNode; });

		auto secNodeLoc  = std::find_if(graph.nodes.begin(),
		graph.nodes.end(), [&path](const Node & node) { return node.strNode == path.strSecondNode; });

		if (firstNodeLoc  == graph.nodes.end())
			firstNodeLoc = graph.nodes.insert(graph.nodes.end(), Node(path.strFirstNode));

		if (secNodeLoc == graph.nodes.end())
			secNodeLoc = graph.nodes.insert(graph.nodes.end(), Node(path.strSecondNode));

		firstNodeLoc->childs.push_back({secNodeLoc, path.cost});
	}

	return graph;
}
