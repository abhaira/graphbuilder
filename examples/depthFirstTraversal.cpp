#include <iostream>
#include "Graph.h"
#include "GraphBuilder.h"
#include "FileParser.h"

void depthFirstTraversal(Graph& graph)
{
	for (auto& node : graph.nodes)
	{
		traversNodeDepthFirst(node);
	}
}

void birthFirstTraversal(Graph& graph)
{
	for (auto node : graph.nodes){
		traversNodeBreathFirst(node, 0);
    graph.untraversGraph();
  }
}

int main()
{
	GraphBuilder builder{"tmp", parseFile};
	Graph graph = builder.buildALGraph();
	graph.untraversGraph();
	birthFirstTraversal(graph);
	return 0;
}
