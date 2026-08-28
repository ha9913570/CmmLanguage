#include "function.hpp"

#include <iostream>
#include <string>

#include "expression.hpp"

// 標準出力に値を表示する関数
void cmm::prt(Node node, std::vector<Var> vars) {
    std::vector<std::string> args;
    for (int i = 0; i < node.node.size(); i++) {
        if (node.node[i].type == "arg") {
            args.push_back(node.node[i].value);
        }
    }

    // 引数が複数指定されているならそれらを結合して表示する
    for (int i = 0; i < args.size(); i++) {
        std::cout << calcExpression(args[i], vars);
    }

    std::cout << std::endl;
}
