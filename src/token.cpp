#include "token.hpp"

void Token::createToken(std::string type, std::string value) {
    tokenType = type;
    token = value;
}

std::string Token::toString() {
    if (token == "\n") {
        return tokenType + " : \\n\n";
    } else if (token == "\0") {
        return tokenType + " : \\0\n";
    } else {
        return tokenType + " : " + token + "\n";
    }
}
