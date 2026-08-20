#ifndef FUNCTION
#define FUNCTION

#include <iostream>
#include <vector>
#include <string>

#include "var.hpp"
#include "Node.hpp"

class Function {
	public:
		void print(Node node, std::vector<Var> vars);
};

#endif // FUNCTION
