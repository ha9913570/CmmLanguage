#include "evaluation.hpp"

#include <stack>

#include "error.hpp"
#include "expression.hpp"
#include "function.hpp"
#include "rpn_tool.hpp"

// プログラムの評価
void Evaluation::evaluation(Node ast) {
    int childNum = (int)ast.node.size();
    for (int i = 0; i < childNum; i++) {
        if (ast.node[i].type == "call") {
            evaluationFunc(ast.node[i]);
        } else if (ast.node[i].type == "var") {
            evaluationVar(ast.node[i]);
        }
    }
}

// 関数の評価
void Evaluation::evaluationFunc(Node node) {
    std::string func = node.node[0].value;
    if (func == "prt") {
        cmm::prt(node, vars);
    } else {
        undefinedFunction(func);
    }
}

// 変数の評価
void Evaluation::evaluationVar(Node node) {
    std::string value = calcExpression(node.node[2].value, vars);
    Var tempVar(node.node[0].value, node.node[1].value, value);
    vars.push_back(tempVar);
}
