#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

#include "sorts.hpp"
#include "randfiller.h"
#include "timecounter.h"

int main()
{
	randfiller rf;
	
	for (int i=4; i<=8192; i*=2)
	{
		std::cout << "dimesione vettore: " << i << "\n";
		std::vector<int> vec(i);
		rf.fill(vec, -10000,10000);
		
		
		auto vec_bubble = vec;
		auto vec_insertion = vec;
		auto vec_selection = vec; 
		auto vec_std = vec;
		
		/* misura Bubble-sort */
		{
			timecounter tc;
			tc.tic();
			
			bubble_sort(vec_bubble);
			double secs = tc.toc();
			std::cout << "Bubble-sort: " << secs << " seconds\n";
		}
		
		/* misura Insertion-sort */
		{
			timecounter tc;
			tc.tic();
			
			insertion_sort(vec_insertion);
			double secs = tc.toc();
			std::cout << "Insertion-sort: " << secs << " seconds\n";
		}
		
		/* misura Selection-sort */
		{
			timecounter tc;
			tc.tic();
			
			selection_sort(vec_selection);
			double secs = tc.toc();
			std::cout << "Selection-sort: " << secs << " seconds\n";
		}
		
		/* misura sort */
		{
			timecounter tc;
			tc.tic();
			
			std::sort(vec_std.begin(), vec_std.end());
			double secs = tc.toc();
			std::cout << "std::sort " << secs << " seconds\n";
		}
		
		std::cout << " ------------------- \n";
	}
	return 0;
}