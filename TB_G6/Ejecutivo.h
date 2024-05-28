#include <iostream>
#include <string>
using namespace std;

template<class E>
class Nodo1 {
public:
    E dato;
    Nodo1* siguiente;

    Nodo1(E dato) : dato(dato), siguiente(nullptr) {}
};

template<class H>
class ListaEnlazada1 {
private:
    Nodo1<H>* cabeza;

public:
    ListaEnlazada1() : cabeza(nullptr) {}

    void agregarNodo(H dato) {
        Nodo1<H>* nuevoNodo = new Nodo1<H>(dato);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        }
        else {
            Nodo1<H>* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    void mostrarLista() {
        Nodo1<H>* actual = cabeza;
        cout << "Plana de docentes:" << endl;
        int contador = 1;
        while (actual != nullptr) {
            cout << contador << ". " << actual->dato << endl;
            actual = actual->siguiente;
            contador++;
        }
    }

    void ordenarPorNombre() {
        Nodo1<H>* actual = cabeza;
        Nodo1<H>* siguienteNodo1;
        H temp;

        if (cabeza == nullptr) {
            return;
        }
        else {
            while (actual != nullptr) {
                siguienteNodo1 = actual->siguiente;

                while (siguienteNodo1 != nullptr) {
                    if (actual->dato > siguienteNodo1->dato) {
                        temp = actual->dato;
                        actual->dato = siguienteNodo1->dato;
                        siguienteNodo1->dato = temp;
                    }
                    siguienteNodo1 = siguienteNodo1->siguiente;
                }
                actual = actual->siguiente;
            }
        }
    }
};

class Ejecutivo {
private:
    string nombre;
    ListaEnlazada1<string> listaDocentes;

public:
    Ejecutivo(string nombreUsuario) : nombre(nombreUsuario) {}

    void agregarDocente(string nombreDocente) {
        listaDocentes.agregarNodo(nombreDocente);
    }

    void mostrarPlana() {
        listaDocentes.mostrarLista();
    }

    void ordenarPlanaPorNombre() {
        listaDocentes.ordenarPorNombre();
    }
};