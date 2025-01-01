#include "root_finding.h"

constexpr uint32_t MaxIterations = 1000;

root_finding::Result root_finding::bisection(
    const Function& f,
    double lower_bound,
    double upper_bound,
    double tolerance
) {
    Iterations iterations;
    for (uint32_t i = 0 ; i < MaxIterations ; ++i) {
        double x = (lower_bound + upper_bound) / 2;
        double fx = f(x);

        iterations.push_back({ x, fx });

        bool is_root = std::abs(fx) < tolerance;
        bool converged = std::abs(upper_bound - lower_bound) < tolerance;
        if (is_root || converged) {
            return iterations;
        }

        if (fx * f(lower_bound) > 0) {
            lower_bound = x;
        } else {
            upper_bound = x;
        }
    }

    return std::nullopt;
}

root_finding::Result root_finding::false_position(
    const Function& f,
    double lower_bound,
    double upper_bound,
    double tolerance
) {
    Iterations iterations;
    for (uint32_t i = 0 ; i < MaxIterations ; ++i) {
        double x = (lower_bound * f(upper_bound) - upper_bound * f(lower_bound))
                   / (f(upper_bound) - f(lower_bound));
        double fx = f(x);

        iterations.push_back({ x, fx });

        bool is_root = std::abs(fx) < tolerance;
        bool converged = std::abs(upper_bound - lower_bound) < tolerance;
        if (is_root || converged) {
            return iterations;
        }

        if (fx * f(lower_bound) > 0) {
            lower_bound = x;
        } else {
            upper_bound = x;
        }
    }

    return std::nullopt;
}

root_finding::Result root_finding::newton(
    const Function& f,
    double x,
    double tolerance
) {
    Iterations iterations;
    auto df = [&](double x) { return (f(x + 1e-4) - f(x - 1e-4)) / (2.0 * 1e-4); };
    for (uint32_t i = 0 ; i < MaxIterations ; ++i) {
        x -= f(x) / df(x);
        double fx = f(x);

        iterations.push_back({ x, fx });

        if (std::abs(fx) < tolerance) {
            return iterations;
        }
    }

    return std::nullopt;
}

root_finding::Result root_finding::secant(
    const Function& f,
    double x0,
    double x1,
    double tolerance
) {
    Iterations iterations;
    for (uint32_t i = 0; i < MaxIterations; ++i) {
        double fx1 = f(x1);
        double fx0 = f(x0);
        double x = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        double fx = f(x);

        iterations.push_back({ x, fx });

        if (std::abs(fx) < tolerance) {
            return iterations;
        }

        x0 = x1;
        x1 = x;
    }

    return std::nullopt;
}

root_finding::Result root_finding::fixed_point(
    const Function& f,
    double x,
    double tolerance
) {
    Iterations iterations;
    for (uint32_t i = 0; i < MaxIterations; ++i) {
        double fx = f(x);
        iterations.push_back({ x, fx });

        if (std::abs(fx) < tolerance) {
            return iterations;
        }

        x = fx;
    }

    return std::nullopt;
}

std::ostream& root_finding::operator<<(std::ostream& os, const Result& result) {
    if (!result) {
        os << "\nNo root found\n";
        return os;
    }

    os.setf(std::ios::fixed);

    os << "\n   i                x                f(x)\n\n";
    unsigned long int i = 1;
    for (const auto& iteration : result.value()) {
        os << std::setw(4) << i++
        << std::setw(17) <<  iteration.x
        << std::setw(20) << iteration.fx << "\n";
    }

    os.unsetf(std::ios::fixed);

    return os;
}
