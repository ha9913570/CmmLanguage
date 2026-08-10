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
};

#endif // TOKEN
