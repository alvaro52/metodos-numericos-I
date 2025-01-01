#include "gauss_seidel.h"

constexpr uint32_t MaxIterations = 1000;

Eigen::VectorXd linear_systems_solver::gauss_seidel(
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
    Eigen::VectorXd new_result = Eigen::VectorXd::Zero(b.rows());
    for (uint32_t iteration = 0; iteration < MaxIterations; ++iteration) {
        for (uint32_t i = 0; i < A.rows(); ++i) {
            double sum = 0.0;
            for (uint32_t j = 0; j < A.cols(); ++j) {
                if (j < i) {
                    sum += auxiliar(i, j) * new_result(j);
                } else if (j == i) {
                    sum += auxiliar(i, j);
                } else {
                    sum += auxiliar(i, j) * result(j);
                }
            }

            new_result(i) = sum;
        }

        if ((new_result - result).norm() < tolerance) {
            break;
        }

        result = new_result;
    }

    return result;
}
