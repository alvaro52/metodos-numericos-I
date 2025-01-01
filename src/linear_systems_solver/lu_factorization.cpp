#include "lu_factorization.h"

Eigen::VectorXd forward_substitution (const Eigen::MatrixXd& L, const Eigen::VectorXd& b);
Eigen::VectorXd backward_substitution(const Eigen::MatrixXd& U, const Eigen::VectorXd& y);

linear_systems_solver::LU linear_systems_solver::lu_factorization(
    const Eigen::MatrixXd& A
) {
    Eigen::MatrixXd L = Eigen::MatrixXd::Identity(A.rows(), A.cols());
    Eigen::MatrixXd U = A;
    for (int i = 0; i < U.rows(); i++) {
        for (int j = i + 1; j < U.rows(); j++) {
            double factor = U(j, i) / U(i, i);
            L(j, i) = factor;
            U.row(j) -= factor * U.row(i);
        }
    }

    return LU{ L, U };
}

Eigen::VectorXd linear_systems_solver::lu_solver(
    const Eigen::MatrixXd& A,
    const Eigen::VectorXd& b
) {
    LU lu = lu_factorization(A);
    Eigen::VectorXd y = forward_substitution(lu.L, b);

    return backward_substitution(lu.U, y);
}

Eigen::VectorXd forward_substitution(
    const Eigen::MatrixXd& L,
    const Eigen::VectorXd& b
) {
    Eigen::VectorXd y(L.rows());
    for (int i = 0; i < L.rows(); i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L(i, j) * y(j);
        }
        y(i) = (b(i) - sum) / L(i, i);
    }

    return y;
}

Eigen::VectorXd backward_substitution(
    const Eigen::MatrixXd& U,
    const Eigen::VectorXd& y
) {
    Eigen::VectorXd x(U.rows());
    for (int i = U.rows() - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < U.cols(); j++) {
            sum += U(i, j) * x(j);
        }
        x(i) = (y(i) - sum) / U(i, i);
    }

    return x;
}
