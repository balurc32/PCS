#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

#include "sorts.hpp"
#include "randfiller.h"
#include "timecounter.h"

// 100 vettori per ogni dimensione

int main()
{
	randfiller rf;
	
	for (int i=1; i<=100; i++)
	{
		std::cout << "dimesione vettore: " << i << "\n";
		const int num_vec =100;
		std::vector<std::vector<int>> A(num_vec);
		for (int j=0; j<num_vec; j++)
		{
			A[j].resize(i);
			rf.fill(A[j],-1000,1000);
		}
		
		auto vec_bubble = A;
		auto vec_insertion = A;
		auto vec_selection = A; 
		auto vec_std = A;
		auto vec_merge = A;
		auto vec_quick = A;
		auto vec_quick_mod = A;
		
		// misura Quick-sort
		{
			timecounter tc;
			tc.tic();
			
			for (int v=0; v<num_vec; v++)
			{
				quick_sort(vec_quick[v], 0, vec_quick[v].size()-1);
			} 
			double secs = tc.toc();
			
			std::cout << "Quick-sort (media): " << secs / num_vec << " seconds\n";
		}
		
		// misura Quick-sort modificato
		{
			timecounter tc;
			tc.tic();
			
			for (int v=0; v<num_vec; v++)
			{
				quick_sort_modificato(vec_quick_mod[v], 0, vec_quick_mod[v].size()-1);
			} 
			double secs = tc.toc();
			
			std::cout << "Quick-sort modificato (media): " << secs / num_vec << " seconds\n";
		}
		
		// misura Merge-sort
		{
			timecounter tc;
			tc.tic();
			
			for (int v=0; v<num_vec; v++)
			{
				merge_sort(vec_merge[v], 0, vec_merge[v].size()-1);
			} 
			double secs = tc.toc();
			
			std::cout << "Merge-sort (media): " << secs / num_vec << " seconds\n";
		}
		
		// misura Bubble-sort
		{
			timecounter tc;
			tc.tic();
			
			for (int v=0; v<num_vec; v++)
			{
				bubble_sort(vec_bubble[v]);
			} 
			double secs = tc.toc();
			
			std::cout << "Bubble-sort (media): " << secs / num_vec << " seconds\n";
		}
		
		// misura Insertion-sort
		{
			timecounter tc;
			tc.tic();
			
			for (int v=0; v<num_vec; v++)
			{
				insertion_sort(vec_insertion[v]);
			} 
			double secs = tc.toc();
			
			std::cout << "Insertion-sort (media): " << secs / num_vec << " seconds\n";
		}
		
		// misura Selection-sort
		{
			timecounter tc;
			tc.tic();
			
			for (int v=0; v<num_vec; v++)
			{
				selection_sort(vec_selection[v]);
			} 
			double secs = tc.toc();
			
			std::cout << "Selection-sort (media): " << secs / num_vec << " seconds\n";
		}
		
		// misura std::sort
		{
			timecounter tc;
			tc.tic();
			
			for (int v=0; v<num_vec; v++)
			{
				std::sort(vec_std[v].begin(), vec_std[v].end());
			}
			double secs = tc.toc();
			
			std::cout << "std::sort (media): " << secs / num_vec << " seconds\n";
		}		
		
		std::cout << " ------------------- \n";
	}
	return 0;
	}
	