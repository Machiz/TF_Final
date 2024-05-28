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
        ss << "Nota: ";
        ss << x;
        return(ss.str());
    }
};