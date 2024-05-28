#include <iostream>
#include<functional>
using namespace std;

typedef unsigned int uint;

template<typename T, T NADA=0>
class ListaNotas
{
private:
    struct Nodo;//direccion de memoria, elementoy direccion de memoria
    typedef function<int(T, T)> Comp;
    Nodo* ini;
    uint lon;//numero de elemetnos de la lista
    Comp comparar;//lambda de criterio de comparacion
public:
    ListaNotas() : ini(nullptr), lon(0), comparar([](T a, T b) {return a - b; }) {};  //inicializacion de miembros
    ListaNotas(Comp comparar) :ini(nullptr), lon(0), comparar(comparar) {}
    ~ListaNotas();
    uint longitud(); //funcion para mostrar longitud lista
    bool esVacia(); //funcion si esta vacia
    void agregaInicial(T elem); //agregar nodo al inicio
    void agregaPos(T elem, uint pos);//agregar en cualquier posicion
    void agregaFinal(T elem); //agregar al final
    void modificarInicial(T elem); //modificar el primer elemento
    void modificarPos(T elem, uint pos); //modificar un elemento por otro
    void modificarFinal(T elem); //modificar el ultimo elemento
    void eliminaInicial(); //eliminar primero
    T obtenerInicial();
    T obtenerPos(uint  pos);
    T obtenerFinal();
    T buscar(T elem);
};

template<typename T, T NADA>
struct ListaNotas<T, NADA>::Nodo {
    T elem;
    Nodo* sig;//puntero apunta al siguiente nodo
    Nodo(T elem = NADA, Nodo* sig = nullptr) :elem(elem), sig(sig) {}//lista de inicializacion de nodos
};

template<typename T, T NADA>
ListaNotas<T, NADA>::~ListaNotas() {
    Nodo* aux = ini;//copia la informacion del nodo ini
    while (aux != nullptr) {
        aux = ini;
        ini = ini->sig;
        delete  aux;
    }
}

template<typename T, T NADA>
uint ListaNotas<T, NADA>::longitud() {
    return lon;
}
template<typename T, T NADA>
bool ListaNotas<T, NADA> ::esVacia() {
    return lon == 0;//operador de comparacion retorna 1 o 0
}
template <typename T, T NADA>
void ListaNotas<T, NADA> ::agregaInicial(T elem) {
    Nodo* nuevo = new Nodo(elem, ini);//constructor, envio elemento y direccion de memoria
    if (nuevo != nullptr)
    {
        ini = nuevo;
        lon++;
    }
}
template<typename T, T  NADA>
void ListaNotas<T, NADA> ::agregaPos(T elem, uint pos)
{
    if (pos > lon)return;
    if (pos == 0)agregaInicial(elem);
    else {
        Nodo* aux = ini;
        for (int i = 1; i < pos; i++)
        {
            aux = aux->sig;
            Nodo* nuevo = new Nodo(elem, aux->sig);
            if (nuevo != nullptr)
            {
                aux->sig = nuevo;
                lon++;
            }

        }

    }
}

template<typename T, T NADA>
void ListaNotas<T, NADA>::agregaFinal(T elem) {
    agregaPos(elem, lon);
}
template<typename T, T NADA>
void ListaNotas<T, NADA> ::modificarInicial(T elem)
{
    if (lon > 0)
    {
        ini->elem = elem;
    }

}
template<typename T, T NADA>
void  ListaNotas<T, NADA> ::modificarPos(T  elem, uint pos)
{
    if (pos >= 0 && pos < lon)
    {
        Nodo* aux = ini;
        for (int i = 0; i <= pos - 1; i++)
        {
            aux = aux->sig;
        }
        aux->elem = elem;
    }
}

template<typename T, T NADA>
void ListaNotas<T, NADA> ::modificarFinal(T elem)
{
    modificarPos(elem, lon - 1);
}

template<typename T, T NADA>
void ListaNotas<T, NADA> ::eliminaInicial()
{
    if (lon > 0)
    {
        Nodo* aux = ini;
        ini = ini->sig;
        delete aux;
        lon--;
    }
}
template<typename T, T NADA>
T ListaNotas<T, NADA>::obtenerInicial()
{
    return ini->elem;//return obtenerPos(0);
}
template<typename T, T NADA>
T ListaNotas<T, NADA>::obtenerPos(uint pos)
{
    if (pos >= 0 && pos < lon)
    {
        Nodo* aux = ini;
        for (int i = 0; i < pos; i++)aux = aux->sig;
        return aux->elem;
    }
    else return NADA;
}
template<typename T, T NADA>
T ListaNotas<T, NADA>::obtenerFinal()
{
    return obtenerPos(lon - 1);
}

template<typename T, T NADA>
T ListaNotas<T , NADA> ::buscar(T elem)
{
    Nodo* aux = ini;
    while (aux != nullptr)
    {
        if (comparar(aux->elem, elem) == 0)
        {
            return aux->elem;
        }
        aux = aux->sig;
    }
    return NADA;
}

