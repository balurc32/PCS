#include <iostream>
#include <set>
#include <string>
#include <map>
#include <list>
#include "undirected_edge.hpp"
#include "undirected_graph.hpp"

template<typename T>
void test_grafo()
{
	undirected_graph<T> G1;
	undirected_graph<T> G2;
	int n;
	T u, v;
	
	// creo G1
	std::cout << "Scegli il numero di archi di G1: " << "\n";
	std::cin >> n;
	
	for (int i=0; i<n; i++)
	{
		std::cout << "Arco " << i+1 << "; inserisci due nodi separati: ";
		std::cin >> u >> v;
		G1.add_edge(u, v);
	}
	
	// creo G2
	std::cout << "Scegli il numero di archi di G2: " << "\n";
	std::cin >> n;
	
	for (int i=0; i<n; i++)
	{
		std::cout << "Arco " << i+1 << "; inserisci due nodi separati: ";
		std::cin >> u >> v;
		G2.add_edge(u, v);
	}
	
	// test neighbours G1
	std::cout << "Inseriesci un nodo di G1 per trovare i suoi vicini \n";
	T nodo_G1;
	std::cin >> nodo_G1;
	std::set<T> vicini_G1 = G1.neighbours(nodo_G1);
	
	if (vicini_G1.empty())
	{
		std::cout << "Il nodo non ha vicini o non esiste nel grafo. \n";
	}
	else 
	{
		std::cout << "I vicini di " << nodo_G1 << " sono: ";
		for (const auto& vicino : vicini_G1) 
		{
			std::cout << vicino << " ";
			}
	}
	
	std::cout << "\n";
	
	// test neighbours G2
	std::cout << "Inseriesci un nodo di G2 per trovare i suoi vicini \n";
	T nodo_G2;
	std::cin >> nodo_G2;
	std::set<T> vicini_G2 = G2.neighbours(nodo_G2);
	
	if (vicini_G2.empty())
	{
		std::cout << "Il nodo non ha vicini o non esiste nel grafo. \n";
	}
	else 
	{
		std::cout << "I vicini di " << nodo_G2 << " sono: ";
		for (const auto& vicino : vicini_G2) 
		{
			std::cout << vicino << " ";
			}
	}
	
	std::cout << "\n";
	
	// test differenza
	undirected_graph<T> G = G1 - G2;
	std::cout << "Gli archi di G = G1 - G2 sono: \n" ;
	
	if (G.all_edges().size() == 0)
	{
		std::cout << "G non contiene nessun arco, quindi o G1=G2 oppure G1 e G2 sono grafi vuoti. \n ";
	}
	else
	{
		for (const auto& arco : G.all_edges())
		{
			std::cout << "(" << arco.get_from() << " - " << arco.get_to() << ")" << "\n";
			}
	}
	 
	// test all_edges
	auto archi_G1 = G1.all_edges(); 
	auto archi_G2 = G2.all_edges();
	std::cout << "Gli archi di G1 sono: \n"; 
	
	for (const auto& arco : archi_G1)
	{
		std::cout << "("<< arco.get_from() << " - " << arco.get_to() << ") ";
	}
	std::cout << "\n";
	
	std::cout << "Gli archi di G2 sono: \n";
	
	for (const auto& arco : archi_G2)
	{
		std::cout << "("<< arco.get_from() << " - " << arco.get_to() << ") ";
	}
	std::cout << "\n";
	
	// test all_nodes
	auto nodi_G1 = G1.all_nodes(); 
	auto nodi_G2 = G2.all_nodes();
	std::cout << "I nodi di G1 sono: \n";
	
	for (const auto& nodo : nodi_G1)
	{
		std::cout << nodo << " ";
	}
	std::cout << "\n";
	
	std::cout << "I nodi di G2 sono: \n";
	
	for (const auto& nodo : nodi_G2)
	{
		std::cout << nodo << " ";
	}
	std::cout << "\n";
	
	/* std::set<undirected_edge<T>> archi;
	int n;
	T u, v;
	
	std::cout << "Scegli il numero di archi: " << "\n";
	std::cin >> n;
	
	for (int i=0; i<n; i++)
	{
		std::cout << "Arco " << i+1 << " inserisci due nodi separati: ";
		std::cin >> u >> v;
		archi.insert(undirected_edge<T>(u, v));
	}
	
	std::cout << "\n--- Risultato ---" << "\n";
	std::cout << "Numero di archi nel set: " << archi.size() << "\n";

	std::cout << "Elenco archi ordinati: " << "\n";
	for (const auto& edge: archi)
	{
		std::cout << "(" << edge.from() << " - " << edge.to() << ")" << "\n";
	} */
	
}

int main() {
	int scelta;
	std::cout << "Scegli il numero relativo alla tipologia dei nodi: " << "\n";
	std::cout << "1. int \n";
	std::cout << "2. double \n";
	std::cout << "3. string \n";
	std::cin >> scelta;
	
	if (scelta == 1)
	{
		test_grafo<int>();
	}
	else if (scelta == 2)
	{
		test_grafo<double>();	
	}
	else if (scelta == 3)
	{
		test_grafo<std::string>();
	}
	else 
	{
		std::cout << "Scelta non valida \n";
	}
	return 0;
}