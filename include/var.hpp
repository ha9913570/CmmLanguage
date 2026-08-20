#ifndef VAR
#define VAR

#include <string>

class Var {
	public:
		std::string type;
		std::string name;
		std::string value;

		Var();
		Var(std::string t, std::string n, std::string v);
		std::string toString();
};

#endif // VAR
