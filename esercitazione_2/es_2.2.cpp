#include <iostream>
#include <algorithm>  // per min e max
#include <cmath>    // per sqrt

int main()
{ 
	static const int N=10;
	double arr[N]= {4.7, -2.3, 9.1, 0.5, -7.8, 3.2, -1.6, 8.4, -0.9, 6.0};
	
	double minimo= arr[0]; // inizializzo il minimo
	double massimo = arr[0];  // inizializzo il massimo 
	double somma=0; // inizializzo la somma
	
	for (int i=0; i<N; ++i) {
		minimo = std::min(minimo, arr[i]);
		
		massimo= std::max(massimo, arr[i]);
		
		somma = somma + arr[i];
		}
		
	std::cout << "il minimo è: " << minimo << "\n";
	std::cout << "il massimo è: " << massimo << "\n";
	
	// media
	double media = somma/N;
	
	std::cout << "la media è: " << media << "\n";
	
	// deviazione standard 
	double somma_quadrati= 0;
	
	for (int i=0; i<N; ++i) {
		somma_quadrati = somma_quadrati+pow(arr[i]-media,2);
		}
	
	double varianza = somma_quadrati/N;
	double deviazione_standard = std::sqrt(varianza);
	
	std::cout << "la deviazione standard è: " << deviazione_standard << "\n";
	
	
	return 0;
	
}	