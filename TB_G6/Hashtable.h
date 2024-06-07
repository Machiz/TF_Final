#include "HashEntidad.h"
#include <iostream>
using namespace std;
class Hashtable
{
private:
	HashEntidad** tabla;
	int numElementos;
	int TABLE_SIZE;
public:
	Hashtable(int TABLE_SIZE = 30)
	{
		this->TABLE_SIZE = TABLE_SIZE;
		tabla = new HashEntidad * [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			tabla[i] = NULL;
		}
		numElementos = 0;
	}
};

