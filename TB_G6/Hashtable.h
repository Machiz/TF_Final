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
	~Hashtable()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (tabla[i] != nullptr)
			{
				delete tabla[i];
			}
		}
		delete[] tabla;
	}
	int size()
	{
		return TABLE_SIZE;
	}
	int sizeActual()
	{
		return numElementos;
	}
	int buscar(int key)
	{
		int step = 0;
		int i, base;
		i = base = key % TABLE_SIZE;//obtener el indice
		while (1)
		{
			if (tabla[i] == nullptr)
			{
				return -1;
			}
			else if (tabla[i]->getkey() == key)return i;//compara el valor de getkey con el de la tabla
			else step++;
			i = (base + step) % TABLE_SIZE;
		}
	}
	void robinHood(int key, int value)
	{

	}
};

