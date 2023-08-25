#include <iostream>
#include <fstream>
#include <string>

#include "Cache.h"
#include "LRU.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::stoi;
using std::string;

const bool debugMode = false;
const int addressSizeBytes = 4;

int main(int argc, char const *argv[])
{
	if (argc != 7)
	{
		printf("Numero de argumentos incorreto. Utilize:\n");
		printf("cache_simulator <nsets> <bsize:bytes> <assoc> <substituição> <flag_saida:0 | 1> arquivo_de_entrada\n");
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
		cout << "arquivo: " << arquivo << endl << endl;
	}

	// Creating cache
	Cache cache(nsets, bsize, assoc, subst, flag_saida);

	// Reading file
	ifstream input(arquivo, std::ios::binary);

	if (!input.is_open())
	{
		printf("Erro ao abrir arquivo de entrada.\n");
		exit(EXIT_FAILURE);
	}

	char buffer[addressSizeBytes];
	int address;
	while (input.read(buffer, addressSizeBytes))
	{
		address = 0;
		for (int i = 0; i < addressSizeBytes; ++i)
			address |= (buffer[i] & 0xFF) << (8 * (addressSizeBytes - 1 - i));

		if (debugMode)
			cout << "Endereco: " << address << endl;

		cache.accessAddress(address);
	}

	cache.printCacheInfo();

	input.close();

	return 0;
}