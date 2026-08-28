#include "rpn_tool.hpp"

#include <iostream>
#include <stack>
#include <stdexcept>

std::vector<std::string> InfixNotationToRPN(
    std::vector<std::string> infixArray) {
    std::vector<std::string> resultArray;
    std::stack<std::string> opStack;
    for (int i = 0; i < infixArray.size(); i++) {
        // 数値ならスタックにそのまま積む
        if (std::isdigit(infixArray[i][0])) {
            resultArray.push_back(infixArray[i]);
        } else {
            if (infixArray[i] == "(") {
                opStack.push(infixArray[i]);
            } else if (infixArray[i] == ")") {
                while (!opStack.empty() && opStack.top() != "(") {
                    resultArray.push_back(opStack.top());
                    opStack.pop();
                }
                if (!opStack.empty()) {
                    opStack.pop();
                }
            } else if (infixArray[i] == "^") {
                opStack.push(infixArray[i]);
            } else if (infixArray[i] == "*" || infixArray[i] == "/") {
                while (!opStack.empty() && opStack.top() != "(" &&
                       (opStack.top() == "^" || opStack.top() == "*" ||
                        opStack.top() == "/")) {
                    resultArray.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(infixArray[i]);
            } else if (infixArray[i] == "+" || infixArray[i] == "-") {
                while (!opStack.empty() && opStack.top() != "(") {
                    resultArray.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(infixArray[i]);
            }
        }
    }
    for (int i = 0; i < opStack.size(); i++) {
        resultArray.push_back(opStack.top());
        if (!opStack.empty()) {
            opStack.pop();
        } else {
            break;
        }
    }

    return resultArray;
}

std::string calcRPN(std::vector<std::string> rpnArray) {
    std::stack<double> numStack;
    for (int i = 0; i < rpnArray.size(); i++) {
        try {
            numStack.push(stod(rpnArray[i]));
        } catch (const std::invalid_argument&) {
            if (rpnArray[i] == "+") {
                double b = numStack.top();
                numStack.pop();
                double a = numStack.top();
                numStack.pop();
                numStack.push(a + b);
            } else if (rpnArray[i] == "-") {
                double b = numStack.top();
                numStack.pop();
                double a = numStack.top();
                numStack.pop();
                numStack.push(a - b);
            } else if (rpnArray[i] == "*") {
                double b = numStack.top();
                numStack.pop();
                double a = numStack.top();
                numStack.pop();
                numStack.push(a * b);
            } else if (rpnArray[i] == "/") {
                double b = numStack.top();
                numStack.pop();
                double a = numStack.top();
                numStack.pop();
                numStack.push(a / b);
            } else if (rpnArray[i] == "^") {
                double b = numStack.top();
                numStack.pop();
                double a = numStack.top();
                numStack.pop();
                double temp = 1;
                for (double j = 0; j < b; j++) {
                    temp *= a;
                }
                numStack.push(temp);
            }
        }
    }

    // 小数点がすべて0ならその0を削除する
    double result = numStack.top();
    if (result - (int)result == 0) {
        return std::to_string((int)result);
    } else {
        return std::to_string(result);
    }
}