#include <iostream>
#include <vector>
#include <optional>

template<typename T>

// il vettore è già ordinato?
bool is_sorted(const std::vector<T>& vec)
{
	if (vec.size() == 0) {
		return true;
	}
	
	for (int i=1; i < vec.size(); i++) 
	{
		if (vec[i-1]>vec[i])
		{
			return false;
		}
	}
	return true;
}

// bubble-sort
template<typename T>
void bubble_sort(std::vector<T>& vec)
{
	if (vec.size() < 2)
	{
		return;
	}
	
	for (int i=0; i<vec.size()-1; i++)
	{
		for (int j=vec.size()-1; j>=i+1; j--)
		{
			if (vec[j] < vec[j-1])
			{
				std::swap(vec[j],vec[j-1]);
			}
		}
	}
}
	
// insertion-sort
template<typename T>
void insertion_sort(std::vector<T>& vec)
{
	if (vec.size() < 2)
	{
		return;
	}
	
	for (int i=1; i<=vec.size()-1; i++)
	{
		T value = vec[i];
		int j= i-1;
		while (j>=0 && vec[j]>value)
		{
			std::swap(vec[j+1],vec[j]);
			j=j-1;
		}
		vec[j+1]=value;
	}
}

// selection-sort
template<typename T>
void selection_sort(std::vector<T>& vec)
{
	if (vec.size() < 2)
	{
		return;
	}
	for (int i=0; i<= vec.size()-2; i++)
	{
		int min_index=i;
		
		for (int j=i+1; j<=vec.size()-1; j++)
		{
			if (vec[j]<vec[min_index])
			{
				min_index=j;
			}
		}
		std::swap(vec[i],vec[min_index]);
	}
}
	


