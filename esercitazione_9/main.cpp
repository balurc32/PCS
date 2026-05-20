#include <iostream>
#include <string>
#include <fstream>
#include "undirected_graph.hpp"
#include "graph_visit.hpp"
#include "classes.hpp"
#include "undirected_edge.hpp"

template<typename T>
void test_grafo()
{
	undirected_graph<T> G;
	int n;
	T u, v;
	double w;
	
	// creo G
	std::cout << "Scegli il numero di archi di G: " << "\n";
	std::cin >> n;
	
	for (int i=0; i<n; i++)
	{
		std::cout << "Arco " << i+1 << ": \n";
		std::cout << "Inserisci due nodi separati: ";
		std::cin >> u >> v;
		std::cout << "Inserisci il peso dell'arco: ";
		std::cin >> w;
		std::cout << "\n";
		
		G.add_edge(u, v,w);
	}
	
	T nodo_sorgente;
	std::cout << "Inserisci il nodo da cui far partire le visite: \n" ;
	std::cin >> nodo_sorgente;

	// test BFS
	std::cout << "TEST BFS da " << nodo_sorgente << "\n" ;
	fifo<T> q;
	auto albero_BFS = graph_visit(G, nodo_sorgente, q);
	
	// Gemini: salvataggio dot bfs 
	std::ofstream file_bfs("albero_bfs.dot");
    albero_BFS.to_dot(file_bfs);
    file_bfs.close();

	for (const auto& arco : albero_BFS.all_edges())
	{
		std::cout << "(" << arco.get_from() << " - " << arco.get_to() << ")\n";
	}
	
	// test DFS
	std::cout << "TEST DFS da " << nodo_sorgente << "\n" ;
	lifo<T> s;
	auto albero_DFS = graph_visit(G, nodo_sorgente, s);
	
	// Gemini: salvataggio dot dfs
	std::ofstream file_dfs("albero_dfs.dot");
    albero_DFS.to_dot(file_dfs);
    file_dfs.close();

	for (const auto& arco : albero_DFS.all_edges())
	{
		std::cout << "(" << arco.get_from() << " - " << arco.get_to() << ")\n";
	}
	
	// test Dijkstra
	std::cout << "TEST DIJKSTRA da " << nodo_sorgente << "\n" ;
	auto albero_dijkstra = dijkstra(G, nodo_sorgente);
	
	// Gemini: salvataggio dot dijkstra
	std::ofstream file_dijkstra("albero_dijkstra.dot");
    albero_dijkstra.to_dot(file_dijkstra);
    file_dijkstra.close();
    
	for (const auto& arco : albero_dijkstra.all_edges())
	{
		std::cout << "(" << arco.get_from() << " - " << arco.get_to() << ")\n";
	}
	
	// test recursive_dfs
	std::cout << "TEST DFS RICORSIVO da " << nodo_sorgente << "\n" ;
	auto albero_rec_dfs = recursive_dfs(G, nodo_sorgente);
	
	// Gemini: aggiunta salvataggio dot recursive_dfs 
	std::ofstream file_rec_dfs("albero_rec_dfs.dot");
    albero_rec_dfs.to_dot(file_rec_dfs);
    file_rec_dfs.close();
    
	for (const auto& arco : albero_rec_dfs.all_edges())
	{
		std::cout << "(" << arco.get_from() << " - " << arco.get_to() << ")\n";
	}
	
	
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