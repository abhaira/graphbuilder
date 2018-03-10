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
	Graph m_graph;

	for (auto path : m_paths)
	{
		{
			auto nodeLocInGraph = std::find_if(m_graph.nodes.begin(),
			m_graph.nodes.end(), [&path](const Node & node) { return node.strNode == path.strFirstNode; });

			if (nodeLocInGraph == m_graph.nodes.end())
			{
				m_graph.nodes.push_back(Node(path.strFirstNode, {{Node(path.strSecondNode), path.cost}}));
			}
			else
			{
				nodeLocInGraph->childs.push_back({Node(path.strSecondNode), path.cost});
			}
		}
		{
			auto nodeLocInGraph = std::find_if(m_graph.nodes.begin(),
			m_graph.nodes.end(), [&path](const Node & node) { return node.strNode == path.strSecondNode; });

			// If we have seen this node first time. Lets add it to our list too.
			if (nodeLocInGraph == m_graph.nodes.end())
			{
				m_graph.nodes.push_back(Node(path.strSecondNode));
			}
		}
	}

	return m_graph;
}
