
void traversNodeDepthFirst(Node& node)
{
	if (false == node.bTraversed)
	{
		node.bTraversed = true;
		std::cout << node.strNode << "\n";

		for (auto& child : node.childs)
		{
			traversNodeDepthFirst(*(std::get<0>(child)));
		}
	}
}

static void traversNodeBreathFirstInvernal(std::list<std::list<Node>::iterator>
																		levelList,
																		int currentLevel, int lastLevel)
{
	if ((0 == lastLevel || currentLevel <= lastLevel) && false == levelList.empty())
	{
		std::list<std::list<Node>::iterator> nextLevelList{};
		bool bFirst = true;

		for (const auto& node : levelList)
		{
			if (false == node->bTraversed)
			{
				if (false == bFirst)
				{
					std::cout << ",";
				}

				std::cout << node->strNode;

				for (const auto& child : node->childs)
				{
					if (false == std::get<0>(child)->bTraversed)
						nextLevelList.push_back((std::get<0>(child)));
				}

				bFirst = false;
				node->bTraversed = true;
			}
		}

		std::cout << "\n";

		traversNodeBreathFirstInvernal(nextLevelList, ++currentLevel, lastLevel);
	}
}

void traversNodeBreathFirst(Node& node, int level)
{
	std::cout << "***Traversing : " << node.strNode << " Levels : " << level <<
						"\n";
	std::list<Node> rootNode;
	rootNode.push_back(node);
	std::list<std::list<Node>::iterator> levelList {};
	levelList.push_back(rootNode.begin());
	traversNodeBreathFirstInvernal(levelList, 0, level);
}


