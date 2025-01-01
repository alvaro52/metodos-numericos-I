#include "root_finding/root_finding_test.h"
#include "linear_systems_solver/linear_systems_solver_test.h"

int main() {
    root_finding_test::test_all();
    linear_systems_solver_test::test_all();
}
