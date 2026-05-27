#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include <Eigen/Eigen>
#include "gradiente_coniugato.hpp"

int main(int argc, char **argv)
{
	//const double tol = 1.0e-8;
	unsigned int n = 3;
	
	Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
	/* commentato il check sull'invertibilità della radice B perché B (generata con random di Eigen)
	mi da sempre una matrice con determinante nullo che quindi entra nell'if e blocca il programma.
	Gemini suggerisce di utilizzare Eigen::MatrixXd B = Eigen::MatrixXd::Identity(n, n) * 2.0 per
	evitare il problema. In questo modo però la matrice generata non è più random ma sempre la
	matrice identità moltiplicata per 2. */
	
	//Eigen::MatrixXd B = Eigen::MatrixXd::Identity(n, n) * 2.0;
	/*if (abs(B.determinant()) < tol)
	{
		std::cout << "mimimi\n" << abs(B.determinant()) << "\n";
		return -1;
	}*/
	
	Eigen::MatrixXd A = B.transpose() * B;
	Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
	Eigen::VectorXd b = A*x_ex;
	
	ris_gradiente_coniugato sol;
	//double r_tol;
	//int max_it;
	
	/* std::cout << "Inserisci la tolleranza: " ;
	std::cin >> r_tol;
	std::cout << "\n";
	std::cout << "Inserisci il numero massimo di iterazioni: ";
	std::cin >> max_it;
	std::cout << "\n"; */
	const double r_tol = 1.0e-10;
	const int max_it = 1000;
	sol.gc(A, b, r_tol, max_it);
	
	std::cout << "\nTEST GRADIENTE CONIUGATO \n";
	
	if (sol.convergenza == true)
	{
		std::cout << " - Converge \n";
	}
	else
	{
		std::cout << " - Non converge \n";
	}
	
	std::cout << std::scientific << " - Numero di iterazioni: " <<  sol.iterazioni << " su " << max_it << "\n";
	std::cout << std::scientific << " - Residuo: " <<  sol.residuo  << "su " << r_tol << "\n";
	
	double err_rel = (sol.x - x_ex).norm() / x_ex.norm();
	std::cout << std::scientific << " - Errore relativo: " <<  err_rel << "\n";
	std::cout << " - Vettore soluzione esatta: \n" << x_ex.transpose() << "\n";
	std::cout << " - Vettore soluzione calcolata: \n" << sol.x.transpose() << "\n";
	
	
	// test con n=100
	
	unsigned int n2 = 100;
	Eigen::MatrixXd B2 = Eigen::MatrixXd::Random(n2, n2);
	
	Eigen::MatrixXd A2 = B2.transpose() * B2;
	Eigen::VectorXd x2_ex = Eigen::VectorXd::Ones(n2);
	Eigen::VectorXd b2 = A2*x2_ex;
	
	ris_gradiente_coniugato sol2;
	sol2.gc(A2, b2, r_tol, max_it);
	
	std::cout << "\nTEST GRADIENTE CONIUGATO con n=100 \n";
	
	if (sol2.convergenza == true)
	{
		std::cout << " - Converge \n";
	}
	else
	{
		std::cout << " - Non converge \n";
	}
	
	std::cout << std::scientific << " - Numero di iterazioni: " <<  sol2.iterazioni << " su " << max_it << "\n";
	std::cout << std::scientific << " - Residuo: " <<  sol2.residuo  << "su " << r_tol << "\n";
	
	double err_rel2 = (sol2.x - x2_ex).norm() / x2_ex.norm();
	std::cout << std::scientific << " - Errore relativo: " <<  err_rel2 << "\n";
	std::cout << " - Vettore soluzione esatta: \n" << x2_ex.transpose() << "\n";
	std::cout << " - Vettore soluzione calcolata: \n" << sol2.x.transpose() << "\n";
	
	// test con n=2000
	
	unsigned int n3 = 2000;
	const int max_it3 = 5000;
	const double r_tol3 = 1.0e-5;
	Eigen::MatrixXd B3 = Eigen::MatrixXd::Random(n3, n3);
	
	Eigen::MatrixXd A3 = B3.transpose() * B3;
	Eigen::VectorXd x3_ex = Eigen::VectorXd::Ones(n3);
	Eigen::VectorXd b3 = A3*x3_ex;
	
	ris_gradiente_coniugato sol3;
	sol3.gc(A3, b3, r_tol3, max_it3);
	
	std::cout << "\nTEST GRADIENTE CONIUGATO con n=2000 \n";
	
	if (sol3.convergenza == true)
	{
		std::cout << " - Converge \n";
	}
	else
	{
		std::cout << " - Non converge \n";
	}
	
	std::cout << std::scientific << " - Numero di iterazioni: " <<  sol3.iterazioni << " su " << max_it3 << "\n";
	std::cout << std::scientific << " - Residuo: " <<  sol3.residuo  << " su " << r_tol3 << "\n";
	
	double err_rel3 = (sol3.x - x3_ex).norm() / x3_ex.norm();
	std::cout << std::scientific << " - Errore relativo: " <<  err_rel3 << "\n";
	//std::cout << " - Vettore soluzione esatta: \n" << x3_ex.transpose() << "\n";
	//std::cout << " - Vettore soluzione calcolata: \n" << sol3.x.transpose() << "\n";
	
	return 0;
}

	