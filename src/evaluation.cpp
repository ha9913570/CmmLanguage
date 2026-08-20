#include "evaluation.hpp"

// プログラムの評価
void Evaluation::evaluation(Node ast) {
	int childNum = ast.node.size();
	for(int i = 0; i < childNum; i++) {
		if(ast.node[i].type == "call") {
			evaluationFunc(ast.node[i]);
		} else if(ast.node[i].type == "var") {
			evaluationVar(ast.node[i]);
		}
	}
}

// 関数の評価
void Evaluation::evaluationFunc(Node node) {
	std::string func = node.node[0].value;
	if(func == "print") {
		fn.print(node, vars);
	}
}

// 変数の評価
void Evaluation::evaluationVar(Node node) {
	std::string value = calcExpression(node.node[2].value);
	Var var(node.node[0].value, node.node[1].value, value);
	vars.push_back(var);
}

// 数式を計算し、その値を返す関数
std::string Evaluation::calcExpression(std::string ex) {
	// 演算子があるかどうかによって数式かどうかを判定する
	std::vector<Token> tokens = tokenize(ex);
	bool isExpression = false;
	std::string op = "+-*/^";
	for(int i = 0; i < tokens.size() - 1; i++) {
		if(op.find(tokens[i].token) != std::string::npos) {
			isExpression = true;
			break;
		}
	}

	// 数式じゃないならそのままの値を、数式ならば計算して返す
	if(!isExpression) {
		return ex;
	} else {
		// 変数を代入
		for(int i = 0; i < tokens.size() - 1; i++) {
			for(int j = 0; j < vars.size(); j++) {
				if(tokens[i].token == vars[j].name) {
					tokens[i].token = vars[j].value;
				}
			}
		}

		// 中置記法を逆ポーランド記法に変換する
		std::string result = "";
		std::vector<std::string> resultArr;
		std::stack<std::string> opStack;
		for(int i = 0; i < tokens.size() - 1; i++) {
			if(tokens[i].tokenType != "symbol") {
				resultArr.push_back(tokens[i].token);
			} else {
				if(tokens[i].token == "(") {
					opStack.push(tokens[i].token);
				} else if(tokens[i].token == ")") {
					while(opStack.size() != 0 && opStack.top() != "(") {
						resultArr.push_back(opStack.top());
						opStack.pop();
					}
					opStack.pop();
				} else if(tokens[i].token == "^") {
					opStack.push(tokens[i].token);
				} else if(tokens[i].token == "*" || tokens[i].token == "/") {
					while(opStack.size() != 0 && opStack.top() != "(" && (opStack.top() == "^" || opStack.top() == "*" || opStack.top() == "/")) {
						resultArr.push_back(opStack.top());
						opStack.pop();
					}
					opStack.push(tokens[i].token);
				} else if(tokens[i].token == "+" || tokens[i].token == "-") {
					while(opStack.size() != 0 && opStack.top() != "(") {
						resultArr.push_back(opStack.top());
						opStack.pop();
					}
					opStack.push(tokens[i].token);
				}
			}
		}
		for(int i = 0; i < opStack.size(); i++) {
			resultArr.push_back(opStack.top());
			opStack.pop();
		}
		for(int i = 0; i < resultArr.size(); i++) {
			result += resultArr[i] + " ";
		}

		// 逆ポーランド記法を計算する
		std::stack<int> numStack;
		for(int i = 0; i < resultArr.size(); i++) {
			try{
				numStack.push(stoi(resultArr[i]));
			} catch(const std::invalid_argument& e) {
				if(resultArr[i] == "+") {
					int b = numStack.top();
					numStack.pop();
					int a = numStack.top();
					numStack.pop();
					numStack.push(a + b);
				} else if(resultArr[i] == "-") {
					int b = numStack.top();
					numStack.pop();
					int a = numStack.top();
					numStack.pop();
					numStack.push(a - b);
				} else if(resultArr[i] == "*") {
					int b = numStack.top();
					numStack.pop();
					int a = numStack.top();
					numStack.pop();
					numStack.push(a * b);
				} else if(resultArr[i] == "/") {
					int b = numStack.top();
					numStack.pop();
					int a = numStack.top();
					numStack.pop();
					numStack.push(a / b);
				} else if(resultArr[i] == "^") {
					int b = numStack.top();
					numStack.pop();
					int a = numStack.top();
					numStack.pop();
					int temp = 1;
					for(int j = 0; j < b; j++) {
						temp *= a;
					}
					numStack.push(temp);
				}
			}
		}
		return std::to_string(numStack.top());
	}
}
