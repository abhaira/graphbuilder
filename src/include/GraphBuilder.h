#ifndef __graph_builder_h__
#define __graph_builder_h__
#include "Graph.h"
#include <string>
#include <functional>

struct path
{
	std::string strFirstNode;
	std::string strSecondNode;
	const int cost;
};

class GraphBuilder
{
	public:
		GraphBuilder(std::string pstrInputPath,
								 std::function<std::list<path>(std::string pstrInputPath)> fnParser);
		Graph buildALGraph();

	private:
		std::list<path> m_paths;
};

#endif
