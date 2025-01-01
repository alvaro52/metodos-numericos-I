#pragma once

#include <Eigen/Dense>

namespace linear_systems_solver {
    Eigen::VectorXd gauss_jacobi(
        const Eigen::MatrixXd& A,
        const Eigen::VectorXd& b,
        double tolerance
    );
}
