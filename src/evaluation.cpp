#include "evaluation.hpp"

#include <stack>

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
    }
}

// 変数の評価
void Evaluation::evaluationVar(Node node) {
    std::string value = calcExpression(node.node[2].value);
    Var tempVar(node.node[0].value, node.node[1].value, value);
    vars.push_back(tempVar);
}

// 数式を計算し、その値を返す関数
std::string Evaluation::calcExpression(std::string ex) {
    // 演算子があるかどうかによって数式かどうかを判定する
    std::vector<Token> tokens = tokenize(ex);
    bool isExpression = false;
    std::string op = "+-*/^";
    for (int i = 0; i < tokens.size() - 1; i++) {
        if (op.find(tokens[i].token) != std::string::npos) {
            isExpression = true;
            break;
        }
    }

    // 数式じゃないならそのままの値を、数式ならば計算して返す
    if (!isExpression) {
        return ex;
    } else {
        // 変数を代入
        for (int i = 0; i < tokens.size() - 1; i++) {
            for (int j = 0; j < vars.size(); j++) {
                if (tokens[i].token == vars[j].name) {
                    tokens[i].token = vars[j].value;
                }
            }
        }

        // 中置記法の数式を配列に格納
        std::vector<std::string> infixNotationArray;
        for (int i = 0; i < tokens.size() - 1; i++) {
            infixNotationArray.push_back(tokens[i].token);
        }

        std::vector<std::string> rpnArray = InfixNotationToRPN(infixNotationArray);

        return calcRPN(rpnArray);
    }
}
