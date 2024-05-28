#ifndef __NODO_H__
#define __NODO_H__
#include<iostream>
template<class T>
class Nodo {
public:
	T dato;
	Nodo<T>* siguiente;

	Nodo(T v, Nodo<T>* sig = NULL) {
		dato = v;
		siguiente = sig;
	}
};

#endif

