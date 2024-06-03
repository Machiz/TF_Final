#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Alumno
{
private:
    string nombre;
    string sexo;
    int edad;
    int añoEscolar;
    string seccion;

public:
    Alumno() {}
    Alumno(const string& nombre, int edad, const string& sexo, int añoEscolar, const string& seccion)
        : nombre(nombre), edad(edad), sexo(sexo), añoEscolar(añoEscolar), seccion(seccion) {}

    string getNombre() const { return nombre; }
    string getSexo() const { return sexo; }
    int getEdad() const { return edad; }
    int getAñoEscolar() const { return añoEscolar; }
    string getSeccion() const { return seccion; }

    void mostrar() const
    {
        cout << "Nombre del alumno: " << getNombre() << endl;
        cout << "Sexo: " << getSexo() << endl;
        cout << "Edad: " << getEdad() << endl;
        cout << "Año escolar: " << getAñoEscolar() << endl;
        cout << "Seccion: " << getSeccion() << endl;
    }

    static void OrdenMerito(const string& nombreAlumno)
    {
        ofstream archivo("datos_alumno.csv", ios::app);
        if (!archivo.is_open())
        {
            cerr << "Error: No se pudo abrir el archivo para escribir." << endl;
            return;
        }
        if (archivo.tellp() == 0)
        {
            archivo << "Nombre,Orden de Mérito,Sexo,Edad,Año Escolar,Sección" << endl;
        }

        int ordenMerito = rand() % 40 + 1;
        archivo << nombreAlumno << "," << ordenMerito << endl;
        archivo.close();
        cout << "Alumno: " << nombreAlumno << " - Orden de mérito: " << ordenMerito << endl;
    }

    void mostrarCSV(const string& nombreArchivo)
    {
        ifstream archivo(nombreArchivo);

        if (!archivo.is_open())
        {
            cerr << "Error: No se pudo abrir el archivo para leer." << endl;
            return;
        }
        string linea;
        while (getline(archivo, linea))
        {
            cout << linea << endl;
        }
        archivo.close();
    }
};

template <typename A>
class nodo4
{
public:
    A dato;
    nodo4* siguiente;

    nodo4(const A& dato, nodo4* siguiente = nullptr) : dato(dato), siguiente(siguiente) {}
};

template <typename A>
class ListaEnlazada
{
private:
    nodo4<A>* cabeza;

    nodo4<A>* getUltimoNodo(nodo4<A>* inicio)
    {
        while (inicio != nullptr && inicio->siguiente != nullptr)
        {
            inicio = inicio->siguiente;
        }
        return inicio;
    }

    nodo4<A>* particion(nodo4<A>* inicio, nodo4<A>* fin, nodo4<A>** nuevoInicio, nodo4<A>** nuevoFin)
    {
        nodo4<A>* pivote = fin;
        nodo4<A>* anterior = nullptr;
        nodo4<A>* actual = inicio;
        nodo4<A>* cola = pivote;

        while (actual != pivote)
        {
            if (actual->dato.getEdad() < pivote->dato.getEdad())
            {
                if ((*nuevoInicio) == nullptr)
                {
                    (*nuevoInicio) = actual;
                }
                anterior = actual;
                actual = actual->siguiente;
            }
            else
            {
                if (anterior)
                {
                    anterior->siguiente = actual->siguiente;
                }
                nodo4<A>* tmp = actual->siguiente;
                actual->siguiente = nullptr;
                cola->siguiente = actual;
                cola = actual;
                actual = tmp;
            }
        }

        if ((*nuevoInicio) == nullptr)
        {
            (*nuevoInicio) = pivote;
        }

        (*nuevoFin) = cola;

        return pivote;
    }

    nodo4<A>* quickSortRecursivo(nodo4<A>* inicio, nodo4<A>* fin)
    {
        if (!inicio || inicio == fin)
        {
            return inicio;
        }

        nodo4<A>* nuevoInicio = nullptr;
        nodo4<A>* nuevoFin = nullptr;

        nodo4<A>* pivote = particion(inicio, fin, &nuevoInicio, &nuevoFin);

        if (nuevoInicio != pivote)
        {
            nodo4<A>* tmp = nuevoInicio;
            while (tmp->siguiente != pivote)
            {
                tmp = tmp->siguiente;
            }
            tmp->siguiente = nullptr;

            nuevoInicio = quickSortRecursivo(nuevoInicio, tmp);

            tmp = getUltimoNodo(nuevoInicio);
            tmp->siguiente = pivote;
        }

        pivote->siguiente = quickSortRecursivo(pivote->siguiente, nuevoFin);

        return nuevoInicio;
    }

public:
    ListaEnlazada() : cabeza(nullptr) { srand(time(nullptr)); }

    void insertarAlumno(const A& elemento)
    {
        nodo4<A>* nuevoNodo = new nodo4<A>(elemento);
        if (!cabeza) {
            cabeza = nuevoNodo;
        }
        else {
            nodo4<A>* actual = cabeza;
            while (actual->siguiente != nullptr)
            {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    void mostrar() const
    {
        nodo4<A>* actual = cabeza;
        while (actual != nullptr)
        {
            actual->dato.mostrar();
            actual = actual->siguiente;
        }
    }

    void generarDatos(const vector<string>& nombres)
    {
        ofstream archivo("datos_alumno.csv", ios::trunc);
        if (!archivo.is_open())
        {
            cerr << "Error: No se pudo abrir el archivo para escribir." << endl;
            return;
        }

        archivo << "Nombre,Orden de Mérito,Sexo,Edad,Año Escolar,Sección" << endl;

        for (const string& nombre : nombres)
        {
            string sexo = (rand() % 2 == 0) ? "M" : "F";
            int edad = rand() % 11 + 7;
            int añoEscolar = rand() % 12 + 1;
            string seccion = (rand() % 2 == 0) ? "A" : "B";
            int ordenMerito = rand() % 40 + 1;

            archivo << nombre << "," << ordenMerito << "," << sexo << "," << edad << "," << añoEscolar << "," << seccion << endl;

            Alumno nuevoAlumno(nombre, edad, sexo, añoEscolar, seccion);
            insertarAlumno(nuevoAlumno);
        }

        archivo.close();
    }

    void ordenarPorEdad()
    {
        cabeza = quickSortRecursivo(cabeza, getUltimoNodo(cabeza));
    }

    void OrdenMeritoPorNombre(const string& nombreAlumno)
    {
        Alumno::OrdenMerito(nombreAlumno);
    }
};
#endif // ALUMNO_H
