#include <queue>
#include <stack>
#include <iostream>
#include <numeric>
#include <concepts>
#pragma once

template<typename T>
class lifo
{
	private:
	std::stack<T> s;
		
	public:
	
	lifo()  // costruttore di default
	{}
	
	// inserimento elemento nel contenitore
	void put(auto val) 
	{
		s.push(val);
	}
	
	// rimuovere elemento 
	T get()
	{
		T val = s.top();
		s.pop();
		return val;
	}
	
	// verificare se è vuoto
	bool empty()
	{
		if (s.empty() == true)
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
class fifo
{
	private:
	std::queue<T> q;
	
	public:
	
	fifo() // costruttore di default
	{}
	
	// inserimento elemento nel contenitore
	void put(auto val) 
	{
		q.push(val);
	}
	
	// rimuovere elemento 
	T get()
	{
		T val = q.front();
		q.pop();
		return val;
	}
	
	// verificare se è vuoto
	bool empty()
	{
		if (q.empty() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
	
		