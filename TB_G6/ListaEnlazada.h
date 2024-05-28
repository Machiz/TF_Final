#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <functional>
#include <iostream>
#include "Nodo4.h"
using namespace std;
typedef unsigned int uint;

template <class L> 
class ListaEnlazada {
private:
    Nodo4<L>* primero;
    size_t longitud;

public:
    ListaEnlazada() : primero(nullptr), longitud(0) {}

    ~ListaEnlazada() {
        Nodo4<L>* actual = primero;
        while (actual != nullptr) {
            Nodo4<L>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    void insertar(const L& dato) {
        Nodo4<L>* nuevo = new Nodo4<L>(dato, primero);
        primero = nuevo;
        longitud++;
    }

    Nodo4<L>* obtenerPrimero() const {
        return primero;
    }

    size_t size() const {
        return longitud;
    }

    // Algoritmo de ordenamiento con lambda
    void ordenar(const function<bool(const L&, const L&)>& comparador) {
        if (longitud < 2) {
            return; // No es necesario ordenar si hay menos de dos elementos
        }

        bool cambiado;
        do {
            cambiado = false;
            Nodo4<L>* anterior = nullptr;
            Nodo4<L>* actual = primero;

            while (actual && actual->siguiente) {
                Nodo4<L>* siguiente = actual->siguiente;

                if (comparador(actual->dato, siguiente->dato)) { // Comparación con lambda
                    // Intercambio de nodos
                    if (anterior == nullptr) {
                        primero = siguiente;
                    }
                    else {
                        anterior->siguiente = siguiente;
                    }

                    actual->siguiente = siguiente->siguiente;
                    siguiente->siguiente = actual;

                    cambiado = true; // Se hizo un cambio
                }

                anterior = actual; // Actualizar el anterior
                actual = siguiente; // Avanzar al siguiente nodo
            }
        } while (cambiado);
    }
};
#endif // LISTAENLAZADA_H