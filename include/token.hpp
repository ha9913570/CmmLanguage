#ifndef TOKEN
#define TOKEN

#include <string>

class Token {
	public:
		std::string tokenType;
		std::string token;

		void createToken(std::string type, std::string value) {
			tokenType = type;
			token = value;
		}

		std::string toString() {
			if(token == "\n") {
				return tokenType + " : \\n\n"; 
			} else if(token == "\0") {
				return tokenType + " : \\0\n";
			} else {
				return tokenType + " : " + token + "\n";
			}
		}
};

#endif // TOKEN
