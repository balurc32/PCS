#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char *argv[]) {
	if (argc!=2) {
		cerr << "Errore: specificare il nome del file." << endl;
		return 1;
		}
//leggo il file

	string filename= argv[1];
	ifstream ifs(filename);
	
	if (!ifs.is_open()) {
		cerr << "Errore: impossibile aprire il file " << endl;
		return 1;
		}
		
	string città;
	double t1,t2,t3,t4;
	
	while (ifs >> città >> t1 >> t2 >> t3 >> t4) {
		double media = (t1+t2+t3+t4)/4;
		
		cout << "Media temperatura nella città di " << città << "=" << media << endl;
	}
		
	return 0;
	
	}
	
	