#include <iostream>
#include <fstream>
#include <numeric>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <list>
#include <concepts>
#include "undirected_edge.hpp"
#pragma once

template<typename T>
class undirected_graph
{
	private:
	std::map <int, undirected_edge<T>> i_arco; // mappa che associa ogni arco ad una chiave di tipo T
	std::map <undirected_edge<T>, int> arco_i;
	std::map <T, std::set<undirected_edge<T>>> lista_adiacenza; // ad ogni nodo associati un set di archi adiacenti	
	int id=0; // contatore indici
	

	
	public:
	// costruttore di default: utilizzo Gemini per capire differenze e codice dei costruttori
	undirected_graph() = default;
	
	// costruttore di copia
	undirected_graph(const undirected_graph& other) = default; // 
	
	// costruttore user-defined
	// undirected_graph()
	
	// add_edge
	void add_edge(const T& u, const T& v, double w = 1.0) {
		undirected_edge<T> a(u, v, w);
		
		if (lista_adiacenza.count(u)>0 && lista_adiacenza[u].find(a) != lista_adiacenza[u].end()) // se l'arco non è presente nel set => lo aggiungo
		{
			return;
			}
		else 
		{
			lista_adiacenza[u].insert(a);
			lista_adiacenza[v].insert(a);
			
			i_arco[id] = a;
			arco_i[a] = id;
			id++;
		}
		}
	
	// neighbours -> trova nodi vicini
	std::set<T> neighbours(const T& nodo) const
	{
		std::set<T> vicini;
		
		if (lista_adiacenza.count(nodo)>0)
		{
			for (const auto& archi: lista_adiacenza.at(nodo)) 
			{
				if (archi.get_from() == nodo)
				{
					vicini.insert(archi.get_to()); // per capire come prendere solo il nodo presente nell'arco che non fosse il nodo scelto ho chiesto a Gemini che mi ha suggerito di implementare i metodi get_from e get_to nel undirected_edge
				}
				else 
				{
					vicini.insert(archi.get_from());
				}
			}
		}
		return vicini;
	}
	
	// all_edges -> tutti gli archi
	std::set<undirected_edge<T>> all_edges() const 
	{
		std::set<undirected_edge<T>> ris;
		
		for (const auto& pair : i_arco)
		{
			ris.insert(pair.second); // funzionamento scorrimento mappa, pair e (first/second) chiesto a Gemini
		}
		return ris;
	}
	
	// all_nodes -> tutti i nodi
	std::set<T> all_nodes() const
	{
		std::set<T> ris;
		
		for (const auto& pair: lista_adiacenza)
		{
			ris.insert(pair.first);
		}
		return ris;
	}
	
	// edge_number -> numero dell'arco
	int edge_number(const undirected_edge<T>& a) const
	{
		if (arco_i.count(a)>0)
		{
			return arco_i.at(a);
		}
		else
		{
			return -1;
		}
	}
	
	// edge_at -> dato il numero dell'arco restituisce l'arco
	undirected_edge<T> edge_at(int n) const 
	{
		if (i_arco.count(n)>0)
		{
			return i_arco.at(n);
		}
		else
		{
			std::cerr << "Errore: indice non trovato" << "\n";
			return undirected_edge<T>();
		}
	}
	
	// operator- -> differenza tra gli archi di due grafi
	undirected_graph<T> operator-(const undirected_graph<T>& other) const 
	{
		undirected_graph<T> ris;
		
		auto archi_G = this-> all_edges();
		
		for (const auto& arco : archi_G)
		{
			if (other.edge_number(arco) == -1) // arco non presente in G' prima avevo messo return -1 se non c'era
			{
				ris.add_edge(arco.get_from(), arco.get_to());
			}
		}
		return ris;
	}
	
	// get_peso -> utilizzato Gemini, utilizzato per l'algoritmo dijkstra
	// devo chiedere al grafo: "Esiste un collegamento tra U e V? E se sì, quanto pesa?"
	
	double get_peso(const T& u, const T& v) const 
	{
		undirected_edge<T> a(u,v);
		
		if (lista_adiacenza.count(u)>0)
		{
			auto i_a = lista_adiacenza.at(u).find(a);
			
			if (i_a != lista_adiacenza.at(u).end())
			{
				return i_a -> get_peso(); // i_a iteratore
			}
		}
		return std::numeric_limits<double>::infinity();
	}
	
	// copiato ed incollato da gemini per fare i grafici
	void to_dot(std::ostream& os) const
	{
		os << "graph G {" << std::endl;
		for (const auto& arco : all_edges()) 
		{
			os << "  \"" << arco.get_from() << "\" -- \"" << arco.get_to() << "\";" << std::endl;
		}
		os << "}" << std::endl;
		}
};
