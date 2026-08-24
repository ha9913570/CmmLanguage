#include "error.hpp"

#include <iostream>

void undefinedFunction(std::string funcName) {
    std::cerr << "定義されていない関数(" << funcName << ")を検出しました" << std::endl;
    exit(1);
}