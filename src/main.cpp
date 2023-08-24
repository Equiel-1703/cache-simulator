#include <iostream>
#include <string>

#include "Cache.h"

using std::cin;
using std::cout;
using std::endl;
using std::stoi;
using std::string;

const bool debugMode = true;

int main(int argc, char const *argv[])
{
	if (argc != 7)
	{
		printf("Numero de argumentos incorreto. Utilize:\n");
		printf("cache_simulator <nsets> <bsize> <assoc> <substituição> <flag_saida> arquivo_de_entrada\n");
		exit(EXIT_FAILURE);
	}

	// Loading parameters
	int nsets = stoi(argv[1]);
	int bsize = stoi(argv[2]);
	int assoc = stoi(argv[3]);
	char subst = argv[4][0];
	int flag_saida = stoi(argv[5]);
	string arquivo = argv[6];

	// Test printing
	if (debugMode)
	{
		cout << "nsets: " << nsets << endl;
		cout << "bsize: " << bsize << endl;
		cout << "assoc: " << assoc << endl;
		cout << "subst: " << subst << endl;
		cout << "flag_saida: " << flag_saida << endl;
		cout << "arquivo: " << arquivo << endl;
	}

	// Creating cache
	Cache cache(nsets, bsize, assoc, subst, flag_saida);
	cache.printSetsData();
	cache.~Cache();
	
	return 0;
}
