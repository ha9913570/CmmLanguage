#include <vector>
#include <string>

#include "tokenize.hpp"

// 文字が記号かどうかを判定し、記号ならTrueを返す関数
bool isSymbol(char c) {
	std::string symbols = "+-*/=^(){}<>";
	if(symbols.find(c) == std::string::npos) {
		return false;
	} else {
		return true;
	}
}

// 与えられた文字列をトークン列に変換する関数
std::vector<std::string> tokenize(std::string s) {
	std::vector<std::string> tokens;
	for(int i = 0; i < s.size();) {
		std::string token = "";

		// スペース、タブ、改行など
		if(s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r') {
			i++;
			continue;
		}
		// ファイルの終端
		if(s[i] == '\0') {
			break;
		}
		// 記号
		if(isSymbol(s[i])) {
			do {
				token += s[i];
				i++;
			} while(isSymbol(s[i]) && s[i] != '\0');
		} else {
			do {
				token += s[i];
				i++;
			} while(!isSymbol(s[i]) && s[i] != '\0');
		}

		tokens.push_back(token);
	}
	return tokens;
}
