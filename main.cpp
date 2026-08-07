#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokens;

bool isSymbol(char c) {
	std::string symbols = "+-*/=^(){}<>";
	if(symbols.find(c) == std::string::npos) {
		return false;
	} else {
		return true;
	}
}

void tokenize(std::string s) {
	int tokenIndex = 0;
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
}

int main(void) {
	std::string str = "41+223 - (44*2) = ";
	tokenize(str);

	std::cout << "処理前:" << str << std::endl << "処理後" << std::endl;
	for(int i = 0; i < tokens.size(); i++) {
		std::cout << tokens[i] << std::endl;
	}

	return 0;
}
