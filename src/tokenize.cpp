#include <vector>
#include <string>
#include <iostream>

#include "token.hpp"
#include "tokenize.hpp"

// 文字が記号かどうかを判定し、記号ならTrueを返す関数
bool isSymbol(char c) {
	std::string symbols = "+-*/=^(){}<>'\n,";
	if(symbols.find(c) == std::string::npos) {
		return false;
	} else {
		return true;
	}
}

// 文字が数字かどうかを判定し、数字ならTrueを返す関数
bool isNumber(char c) {
	std::string numbers = "0123456789";
	if(numbers.find(c) == std::string::npos) {
		return false;
	} else {
		return true;
	}
}

// 文字がスペース類かどうかを判定し、スペースならTrueを返す関数
bool isSpace(char c) {
	std::string spaces = " \t\r";
	if(spaces.find(c) == std::string::npos) {
		return false;
	} else {
		return true;
	}
}

// 与えられた文字列をトークン列に変換する関数
std::vector<Token> tokenize(std::string s) {
	std::vector<Token> tokens;
	for(int i = 0; i < s.size();) {
		Token token;
		std::string value = "";
		std::string type = "string";

		// スペース、タブ、改行など
		if(isSpace(s[i])) {
			i++;
			continue;
		}
		// ファイルの終端
		if(s[i] == '\0') {
			break;
		} 

		if(s[i] == '\n') {
			type = "end";
			value += s[i];
			i++;
		} else if(isSymbol(s[i])) {
			type = "symbol";
			do {
				value += s[i];
				i++;
			} while(value.find(s[i]) != std::string::npos);
		} else if(isNumber(s[i])) {
			type = "int";
			do {
				value += s[i];
				i++;
			} while(isNumber(s[i]));
		} else if(s[i] == '"') {
			do {
				i++;
				value += s[i];
				if(s[i + 1] == '"') {
					i += 2;
					break;
				}
			} while(1);
		} else {
			do {
				value += s[i];
				i++;
			} while(!isSymbol(s[i]) && !isNumber(s[i]) && !isSpace(s[i]) && s[i] != '\0');
		}

		token.createToken(type, value);
		tokens.push_back(token);
	}

	Token eofToken;
	eofToken.createToken("eof", "\0");
	tokens.push_back(eofToken);

	return tokens;
}
