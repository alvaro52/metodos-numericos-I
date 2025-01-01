#include "root_finding_test.h"

void root_finding_test::test_bisection() {
    root_finding::Result result = root_finding::bisection(f, 0.5, 1, tolerance);
    std::cout << "\nBisection: " << result;
}

void root_finding_test::test_false_position() {
    root_finding::Result result = root_finding::false_position(f, 0.5, 1, tolerance);
    std::cout << "\nFalse Position: " << result;
}

void root_finding_test::test_newton() {
    root_finding::Result result = root_finding::newton(f, 1, tolerance);
    std::cout << "\nNewton: " << result;
}

void root_finding_test::test_secant() {
    root_finding::Result result = root_finding::secant(f, 0, 2, tolerance);
    std::cout << "\nSecant: " << result;
}

void root_finding_test::test_fixed_point() {
    root_finding::Result result = root_finding::fixed_point(f, 0.5, tolerance);
    std::cout << "\nFixed Point: " << result;
}

void root_finding_test::test_all() {
    test_bisection();
    test_false_position();
    test_newton();
    test_secant();
    test_fixed_point();
}
