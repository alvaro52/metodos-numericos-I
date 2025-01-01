#include "gauss_jordan.h"

Eigen::VectorXd linear_systems_solver::gauss_jordan_solver(
    const Eigen::MatrixXd& A,
    const Eigen::VectorXd& b
) {
    Eigen::MatrixXd Ab(A.rows(), A.cols() + 1);
    Ab << A, b;

    for (int i = 0; i < Ab.rows(); ++i) {
        Ab.row(i) /= Ab(i, i);

        for (int j = 0; j < Ab.rows(); ++j) {
            if (i == j) {
                continue;
            }

            Ab.row(j) -= Ab.row(i) * Ab(j, i);
        }
    }

    return Ab.col(Ab.cols() - 1);
}
