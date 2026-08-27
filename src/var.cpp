#include "var.hpp"

Var::Var() {
    type = "";
    name = "";
    value = "";
}

Var::Var(std::string t, std::string n, std::string v) {
    type = t;
    name = n;
    value = v;
}
