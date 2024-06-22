#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "ListaAlumnos.h"
#include "ListaNotas.h"

using namespace std;

// Clase padre con las funciones puras
class Persona {
public:
    virtual void mostrarDatos() const = 0;
    virtual int getEdad() const = 0;
};

class Alumno : public Persona {
public:
    string nombre;
    int edad;
    string genero;
    int grado;
    string seccion;
    /*int notaDesarrolloPersonal;
    int notaCienciasSociales;
    int notaFisica;
    int notaHistoria;
    int notaHistoriaDelArte;
    int notaQuimica;
    int notaMatematica;
    int notaEducacionFisica;*/

    Alumno(string nombre, int edad, string genero, int grado, string seccion)
        : nombre(nombre), edad(edad), genero(genero), grado(grado), seccion(seccion) {}

    int getEdad() const override {
        return edad;
    }

    void mostrarDatos() const override {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", Género: " << genero
            << ", Grado: " << grado << ", Sección: " << seccion << endl;
    }
};



// Clase Nodo para el árbol binario
template<class T>
class Nodo {
public:
    Alumno dato;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(const Alumno& dato) : dato(dato), izquierdo(nullptr), derecho(nullptr) {}
};

// Clase Árbol Binario
//template<class T>
//class ArbolBinario {
//private:
//    Nodo*<T> raiz;
//
//    Nodo*<T> insertarNodo(Nodo<T>* nodo, const Alumno& dato) {
//        if (nodo == nullptr) {
//            return new Nodo<T>(dato);
//        }
//        if (dato.getEdad() < nodo->dato.getEdad()) {
//            nodo->izquierdo = insertarNodo(nodo->izquierdo, dato);
//        }
//        else {
//            nodo->derecho = insertarNodo(nodo->derecho, dato);
//        }
//        return nodo;
//    }
//
//    void enOrden(Nodo* nodo) const {
//        if (nodo == nullptr) {
//            return;
//        }
//        enOrden(nodo->izquierdo);
//        nodo->dato.mostrarDatos();
//        enOrden(nodo->derecho);
//    }
//
//    void preOrden(Nodo* nodo) const {
//        if (nodo == nullptr) {
//            return;
//        }
//        nodo->dato.mostrarDatos();
//        preOrden(nodo->izquierdo);
//        preOrden(nodo->derecho);
//    }
//
//    void postOrden(Nodo* nodo) const {
//        if (nodo == nullptr) {
//            return;
//        }
//        postOrden(nodo->izquierdo);
//        postOrden(nodo->derecho);
//        nodo->dato.mostrarDatos();
//    }
//
//    int altura(Nodo* nodo) const {
//        if (nodo == nullptr) {
//            return 0;
//        }
//        return 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));
//    }
//
//public:
//    ArbolBinario() : raiz(nullptr) {}
//
//    void insertar(const Alumno& dato) {
//        raiz = insertarNodo(raiz, dato);
//    }
//
//    void enOrden() const {
//        enOrden(raiz);
//    }
//
//    void preOrden() const {
//        preOrden(raiz);
//    }
//
//    void postOrden() const {
//        postOrden(raiz);
//    }
//
//    int altura() const {
//        return altura(raiz);
//    }
//};

class Padre {
public:
    void matricularAlumno(const string& archivoAlumnos) {
        ofstream archivo(archivoAlumnos, ios::app);
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para escribir." << endl;
            return;
        }

        string nombre, genero, seccion;
        int edad, grado;
        int notaDesarrolloPersonal, notaCienciasSociales, notaFisica, notaHistoria, notaHistoriaDelArte, notaQuimica, notaMatematica, notaEducacionFisica;

        cout << "Ingrese el nombre del alumno: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese la edad del alumno: ";
        cin >> edad;
        cout << "Ingrese el genero del alumno (M/F): ";
        cin >> genero;
        cout << "Ingrese el grado del alumno: ";
        cin >> grado;
        cout << "Ingrese la seccion del alumno: ";
        cin >> seccion;

        // Pidiendo notas al usuario
        /*cout << "Ingrese las notas para " << nombre << ":\n";
        cout << "  Desarrollo personal: ";
        cin >> notaDesarrolloPersonal;
        cout << "  Ciencias sociales: ";
        cin >> notaCienciasSociales;
        cout << "  Física: ";
        cin >> notaFisica;
        cout << "  Historia: ";
        cin >> notaHistoria;
        cout << "  Historia del arte: ";
        cin >> notaHistoriaDelArte;
        cout << "  Química: ";
        cin >> notaQuimica;
        cout << "  Matemática: ";
        cin >> notaMatematica;
        cout << "  Educación física: ";
        cin >> notaEducacionFisica;*/

        archivo << nombre << "," << edad << "," << genero << "," << grado << "," << seccion << endl;
        archivo.close();
    }

    void verNotasAlumno(const string& archivoNotas) {
        ifstream archivo(archivoNotas);
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para leer." << endl;
            return;
        }

        string nombre, linea;
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore();
        getline(cin, nombre);

        while (getline(archivo, linea)) {
            size_t pos = linea.find(nombre);
            if (pos != string::npos) {
                cout << "Notas de " << nombre << ":\n";
                cout << linea << endl;
                archivo.close();
                return;
            }
        }

        cout << "Alumno no encontrado." << endl;
        archivo.close();
    }

    void verPromedioNotas(const string& archivoNotas) {
        ifstream archivo(archivoNotas);
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para leer." << endl;
            return;
        }

        string nombre, linea;
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore();
        getline(cin, nombre);

        while (getline(archivo, linea)) {
            size_t pos = linea.find(nombre);
            if (pos != string::npos) {
                vector<string> datos;
                size_t inicio = 0, fin = linea.find(",");
                while (fin != string::npos) {
                    datos.push_back(linea.substr(inicio, fin - inicio));
                    inicio = fin + 1;
                    fin = linea.find(",", inicio);
                }
                datos.push_back(linea.substr(inicio, fin - inicio));

                double promedio = 0;
                for (int i = 5; i < datos.size(); ++i) {
                    promedio += stoi(datos[i]);
                }
                promedio /= (datos.size() - 5);

                cout << "Promedio de notas de " << nombre << ": " << promedio << endl;
                archivo.close();
                return;
            }
        }

        cout << "Alumno no encontrado." << endl;
        archivo.close();
    }
};



