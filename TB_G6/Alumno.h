#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <string>
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
    void OrdenMerito()
    {
        ofstream archivo("datos_alumno.csv", ios::app);
        if (!archivo.is_open())
        {
            cerr << "Error: No se pudo abrir el archivo para escribir." << endl;
            return;
        }
        if (archivo.tellp() == 0)
        {
            archivo << "Nombre,Orden de Mérito" << endl;
        }
        string nombreAlumno;
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore();
        getline(cin, nombreAlumno);

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

    void mostrarRecursivo(nodo4<A>* nodo) const
    {
        if (nodo)
        {
            nodo->dato.mostrar();
            mostrarRecursivo(nodo->siguiente);
        }
    }

public:
    ListaEnlazada() : cabeza(nullptr) { srand(time(nullptr)); }

    void insertarAlumno(const A& elemento)
    {
        nodo4<A>* nuevoNodo = new nodo4<A>(elemento);
        if (!cabeza)
        {
            cabeza = nuevoNodo;
        }
        else
        {
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
        mostrarRecursivo(cabeza);
    }

    void generarDatos(int cantidad)
    {
        if (cantidad < 20)
        {
            cantidad = 20;
        }
        else if (cantidad > 40)
        {
            cantidad = 40;
        }

        for (int i = 0; i < cantidad; i++)
        {
            string nombre = "Alumno" + to_string(i + 1);
            string sexo = (rand() % 2 == 0) ? "M" : "F";
            int edad = rand() % 11 + 7;
            int añoEscolar = rand() % 12 + 1;
            string seccion = (rand() % 2 == 0) ? "A" : "B";

            Alumno nuevoAlumno(nombre, edad, sexo, añoEscolar, seccion);
            insertarAlumno(nuevoAlumno);
        }
    }

    void ordenarPorEdad()
    {
        if (!cabeza) return;

        nodo4<A>* ordenado = nullptr;

        nodo4<A>* actual = cabeza;
        while (actual != nullptr) {
            nodo4<A>* siguiente = actual->siguiente;

            auto comparator = [](const A& a, const A& b) { return a.getEdad() < b.getEdad(); };

            if (ordenado == nullptr || comparator(actual->dato, ordenado->dato)) {
                actual->siguiente = ordenado;
                ordenado = actual;
            }
            else {
                nodo4<A>* temporal = ordenado;
                while (temporal->siguiente != nullptr && comparator(temporal->siguiente->dato, actual->dato)) {
                    temporal = temporal->siguiente;
                }
                actual->siguiente = temporal->siguiente;
                temporal->siguiente = actual;
            }
            actual = siguiente;
        }
        cabeza = ordenado;
    }
};
#endif ALUMNO_H



//MENU
case 3: //USUARIOS
{
    int opcion1;
    cout << "¿Quién eres?" << endl;
    cout << "1. Alumno      2. Padre      3. Regresar a página principal" << endl;
    cin >> opcion1;

    switch (opcion1)
    {
    case 1:
    {
        int opcion2;
        cout << "Que deseas ver?" << endl;
        cout << "1. Orden de merito actual      2. Imprimir datos      3. Regresar" << endl;
        cin >> opcion2;

        switch (opcion2)
        {
        case 1:
        {
            char volver;
            objAlumno.OrdenMerito();
            cout << "Desea volver al Menu Principal? (S / N)" << endl;
            cin >> volver;
            if (volver == 's' || volver == 'S')
            {
                system("cls");
                menu();
            }
            break;
        }
        case 2:
        {
            int subOpcion;
            cout << "1. Imprimir datos sin ordenar      2. Imprimir datos ordenados por edad" << endl;
            cin >> subOpcion;
            switch (subOpcion)
            {
            case 1:
            {
                cout << "Lista de alumnos:" << endl;
                listaAlumnos.mostrar();
                break;
            }
            case 2:
            {
                listaAlumnos.ordenarPorEdad();
                cout << "\nLista de alumnos ordenada por edad:" << endl << endl;
                listaAlumnos.mostrar();
            }
            default:
            {
                cout << "Opción no válida." << endl;
                break;
            }
            }
            char volver;
            cout << "Desea volver al Menu Principal? (S / N)" << endl;
            cin >> volver;
            if (volver == 's' || volver == 'S') {
                system("cls");
                menu();
            }
            break;
        }
        case 3:
        {
            cout << "Regresando al menú principal..." << endl;
            system("cls");
            menu();
            break;
        }
        default: 
        {
            cout << "Opción no válida." << endl;
            break;
        }
        }
        break;
    }
   
    case 2:          
        objPadre.registrarAlumno();              
        break;
    case 3:
        cout << "Regresando al menú principal" << endl;
        system("cls");
        menu();
        break;
    default:
        cout << "Opción no válida." << endl;
        break;
    }
    break;
}
};
