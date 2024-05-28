#include "Nodo.h"
//
//using  namespace std;
//
//template<class T>
//class Pila {
//private:
//    Nodo<T>* tope;//ultimo valor de entrada = tope, lo ultimo que ingresa
//public:
//    Pila() { tope = NULL; };
//    void push(T v);//poner un elemento
//    T pop();//borrar/eliminar el ultimo
//    bool estaVacia();//verificar
//};
//
//template <class T>
//void Pila<T>::push(T v)
//{
//    if (estaVacia()) {
//        tope = new Nodo <T>(v);
//    }
//    else
//        tope = new Nodo<T>(v, tope);
//}
//
//template<class T>
//T Pila<T>::pop()
//{
//    if (estaVacia())return NULL;
//    else {
//        T elemento = (T)(tope->dato);
//        tope = (Nodo<T>*)tope->siguiente;
//        return elemento;
//    }
//}
//template<class T>
//bool Pila<T>::estaVacia()
//{
//    return tope = NULL;
//}
//
