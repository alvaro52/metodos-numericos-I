#include "gauss_elimination.h"

void            to_row_echelon_form(Eigen::MatrixXd& Ab);
Eigen::VectorXd back_substitution  (const Eigen::MatrixXd& Ab);

Eigen::VectorXd linear_systems_solver::gauss_elimination_solver(
    const Eigen::MatrixXd& A,
    const Eigen::VectorXd& b
) {
    Eigen::MatrixXd Ab(A.rows(), A.cols() + 1);
    Ab << A, b;

    to_row_echelon_form(Ab);

    return back_substitution(Ab);
}

void to_row_echelon_form(Eigen::MatrixXd& Ab) {
    for (int i = 0 ; i < Ab.rows() ; i++) {
        for (int j = i + 1 ; j < Ab.rows() ; j++) {
            double factor = Ab(j, i) / Ab(i, i);
            Ab.row(j) -= factor * Ab.row(i);
        }
    }
}

Eigen::VectorXd back_substitution(const Eigen::MatrixXd& Ab) {
    Eigen::VectorXd result(Ab.rows());
    for (int i = Ab.rows() - 1 ; i >= 0 ; i--) {
        double sum = 0;
        for (int j = i + 1 ; j < Ab.cols() - 1 ; j++) {
            sum += Ab(i, j) * result(j, 0);
        }
        result(i, 0) = (Ab(i, Ab.cols() - 1) - sum) / Ab(i, i);
    }

    return result;
}
