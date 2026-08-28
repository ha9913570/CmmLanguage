#include "tokenize.hpp"

#include <string>
#include <vector>

// 文字が記号かどうかを判定し、記号ならTrueを返す関数
bool isSymbol(char c) {
    std::string symbols = "+-*/=^(){}<>'\n,";
    if (symbols.find(c) == std::string::npos) {
        return false;
    } else {
        return true;
    }
}

// 文字が数字かどうかを判定し、数字ならTrueを返す関数
bool isNumber(char c) {
    std::string numbers = "0123456789";
    if (numbers.find(c) == std::string::npos) {
        return false;
    } else {
        return true;
    }
}

// 文字がスペース類かどうかを判定し、スペースならTrueを返す関数
bool isSpace(char c) {
    std::string spaces = " \t\r";
    if (spaces.find(c) == std::string::npos) {
        return false;
    } else {
        return true;
    }
}

// 与えられた文字列をトークン列に変換する関数
std::vector<std::string> tokenize(std::string s) {
    std::vector<std::string> tokens;
    for (int i = 0; i < s.size();) {
        std::string value = "";

        // スペース、タブ、改行など
        if (isSpace(s[i])) {
            i++;
            continue;
        }
        // ファイルの終端
        if (s[i] == '\0') {
            break;
        }

        if (s[i] == '\n') {
            value += s[i];
            i++;
        } else if (isSymbol(s[i])) {
            do {
                value += s[i];
                i++;
            } while (value.find(s[i]) != std::string::npos);
        } else if (isNumber(s[i])) {
            do {
                value += s[i];
                i++;
            } while (isNumber(s[i]) || s[i] == '.');
        } else if (s[i] == '"') {
            do {
                value += s[i];
                i++;
            } while (s[i] != '"');
            value += '"';
            i++;
        } else {
            do {
                value += s[i];
                i++;
            } while (!isSymbol(s[i]) && !isNumber(s[i]) && !isSpace(s[i]) && s[i] != '\0');
        }
        tokens.push_back(value);
    }

    return tokens;
}
