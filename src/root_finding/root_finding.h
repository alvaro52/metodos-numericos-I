#pragma once

#include <iomanip>
#include <optional>
#include <ostream>
#include <vector>

#include "../utils/Function.h"

namespace root_finding {
    struct Iteration { double x, fx; };
    using Iterations = std::vector<Iteration>;
    using Result     = std::optional<Iterations>;

    Result bisection     (const Function& f, double a, double b, double tol);
    Result false_position(const Function& f, double a, double b, double tol);
    Result newton        (const Function& f, double x, double tol);
    Result secant        (const Function& f, double x0, double x1, double tolerance);
    Result fixed_point   (const Function& f, double x, double tolerance);

    std::ostream& operator<<(std::ostream& os, const Result& result);
}
