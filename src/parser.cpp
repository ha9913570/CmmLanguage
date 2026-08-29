#include "parser.hpp"

#include "tokenize.hpp"

// 変数宣言の文かどうかを判定する関数
bool isVarDeclaration(std::string token) {
    bool result = false;
    if (token == "int" || token == "dbl") {
        result = true;
    }
    return result;
}

// プログラム全体をパースする関数
Node parseProgram(std::string program) {
    std::vector<std::string> sentences;
    std::string temp = "";
    for (int i = 0; i < program.size(); i++) {
        if (program[i] == '\n') {
            sentences.push_back(temp);
            temp = "";
        } else {
            temp += program[i];
        }
    }
    sentences.push_back(temp);

    Node rootNode("root", "program");
    for (int i = 0; i < sentences.size(); i++) {
        rootNode.node.push_back(parseSentence(sentences[i]));
    }
    return rootNode;
}

// プログラム中の1文をパースする関数
Node parseSentence(std::string sentence) {
    Node sentenceNode;

    std::vector<std::string> tokens = tokenize(sentence);

    int indentCount = countIndent(tokens);

    if (isVarDeclaration(tokens[0 + indentCount])) {
        sentenceNode = parseVarDeclaration(tokens);
        sentenceNode.type = "var";
    } else {
        sentenceNode = parseCallSentence(tokens);
        sentenceNode.type = "call";
    }

    sentenceNode.value = sentence;
    return sentenceNode;
}

// 変数宣言の文をパースする関数
Node parseVarDeclaration(std::vector<std::string> tokens) {
    int indentCount = countIndent(tokens);

    std::string value = "";
    for (int i = 3 + indentCount; i < tokens.size(); i++) {
        value += tokens[i];
    }

    // int型で小数点が見つかったら切り捨てる
    if (tokens[0 + indentCount] == "int" && value.find('.') != std::string::npos) {
        value.erase(value.find('.'));
    }

    Node mainNode;
    Node typeNode("varType", tokens[0 + indentCount]);
    Node nameNode("varName", tokens[1 + indentCount]);
    Node valueNode("varValue", value);

    mainNode.node.push_back(typeNode);
    mainNode.node.push_back(nameNode);
    mainNode.node.push_back(valueNode);

    return mainNode;
}

// 関数呼び出しの文をパースする関数
Node parseCallSentence(std::vector<std::string> tokens) {
    int indentCount = countIndent(tokens);

    // 引数ノードを作成
    std::vector<Node> argNodes;
    std::string argValue = "";
    Node tempNode("arg", "");
    for (int i = 2 + indentCount; tokens[i] != ")"; i++) {
        if (tokens[i] == ",") {
            tempNode.value = argValue;
            argNodes.push_back(tempNode);
            argValue = "";
        } else {
            argValue += tokens[i];
        }
    }
    tempNode.value = argValue;
    argNodes.push_back(tempNode);

    Node mainNode;
    Node callNode("function", tokens[0 + indentCount]);
    Node startNode("startArg", tokens[1 + indentCount]);
    Node endNode("endArg", tokens[tokens.size() - 1]);

    mainNode.node.push_back(callNode);
    mainNode.node.push_back(startNode);
    for (int i = 0; i < argNodes.size(); i++) {
        mainNode.node.push_back(argNodes[i]);
    }
    mainNode.node.push_back(endNode);

    return mainNode;
}

// トークン列に含まれるインデントの数を数える関数
int countIndent(std::vector<std::string> tokens) {
    int indentCount = 0;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "INDENT") {
            indentCount++;
        } else {
            break;
        }
    }
    return indentCount;
}
