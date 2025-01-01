#include "linear_systems_solver_test.h"

#include <cassert>
#include <iostream>

#include "gauss_elimination.h"
#include "gauss_jordan.h"
#include "lu_factorization.h"
#include "gauss_jacobi.h"
#include "gauss_seidel.h"

void linear_systems_solver_test::test_gauss_elimination_solver() {
    Eigen::MatrixXd A(3, 3);

    A << -3, 2,-1,
          6,-6, 7,
          3,-4, 4;

    Eigen::MatrixXd b(3, 1);
    b << -1,
         -7,
         -6;

    Eigen::VectorXd result =
        linear_systems_solver::gauss_elimination_solver(A, b);

    Eigen::VectorXd expected_result(3, 1);
    expected_result << 2,
                       2,
                      -1;

    assert(result.isApprox(expected_result));

    std::cout << "\n\nGauss elimination test:" << std::endl;
    std::cout << "\n\nMatrix A:\n\n";
    std::cout << A << std::endl;

    std::cout << "\n\nMatrix b:\n\n";
    std::cout << b << std::endl;

    std::cout << "\n\nResult:\n\n";
    std::cout << result << std::endl;
}

void linear_systems_solver_test::test_gauss_jordan_elimination_solver() {
    Eigen::MatrixXd A(3, 3);

    A << -3, 2,-1,
          6,-6, 7,
          3,-4, 4;

    Eigen::MatrixXd b(3, 1);
    b << -1,
         -7,
         -6;

    Eigen::VectorXd result = linear_systems_solver::gauss_jordan_solver(A, b);

    Eigen::VectorXd expected_result(3, 1);
    expected_result << 2,
                       2,
                      -1;

    assert(result.isApprox(expected_result));

    std::cout << "\n\nGauss-Jordan elimination test:" << std::endl;
    std::cout << "\n\nMatrix A:\n\n";
    std::cout << A << std::endl;

    std::cout << "\n\nMatrix b:\n\n";
    std::cout << b << std::endl;

    std::cout << "\n\nResult:\n\n";
    std::cout << result << std::endl;
}

void linear_systems_solver_test::test_lu_factorization() {
    Eigen::MatrixXd A(4, 4);

    A << 2, 4, 3, 5,
        -4,-7,-5,-8,
         6, 8, 2, 9,
         4, 9,-2,14;

    std::cout << "\n\nLU factorization test:" << std::endl;
    std::cout << "Before LU factorization:" << std::endl;
    std::cout << A << std::endl;

    linear_systems_solver::LU lu = linear_systems_solver::lu_factorization(A);

    Eigen::MatrixXd expected_L(4, 4);
    expected_L << 1, 0, 0, 0,
                 -2, 1, 0, 0,
                  3,-4, 1, 0,
                  2, 1, 3, 1;

    Eigen::MatrixXd expected_U(4, 4);
    expected_U << 2, 4, 3, 5,
                  0, 1, 1, 2,
                  0, 0,-3, 2,
                  0, 0, 0,-4;

    assert(lu.L.isApprox(expected_L));
    assert(lu.U.isApprox(expected_U));

    std::cout << "\n\nAfter LU factorization:" << std::endl;
    std::cout << "\nL:\n\n" << lu.L << std::endl;
    std::cout << "\n\nU:\n\n" << lu.U << std::endl;
}

void linear_systems_solver_test::test_lu_solver() {
    Eigen::MatrixXd A(3, 3);

    A << -3, 2,-1,
          6,-6, 7,
          3,-4, 4;

    Eigen::MatrixXd b(3, 1);
    b << -1,
         -7,
         -6;

    Eigen::VectorXd result = linear_systems_solver::lu_solver(A, b);

    Eigen::VectorXd expected_result(3, 1);
    expected_result << 2,
                       2,
                      -1;

    assert(result.isApprox(expected_result));
}

void linear_systems_solver_test::test_gauss_jacobi_solver() {
    Eigen::MatrixXd A(3, 3);
    A << 10, 2, 1,
            1, 5, 1,
            2, 3, 10;

    Eigen::VectorXd b(3);
    b << 7,
            -8,
            6;


    Eigen::VectorXd result = linear_systems_solver::gauss_jacobi(A, b, 1e-12);

    std::cout << "\n\nGauss Jacobi test:" << std::endl;
    std::cout << "\n\nMatrix A:\n\n";
    std::cout << A << std::endl;
    std::cout << "\n\nMatrix b:\n\n";
    std::cout << b << std::endl;
    std::cout << "\n\nResult:\n\n";
    std::cout << result << std::endl;

    Eigen::VectorXd expectedResult(3);
    expectedResult << 1,
                     -2,
                      1;

    assert(expectedResult.isApprox(result));
}

void linear_systems_solver_test::test_gauss_seidel_solver() {
    Eigen::MatrixXd A(3, 3);

    A << 10, 2, 1,
            1, 5, 1,
            2, 3, 10;

    Eigen::VectorXd b(3);
    b << 7,
            -8,
            6;


    Eigen::VectorXd result = linear_systems_solver::gauss_seidel(A, b, 1e-12);

    std::cout << "\n\nGauss Jacobi test:" << std::endl;
    std::cout << "\n\nMatrix A:\n\n";
    std::cout << A << std::endl;
    std::cout << "\n\nMatrix b:\n\n";
    std::cout << b << std::endl;
    std::cout << "\n\nResult:\n\n";
    std::cout << result << std::endl;

    Eigen::VectorXd expectedResult(3);
    expectedResult << 1,
                     -2,
                      1;

    assert(expectedResult.isApprox(result));
}

void linear_systems_solver_test::test_all() {
    test_gauss_elimination_solver();
    test_gauss_jordan_elimination_solver();
    test_lu_factorization();
    test_lu_solver();
    test_gauss_jacobi_solver();
    test_gauss_seidel_solver();
}