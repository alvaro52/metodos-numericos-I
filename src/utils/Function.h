#pragma once

#include <iostream>
#include <tinyexpr.h>

class Function
{
public:
    Function(const char* expression);
    Function(const std::string& expression);
    Function(const Function& other);
    Function(Function&& expression);
    Function& operator=(const char* expression);
    Function& operator=(const std::string& expression);
    Function& operator=(const Function& other);
    Function& operator=(Function&& other);

    ~Function();

    double operator()(double x) const;

private:
    void CompileExpression();

private:
    double* X{ nullptr };
    te_expr* CompiledExpression{ nullptr };
    std::string Expression;
};
