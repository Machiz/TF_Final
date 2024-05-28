#include "iostream"
using namespace std;

#ifndef NODO4_H
#define NODO4_H

// Nodo genérico para lista enlazada
template <class A>
class Nodo4 
{
public:
    A dato;
    Nodo4* siguiente;

    Nodo4(const A& dato, Nodo4* siguiente = nullptr) : dato(dato), siguiente(siguiente) {}
};
#endif // NODO4_H