#ifndef EVALUATION
#define EVALUATION

#include <string>
#include <vector>

#include "node.hpp"
#include "tokenize.hpp"
#include "var.hpp"

class Evaluation {
public:
    void evaluation(Node ast);

private:
    std::vector<Var> vars;

    void evaluationFunc(Node node);
    void evaluationVar(Node node);
    std::string calcExpression(std::string ex);
};

#endif  // EVALUATION
