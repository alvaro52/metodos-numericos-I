#include "gauss_jacobi.h"

#include <iostream>

constexpr uint32_t MaxIterations = 1000;

Eigen::VectorXd linear_systems_solver::gauss_jacobi(
    const Eigen::MatrixXd& A,
    const Eigen::VectorXd& b,
    double tolerance
) {
    Eigen::MatrixXd auxiliar = A;
    for (uint32_t i = 0; i < A.rows(); ++i) {
        double diagonal = auxiliar(i, i);
        auxiliar.row(i) /= -diagonal;
        auxiliar(i, i) = b(i) / diagonal;
    }

    Eigen::VectorXd result = Eigen::VectorXd::Zero(b.rows());
    for (uint32_t iteration = 0; iteration < MaxIterations; ++iteration) {
        Eigen::VectorXd new_result = Eigen::VectorXd::Zero(b.rows());
        for (uint32_t i = 0; i < A.rows(); ++i) {
            double result_i = result(i);
            result(i) = 1.0;

            new_result(i) = auxiliar.row(i) * result;

            result(i) = result_i;
        }

        if ((new_result - result).norm() < tolerance) {
            break;
        }

        result = new_result;
    }

    return result;
}
