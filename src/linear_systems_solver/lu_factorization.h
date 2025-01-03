#pragma once

#include <Eigen/Dense>

namespace linear_systems_solver {
    struct LU {  Eigen::MatrixXd L, U; };

    LU              lu_factorization(const Eigen::MatrixXd& A);
    Eigen::VectorXd lu_solver(const LU& lu, const Eigen::VectorXd& b);
    Eigen::VectorXd lu_solver(const Eigen::MatrixXd& A, const Eigen::VectorXd& b);
}
