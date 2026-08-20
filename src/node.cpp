#include "node.hpp"

Node::Node() {
	type = "";
	value = "";
}

Node::Node(std::string t, std::string v) {
	type = t;
	value = v;
}

// ノードの内容を再帰的に表示する関数
void Node::printNode(int depth) {
	for(int i = 0; i < depth; i++) {
		std::cout << "  ";
	}
	std::cout << type << " : " << value << std::endl;
	for(int i = 0; i < node.size(); i++) {
		node[i].printNode(depth + 1);
	}
}
