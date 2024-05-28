#ifndef PADRE_H
#define PADRE_H
#include <fstream>
#include <iostream>
#include <string>
#include "Alumno.h" // Asegúrate de que la clase Alumno esté definida correctamente
#include "ListaEnlazada.h" // Asegúrate de que ListaEnlazada esté implementada
using namespace std;

class Padre
{
private:
    string nombre; 
    ListaEnlazada<Alumno> alumnos; 

public:
    Padre() {}
    Padre(const string& nombre) : nombre(nombre) {} 

    // Getters
    string getNombre() const { return nombre; }

    void registrarAlumno() 
    {
        ofstream archivo("alumnos.csv", ios::app);

        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para escribir." << endl;
            return;
        }
        if (archivo.tellp() == 0) 
        {
            archivo << "Nombre,Edad,AñoEscolar,Sección" << endl;
        }
      
        string nombreAlumno;
        int edadAlumno;
        int añoAlumno;
        string seccionAlumno;
        cout << "Registrar Alumno: " << endl;
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore(); 
        getline(cin, nombreAlumno); 

        cout << "Ingrese la edad del alumno: ";
        cin >> edadAlumno;

        cout << "Ingrese el año escolar del alumno: ";
        cin >> añoAlumno; 

        cin.ignore();

        cout << "Ingrese la sección del alumno(A/B): ";
        getline(cin, seccionAlumno); 

        archivo << nombreAlumno << ","
            << edadAlumno << ","
            << añoAlumno << ","
            << seccionAlumno << endl;

        archivo.close(); 

        int opcion;
        cout << "Qué desea hacer ahora?" << endl;
        cout << "1. Imprimir datos guardados\n2. Regresar al menú principal" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Imprimir los datos del archivo CSV
        {
            ifstream archivo("alumnos.csv");

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
        break;

        case 2:
            cout << "Regresando al menú principal..." << endl;
            break;

        default:
            cout << "Opción no válida." << endl;
            break;
        }
    }
};
#endif PADRE_H