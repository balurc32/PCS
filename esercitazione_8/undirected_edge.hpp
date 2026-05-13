#include <iostream>
#include <numeric>
#include <concepts>
#pragma once

template<typename T>
class undirected_edge
{
	private:
	T from_;
	T to_;
	
	public:
	undirected_edge() : from_(T{}), to_(T{}) // costruttore di default
	{}
	
	undirected_edge(const T& nodoA, const T& nodoB)       // costruttore user-defined
	: from_(std::min(nodoA,nodoB)), to_(std::max(nodoA, nodoB))
	{}
	
	T from() const { return from_; }
	T to() const { return to_; }
	
	T get_from() const 
	{
		return from_;
	}
	
	T get_to() const
	{
		return to_;
	}
	
	// Operatore<
	bool operator<(const undirected_edge<T>& other) const // operatore di confronto, arco A < arco B? se sì => True
	{
		if (from_ != other.from_)
		{
		    return from_ < other.from_;
		}
		else
		{
			return to_ < other.to_;
		}
	}
	
	// Operatore==
	bool operator==(const undirected_edge<T>& other) const
	{
		if (from_ == other.from_ && to_ == other.to_)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const undirected_edge<T>& nodo)
{
	os << "(" << nodo.from() << " - " << nodo.to() << ")" << "\n";
	return os;
}


	

