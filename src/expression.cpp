#include "expression.hpp"

#include "rpn_tool.hpp"
#include "tokenize.hpp"

// 数式を計算し、その値を返す関数
std::string calcExpression(std::string ex, std::vector<Var> vars) {
    // 演算子があるかどうかによって数式かどうかを判定する
    std::vector<std::string> tokens = tokenize(ex);
    bool isExpression = false;
    std::string op = "+-*/^";
    for (int i = 0; i < tokens.size(); i++) {
        if (op.find(tokens[i]) != std::string::npos) {
            isExpression = true;
            break;
        }
    }

    // 変数を代入
    for (int i = 0; i < tokens.size(); i++) {
        for (int j = 0; j < vars.size(); j++) {
            if (tokens[i] == vars[j].name) {
                tokens[i] = vars[j].value;
            }
        }
    }

    // 数式じゃないならそのままの値を、数式ならば計算して返す
    if (!isExpression) {
        std::string result = "";
        for (int i = 0; i < tokens.size(); i++) {
            // トークン中のリテラルを表すダブルクォーテーションを削除
            if (tokens[i][0] == '"') {
                tokens[i] = tokens[i].substr(1, tokens[i].size() - 2);
            }
            result += tokens[i];
        }
        return result;
    } else {
        // 中置記法の数式を配列に格納
        std::vector<std::string> infixNotationArray;
        for (int i = 0; i < tokens.size(); i++) {
            infixNotationArray.push_back(tokens[i]);
        }

        std::vector<std::string> rpnArray = InfixNotationToRPN(infixNotationArray);

        return calcRPN(rpnArray);
    }
}
