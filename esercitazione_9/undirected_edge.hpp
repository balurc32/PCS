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
	double peso_; // aggiunto per Dijkstra
	
	public:
	undirected_edge() : from_(T{}), to_(T{}), peso_(0.0) // costruttore di default
	{}
	
	undirected_edge(const T& nodoA, const T& nodoB, double w = 1.0)       // costruttore user-defined
	: from_(std::min(nodoA,nodoB)), to_(std::max(nodoA, nodoB)), peso_(w)
	{}
	
	double peso() const {return peso_;} // aggiunto per Dijkstra
	T from() const { return from_; }
	T to() const { return to_; }
	
	double get_peso() const
	{
		return peso_;
	}
	
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


	

