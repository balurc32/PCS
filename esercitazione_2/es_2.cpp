#include <iostream>

int main()
{
	double ad[4] = {0.0, 1.1, 2.2, 3.3};
	float af[8]={0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	int ai[3] = {0, 1, 2};
	
	int x = 1;
	float y = 1.1;
	
	(&y)[1] = 0;
	std::cout << x << "\n";
	
	std::cout << &x << "\n";
	std::cout << &y << "\n";
	
	for (int i=0; i<4; ++i) {
		std::cout << "ad["<<i<<"]: " << &ad[i] << "\n";
	}
	
	for (int i=0; i<8; ++i) {
		std::cout << "af["<< i <<"]: " << &af[i] << "\n";
	}	
	
	for (int i=0; i<8; ++i) {
		std::cout << "ai["<< i <<"]: " << &ai[i] << "\n";
	}	
	
	return 0;
}
	


