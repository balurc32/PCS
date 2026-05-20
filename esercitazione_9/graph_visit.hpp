#include <iostream>
#include <numeric>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <list>
#include <concepts>
#include <queue>
#include <stack>
#include <limits>
#include "undirected_graph.hpp"
#pragma once

template<typename T, typename contenitore>
undirected_graph<T> graph_visit(const undirected_graph<T>& G, const T& nodo_sorgente, contenitore& C)
{
	undirected_graph<T> albero;
	std::set<T> nodi_visitati; 
	
	C.put(nodo_sorgente); // inserisco nodo sorgente
	nodi_visitati.insert(nodo_sorgente);
	
	while (C.empty() == false)
	{
		T nodo = C.get(); // estraiamo un altro nodo
		
		for (const auto& n : G.neighbours(nodo))
		{
			if (nodi_visitati.find(n) == nodi_visitati.end())
			{
				nodi_visitati.insert(n); // inseriamo il nodo nei visitati
				albero.add_edge(nodo, n); // aggiungiamo arco all'albero 
				C.put(n); // mettiamo nel contenitore per visitarlo dopo
			}
		}
	}
	return albero;
}


template<typename T>
void passo_dfs(const undirected_graph<T>& G, const T& n, std::set<T>& nodi_visitati, undirected_graph<T>& albero)
{
	nodi_visitati.insert(n); // inserisco il nodo ai visitati
	
	for (const auto& k : G.neighbours(n))
	{
		if (nodi_visitati.find(k) == nodi_visitati.end()) // se il nodo k non è ancora stato visitato
		{
			albero.add_edge(n, k); // aggiungo l'arco all'albero
			passo_dfs(G, k, nodi_visitati, albero); // rifaccio stesso processo per il nodo k => scendo in profondità
		}
	}
}

template<typename T> 
undirected_graph<T> recursive_dfs(const undirected_graph<T>& G, const T& nodo_sorgente)
{
	undirected_graph<T> albero;
	std::set<T> nodi_visitati;
	
	passo_dfs(G, nodo_sorgente, nodi_visitati, albero);
	return albero;
}

// chiesto a Gemini funzionamento dell'algoritmo Dijkstra

template<typename T>
undirected_graph<T> dijkstra(const undirected_graph<T>& G, const T& s)
{
	std::map<T,T> pred; // array predecessori
	std::map<T,double> dist; // array distanze 
	
	for (const auto& nodo : G.all_nodes())
	{
		pred[nodo] = T{}; // utilizzo Gemini per scrivere pred[i=0] = -1
		dist[nodo] = std::numeric_limits<double>::infinity(); // utilizzo Gemini per scrivere dist[i=0] = +inf
	}
	
	pred[s] = s;
	dist[s] = 0.0;
	
	std::priority_queue<std::pair<double, T>, std::vector<std::pair<double, T>>, std::greater<std::pair<double, T>>> PQ; // chiesto a Gemini come scrivere l'adattatore Priority Queue
	
	for (const auto& nodo : G.all_nodes())
	{
		PQ.push({dist[nodo], nodo});
	}
	
	while (!PQ.empty()) // (u,p) = PQ.Dequeue()
	{
		T u = PQ.top().second; // chiesto a Gemini come prendere gli elementi con maggiore priorità (ovvero distanza minore da PQ), qui prendo il nodo
		double p = PQ.top().first; // prendo il primo elem della coppia {distanza, nodo} del nodo con distanza minore
		PQ.pop();
		
		if (p > dist[u]) continue;
		
		for (const auto& w : G.neighbours(u))
		{
			double peso_uw = G.get_peso(u,w);
			
			if (dist[w] > dist[u] + peso_uw)
			{
				dist[w] = dist[u] + peso_uw;
				pred[w] = u;
				
				PQ.push({dist[w], w}); // chiesto a Gemini cosa fosse DecreaseKey
			}
		}
	}
	
	undirected_graph<T> albero;
	
	for (const auto& nodo : G.all_nodes())
	{
		if (pred[nodo] != T{} && pred[nodo] != nodo && dist[nodo] != std::numeric_limits<double>::infinity()) // se il nodo ha un predecessore valido
		{
			albero.add_edge(pred[nodo], nodo, G.get_peso(pred[nodo], nodo));
		}
	}
	return albero;
}