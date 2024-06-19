#ifndef __NODO1_H__
#define __NODO1_H__
#include<iostream>
template<class T>
class Nodo1 {
public:
	T dato;
	Nodo1<T>* siguiente;

	Nodo1(T v, Nodo1<T>* sig = NULL) {
		dato = v;
		siguiente = sig;
	}
};

#endif

