#pragma once

#include <Eigen/Dense>

namespace linear_systems_solver {
    Eigen::VectorXd gauss_jordan_solver(const Eigen::MatrixXd& A, const Eigen::VectorXd& b);
};
