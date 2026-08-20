#ifndef NODE
#define NODE

#include <iostream>
#include <vector>

class Node {
	public:
		std::string type;
		std::string value;
		std::vector<Node> node;

		Node();
		Node(std::string t, std::string v);
		void printNode(int depth = 0);
};

#endif // NODE
