#ifndef NODE
#define NODE

#include <iostream>
#include <vector>

class Node {
	public:
		std::string value;
		std::vector<Node> node;

		void printNode(int depth = 0) {
			for(int i = 0; i < depth; i++) {
				std::cout << "  ";
			}
			std::cout << value << std::endl;
			for(int i = 0; i < node.size(); i++) {
				node[i].printNode(depth + 1);
			}
		}
};

#endif // NODE
