#pragma once

#include "root_finding.h"

namespace root_finding_test {
    const Function f = "e^x - 4 * x * x";
    constexpr double tolerance = 1e-4;

    void test_bisection();
    void test_false_position();
    void test_newton();
    void test_secant();
    void test_fixed_point();

    void test_all();
}