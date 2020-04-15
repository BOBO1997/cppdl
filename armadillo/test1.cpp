#include <iostream>
#include <armadillo>

int main() {
	arma::arma_rng::set_seed_random();
	arma::Mat<double> A = arma::randu(4,4);
	std::cout << A << std::endl;

	arma::mat B = arma::randn(4,4);
	std::cout << B << std::endl;
	arma::mat C = arma::diagmat(B);
	std::cout << C << std::endl;
	std::cout << B.t() << std::endl;
	std::cout << A * B.t() << std::endl;
	
	A.row(0) = A.row(1) + A.row(2);
	std::cout << A << std::endl;
	A.col(3).zeros();
	std::cout << A << std::endl;
	
}
