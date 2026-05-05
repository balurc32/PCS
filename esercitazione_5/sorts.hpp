#include <iostream>
#include <vector>
#include <optional>
#include <string>

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
	

// merge
template<typename T>
void merge(std::vector<T>& A, int p, int q, int r)
{
	int n1= q-p+1;
	int n2= r-q;
	std::vector<T> R;
	std::vector<T> L;
	L.resize(n1+1);
	R.resize(n2+2);
	
	for (int i=0; i<=n1-1; i++)
	{
		L[i]=A[p+i];
	}
	
	for (int j=0; j<=n2-1; j++)
	{
		R[j]=A[q+j+1];
	}
	
	if constexpr(std::is_same<T, std::string>::value)    // utilizzato gemini per constexpr
	{
		L[n1]="{{";
		R[n2]="{{";	
	}
	else 
	{
		L[n1]= 10000000;
		R[n2]= 10000000;
		}
	int j=0;
	int i=0;
	
	for (int k=p; k<=r; k++)
	{
		if (L[i]<=R[j])
		{
			A[k]=L[i];
			i= i+1; 
		}
		else 
		{
			A[k]=R[j];
			j=j+1;
		}
	}	
}

// merge-sort
template<typename T>
void merge_sort(std::vector<T>& A, int p, int r)
{
	if (p<r)
	{
		int q=(p+r)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}


// Partition
template<typename T>
int partition(std::vector<T>& A, int p, int r)
{
	T x=A[r];
	int i= p-1;
	
	for (int j=p; j<=r-1; j++)
	{
		if (A[j]<=x)
		{
			i= i+1;
			std::swap(A[i],A[j]);
		}
	}
	std::swap(A[i+1], A[r]);
	return i+1;
}

// insertion-sort parziale 
template<typename T>
void insertion_sort_parziale(std::vector<T>& A, int p, int r)
{
	for (int i=p+1; i<=r; i++)
	{
		T value = A[i];
		int j= i-1;
		while (j>=p && A[j]>value)
		{
			std::swap(A[j+1],A[j]);
			j=j-1;
		}
		A[j+1]=value;
	}
}


// quick-sort modificato
template<typename T>
void quick_sort_modificato(std::vector<T>& A, int p, int r)
{
	if (p<r)
	{
		if ((r-p+1) < 88)
		{
			insertion_sort_parziale(A, p, r);
		}
		else
		{
			int q=partition(A,p,r);
			quick_sort_modificato(A,p,q-1);
			quick_sort_modificato(A,q+1,r);
			}
	}
}

// quick-sort 
template<typename T>
void quick_sort(std::vector<T>& A, int p, int r)
{
	if (p<r)
	{
		int q=partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
}
