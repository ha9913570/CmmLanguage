#ifndef VAR
#define VAR

#include <string>

struct Var {
    std::string type;
    std::string name;
    std::string value;

    Var();
    Var(std::string t, std::string n, std::string v);
};

#endif  // VAR
