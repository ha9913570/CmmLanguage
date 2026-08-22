#ifndef EVALUATION
#define EVALUATION

#include <vector>
#include <string>

#include "tokenize.hpp"
#include "token.hpp"
#include "var.hpp"
#include "node.hpp"
#include "function.hpp"

class Evaluation {
	public:
		void evaluation(Node ast);

	private:
		std::vector<Var> vars;
		Function fn;

		void evaluationFunc(Node node);
		void evaluationVar(Node node);
		std::string calcExpression(std::string ex);
};

#endif // EVALUATION
