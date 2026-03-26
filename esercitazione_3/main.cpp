#include <iostream>
#include "rational.hpp"

int main()
{
	// semplificazione
	rational<int> r1(3,6); 
	std::cout << "semplifico 3/6: " << r1 << "\n";
	
	// prova operazioni
	rational<int> a(1,2);
	rational<int> b(1,4);
	std::cout << a << "+" << b << " = " << (a + b) << "\n";
	std::cout << a << "-" << b << " = " << (a - b) << "\n";
	std::cout << a << "*" << b << " = " << (a * b) << "\n";
	std::cout << a << "/" << b << " = " << (a / b) << "\n";
	
	// prova inf
	rational<int> inf(5,0);
	std::cout << "infinito è: " << inf << "\n";
	std::cout << "somma con inf: " << (a + inf) << "\n";
	
	// prova NaN
	rational<int> NaN(0, 0);
	std::cout << "Not a Number è: " << NaN << "\n";
	std::cout << "somma con NaN: " << (a + NaN) << "\n";
	
	
	return 0;
}