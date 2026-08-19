#ifndef FUNCTION
#define FUNCTION

#include <iostream>
#include <vector>
#include <string>

#include "var.hpp"
#include "Node.hpp"

class Function {
	public:
		void print(Node node, std::vector<Var> vars) {
			std::vector<std::string> args;
			for(int i = 0; i < node.node.size(); i++) {
				if(node.node[i].type == "arg") {
					args.push_back(node.node[i].value);
				}
			}

			for(int i = 0; i < args.size(); i++) {
				// 変数かどうかを判定
				int varIndex;
				bool isVar = false;
				for(int j = 0; j < vars.size(); j++) {
					if(vars[j].name == args[i]) {
						isVar = true;
						varIndex = j;
						break;
					}
				}

				// 変数ならその値、それ以外ならそのまま出力
				if(isVar) {
					std::cout << vars[varIndex].value;
				} else {
					std::cout << args[i];
				}
			}
			std::cout << std::endl;
		}
};

#endif // FUNCTION
