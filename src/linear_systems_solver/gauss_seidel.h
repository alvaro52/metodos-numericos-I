#pragma once

#include <Eigen/Dense>

namespace linear_systems_solver {
    Eigen::VectorXd gauss_seidel(
        const Eigen::MatrixXd& A,
        const Eigen::VectorXd& b,
        double tolerance
    );
}
