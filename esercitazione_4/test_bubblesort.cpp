#include <iostream>
#include <vector>
#include "sorts.hpp"
#include "randfiller.h"


int main()
{
	bool sorted=true;
	randfiller rf;
	const int n = 10;
	
	std::vector<int> vi;
	vi.resize(n);
	rf.fill(vi,1,1000);
	
	for (int i=0; i<vi.size(); i++)
	{
		int dim= vi[i];
		
		for (int j=0; j<100; j++)
		{
			std::vector<int> vi_test;
			vi_test.resize(dim);
			rf.fill(vi_test, -10000,10000);
			bubble_sort(vi_test);
			
			if (not is_sorted(vi_test))
			{
				sorted= false;
			}
		}
	}
	
	if (sorted==true)
	{
		std::cout << "il bubble-sort funziona, complimenti!! Questa da te proprio non me l'aspettavo" << "\n";
		return EXIT_SUCCESS;
	}
	
	else {
		std::cout << "il bubble-sort non ha funzionato, non arrenderti e riprova" << "\n";
		return EXIT_FAILURE;
	}	
	
}