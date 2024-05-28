#include "Nodo.h"
#include <iostream>
using namespace std;
template<class T>
class Notas
{
private:	
	
	Nodo<T>* inicio;
	Nodo<T>* fin;
public:
	Notas()
	{
		inicio = NULL;
		fin = NULL;
	}
	void agregarNota(T v);
	T quitarNota();
	bool esVacia();
	//double calcularPromedio();
};
template <class T>
void Notas<T>::agregarNota(T n) {
	Nodo<T>* nodo = new Nodo<T>(n);
	if (esVacia()) {
		inicio = nodo;
		fin = inicio;
	}
	else {

		fin->siguiente = nodo;
		fin = nodo;
	}
	nodo = NULL;
}

template <class T>
T Notas<T>::quitarNota() 
{
	T dato = inicio->dato;

	if (inicio == fin) 
	{
		inicio = NULL;
		fin = NULL;
	}
	else 
	{
		inicio = inicio->siguiente;
	}

	return dato;
}
template<class T>
bool Notas<T>::esVacia() {
	return (inicio == NULL);
}
