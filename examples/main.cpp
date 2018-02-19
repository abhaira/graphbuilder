#include <iostream>
#include "Graph.h"
#include "GraphBuilder.h"
#include "FileParser.h"

int main()
{
	GraphBuilder builder{"tmp", parseFile};
	Graph graph = builder.buildALGraph();
	graph.printNodes();
	return 0;
}
