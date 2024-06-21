#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
//#include <algorithm> // Para std::max
//#include <ctime> // Para srand y rand

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
    int notaDesarrolloPersonal;
    int notaCienciasSociales;
    int notaFisica;
    int notaHistoria;
    int notaHistoriaDelArte;
    int notaQuimica;
    int notaMatematica;
    int notaEducacionFisica;

    Alumno(string nombre, int edad, string genero, int grado, string seccion,
        int notaDesarrolloPersonal = 0, int notaCienciasSociales = 0, int notaFisica = 0, int notaHistoria = 0,
        int notaHistoriaDelArte = 0, int notaQuimica = 0, int notaMatematica = 0, int notaEducacionFisica = 0)
        : nombre(nombre), edad(edad), genero(genero), grado(grado), seccion(seccion),
        notaDesarrolloPersonal(notaDesarrolloPersonal), notaCienciasSociales(notaCienciasSociales),
        notaFisica(notaFisica), notaHistoria(notaHistoria), notaHistoriaDelArte(notaHistoriaDelArte),
        notaQuimica(notaQuimica), notaMatematica(notaMatematica), notaEducacionFisica(notaEducacionFisica) {}

    int getEdad() const override {
        return edad;
    }

    void mostrarDatos() const override {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", Género: " << genero
            << ", Grado: " << grado << ", Sección: " << seccion << endl;
    }
};

template <typename A>
class nodo4 {
public:
    A dato;
    nodo4* siguiente;

    nodo4(const A& dato, nodo4* siguiente = nullptr) : dato(dato), siguiente(siguiente) {}
};

template <typename A>
class ListaEnlazada {
private:
    nodo4<A>* cabeza;

    nodo4<A>* getUltimoNodo(nodo4<A>* inicio) {
        while (inicio != nullptr && inicio->siguiente != nullptr) {
            inicio = inicio->siguiente;
        }
        return inicio;
    }

    nodo4<A>* particion(nodo4<A>* inicio, nodo4<A>* fin, nodo4<A>** nuevoInicio, nodo4<A>** nuevoFin) {
        nodo4<A>* pivote = fin;
        nodo4<A>* anterior = nullptr;
        nodo4<A>* actual = inicio;
        nodo4<A>* cola = pivote;

        while (actual != pivote) {
            if (actual->dato.getEdad() < pivote->dato.getEdad()) {
                if ((*nuevoInicio) == nullptr) {
                    (*nuevoInicio) = actual;
                }
                anterior = actual;
                actual = actual->siguiente;
            }
            else {
                if (anterior) {
                    anterior->siguiente = actual->siguiente;
                }
                nodo4<A>* tmp = actual->siguiente;
                actual->siguiente = nullptr;
                cola->siguiente = actual;
                cola = actual;
                actual = tmp;
            }
        }

        if ((*nuevoInicio) == nullptr) {
            (*nuevoInicio) = pivote;
        }

        (*nuevoFin) = cola;

        return pivote;
    }

    nodo4<A>* quickSortRecursivo(nodo4<A>* inicio, nodo4<A>* fin) {
        if (!inicio || inicio == fin) {
            return inicio;
        }

        nodo4<A>* nuevoInicio = nullptr;
        nodo4<A>* nuevoFin = nullptr;

        nodo4<A>* pivote = particion(inicio, fin, &nuevoInicio, &nuevoFin);

        if (nuevoInicio != pivote) {
            nodo4<A>* tmp = nuevoInicio;
            while (tmp->siguiente != pivote) {
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

    void insertarAlumno(const A& elemento) {
        nodo4<A>* nuevoNodo = new nodo4<A>(elemento);
        if (!cabeza) {
            cabeza = nuevoNodo;
        }
        else {
            nodo4<A>* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    void mostrarDatos() const {
        nodo4<A>* actual = cabeza;
        while (actual != nullptr) {
            actual->dato.mostrarDatos();
            actual = actual->siguiente;
        }
    }

    void generarDatos(const vector<string>& nombres) {
        ofstream archivo("alumnos.csv", ios::app);
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para escribir." << endl;
            return;
        }

        for (const string& nombre : nombres) {
            string sexo = (rand() % 2 == 0) ? "M" : "F";
            int edad = rand() % 11 + 7;
            int anoEscolar = rand() % 12 + 1;
            string seccion = (rand() % 2 == 0) ? "A" : "B";

            // Pidiendo notas al usuario
           

            Alumno nuevoAlumno(nombre, edad, sexo, anoEscolar, seccion);
            insertarAlumno(nuevoAlumno);

            archivo << nombre << "," << edad << "," << sexo << "," << anoEscolar << "," << seccion << endl;
        }
        archivo.close();
    }

    void ordenarPorEdad() {
        cabeza = quickSortRecursivo(cabeza, getUltimoNodo(cabeza));
    }

    bool buscarAlumno(const string& nombreAlumno, Alumno& alumnoEncontrado) const {
        nodo4<A>* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato.nombre == nombreAlumno) {
                alumnoEncontrado = actual->dato;
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    void OrdenMerito(const string& nombreAlumno) {
        Alumno alumnoEncontrado("", 0, "", 0, "", 0, 0, 0, 0, 0, 0, 0, 0);
        if (buscarAlumno(nombreAlumno, alumnoEncontrado)) {
            ofstream archivo("datos_alumno.csv", ios::app);
            if (!archivo.is_open()) {
                cerr << "Error: No se pudo abrir el archivo para escribir." << endl;
                return;
            }
            if (archivo.tellp() == 0) {
                archivo << "Nombre,Orden de Mérito,Sexo,Edad,Año Escolar,Sección" << endl;
            }

            int ordenMerito = rand() % 40 + 1;
            archivo << nombreAlumno << "," << ordenMerito << "," << alumnoEncontrado.genero << "," << alumnoEncontrado.edad << "," << alumnoEncontrado.grado << "," << alumnoEncontrado.seccion << endl;
            archivo.close();

            cout << "Alumno: " << nombreAlumno << endl;
            cout << "Orden de Mérito: " << ordenMerito << endl;
            cout << "Sexo: " << alumnoEncontrado.genero << endl;
            cout << "Edad: " << alumnoEncontrado.edad << endl;
            cout << "Año Escolar: " << alumnoEncontrado.grado << endl;
            cout << "Sección: " << alumnoEncontrado.seccion << endl;
        }
        else {
            cout << "Alumno no encontrado." << endl;
        }
    }

    void mostrarNotasAlumno(const string& nombreAlumno) {
        Alumno alumnoEncontrado("", 0, "", 0, "", 0, 0, 0, 0, 0, 0, 0, 0);
        if (buscarAlumno(nombreAlumno, alumnoEncontrado)) {
            

        }
        else {
            cout << "Alumno no encontrado." << endl;
        }
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
        cout << "Ingrese las notas para " << nombre << ":\n";
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
        cin >> notaEducacionFisica;

        archivo << nombre << "," << edad << "," << genero << "," << grado << "," << seccion << ","
            << notaDesarrolloPersonal << "," << notaCienciasSociales << "," << notaFisica << ","
            << notaHistoria << "," << notaHistoriaDelArte << "," << notaQuimica << "," << notaMatematica << ","
            << notaEducacionFisica << endl;
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



