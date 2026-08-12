#ifndef EVALUATION
#define EVALUATION

#include <iostream>
#include <vector>
#include <string>

#include "var.hpp"
#include "Node.hpp"
#include "function.hpp"

class Evaluation {
	public:
		// プログラムの評価
		void evaluation(Node ast) {
			int childNum = ast.node.size();
			for(int i = 0; i < childNum; i++) {
				if(ast.node[i].type == "call") {
					evaluationFunc(ast.node[i]);
				} else if(ast.node[i].type == "var") {
					evaluationVar(ast.node[i]);
				}
			}
		}

	private:
		std::vector<Var> vars;
		Function fn;

		// 関数の評価
		void evaluationFunc(Node node) {
			std::string func = node.node[0].value;
			if(func == "print") {
				fn.print(node, vars);
			}
		}
		// 変数の評価
		void evaluationVar(Node node) {
			Var var(node.node[0].value, node.node[1].value, node.node[2].value);
			vars.push_back(var);
		}
};

#endif // EVALUATION
