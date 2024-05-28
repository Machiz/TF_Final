template<typename T>
class Nodo2
{
public:
    T dato;
    Nodo2  * siguiente;

    Nodo2(const T& dato, Nodo* siguiente = nullptr) : dato(dato), siguiente(siguiente) {}

};

