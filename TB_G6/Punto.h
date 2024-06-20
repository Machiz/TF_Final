#include<iostream>
#include <string>
#include <sstream> //trabajar con cadenas

using namespace std;

class Punto {
    int x;//edad
public:
    Punto( int x) :x(x) {}//constructor de copias
    string toString()
    {
        ostringstream ss;//como decir int x;(una variable)
        string cursos[] = { "Matematica", "Ingles", "Comunicacion", "Ciencia", "Historia" };
        ss << "Nota: ";
        for (int i = 0; i <= 4; ++i)
        {
            ss <<cursos[i]<<" " << x;
        }
        return(ss.str());
    }
};