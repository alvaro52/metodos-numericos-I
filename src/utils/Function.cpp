#include "Function.h"

Function::Function(const char* expression) {
    Expression = expression;
    CompileExpression();
}

Function::Function(const std::string& expression) {
    Expression = expression;
    CompileExpression();
}

Function::Function(const Function& other) {
    Expression = other.Expression;
    CompileExpression();
}

Function::Function(Function&& expression) {
    CompiledExpression = expression.CompiledExpression;
    X = expression.X;

    expression.CompiledExpression = nullptr;
    expression.X = nullptr;
}

Function& Function::operator=(const char* expression) {
    Expression = expression;
    CompileExpression();

    return *this;
}

Function& Function::operator=(const std::string& expression) {
    Expression = expression;
    CompileExpression();

    return *this;
}

Function& Function::operator=(const Function& other) {
    Expression = other.Expression;
    CompileExpression();

    return *this;
}

Function& Function::operator=(Function&& other) {
    Expression = other.Expression;
    CompiledExpression = other.CompiledExpression;
    X = other.X;

    other.CompiledExpression = nullptr;
    other.X = nullptr;

    return *this;
}

Function::~Function() {
    te_free(CompiledExpression);
    delete X;
}

double Function::operator()(double x) const {
    *X = x;
    return te_eval(CompiledExpression);
}

void Function::CompileExpression() {
    te_free(CompiledExpression);
    delete X;

    X = new double;
    te_variable variables[] = {{"x", X}};
    CompiledExpression = te_compile(Expression.c_str(), variables, 1, nullptr);
    if (!CompiledExpression) {
        std::cerr << "Error compiling expression: " << Expression << std::endl;
    }
}
