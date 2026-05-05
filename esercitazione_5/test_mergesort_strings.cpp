#include <iostream>
#include <vector>
#include <string>
#include "sorts.hpp"

int main()
{
	
	std::vector<std::string> parole={"opprimenti è","Ciccutin","il suo studente preferito","voi i miei saluti","luca barla","numerosi tentativi fallimentari ed","Buongiorno", "nonostante i","riuscito nel suo intento, vanno a","finalmente"};
	/*
	std::cout << "Inserisci una decina di parole a caso, separate da spazio o invio" << "\n";
	
	for (int i=0; i<num_parole; i++)
	{
		std::string input;
		std::cin >> input;
		parole.push_back(input);
	}
	*/
	std::cout << "Sto ordinando con merge-sort..." << "\n";
	merge_sort(parole, 0, parole.size()-1);
	
	if (is_sorted(parole))
	{
		std::cout <<"Bravissimo, il tuo elenco è in ordine alfabetico" << "\n";
		for (const auto& s : parole)
		{
			std::cout << "- " << s << "\n";
		}
		return EXIT_SUCCESS;
	}
	else {
		std::cerr << "Peccato hai sbagliato ma non demoralizzarti, Michael Jordan in carriera ha sbagliato più di 9.000 tiri. Ha perso quasi 300 partite. Per 26 volte gli è stato affidato il tiro decisivo e l'ha sbagliato. Ha fallito più e più volte nella sua vita. Ed è per questo che alla fine ha vinto tutto." << "\n";
		return EXIT_FAILURE;
	}	
}