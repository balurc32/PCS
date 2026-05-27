#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include <Eigen/Eigen>

struct ris_gradiente_coniugato {
	bool convergenza = false;
	int iterazioni = 0;
	double residuo = 0.0;
	Eigen::VectorXd x; 
	
	void gc(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, const double r_tol, const int max_it)
	{
		x = Eigen::VectorXd::Zero(b.size());
		Eigen::VectorXd r = b - A*x;
		Eigen::VectorXd p = r;
		// Eigen::VectorXd res_prec = Eigen::VectorXd::Zero(b.size());
		
		iterazioni = 0;
		residuo = r.norm();
		
		while (iterazioni < max_it && residuo > r_tol)
		{
			const double alpha_k = ((p.transpose() * r) / (p.transpose() * A * p)).value();
			
			x = x + alpha_k * p;
			r = b - A * x;
			residuo = r.norm();
			
			const double beta_k = ((p.transpose() * A * r) / (p.transpose() * A * p)).value();
			
			p = r - beta_k * p;
			iterazioni = iterazioni + 1;
			
			if (residuo <= r_tol)
			{
				convergenza = true;
			}
			else 
			{
				convergenza = false;
			}
		}
	}
};