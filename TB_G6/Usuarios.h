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
            int añoEscolar = rand() % 12 + 1;
            string seccion = (rand() % 2 == 0) ? "A" : "B";

            // Pidiendo notas al usuario
            int notaDesarrolloPersonal, notaCienciasSociales, notaFisica, notaHistoria, notaHistoriaDelArte, notaQuimica, notaMatematica, notaEducacionFisica;
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

            Alumno nuevoAlumno(nombre, edad, sexo, añoEscolar, seccion, notaDesarrolloPersonal, notaCienciasSociales, notaFisica, notaHistoria, notaHistoriaDelArte, notaQuimica, notaMatematica, notaEducacionFisica);
            insertarAlumno(nuevoAlumno);

            archivo << nombre << "," << edad << "," << sexo << "," << añoEscolar << "," << seccion << ","
                << notaDesarrolloPersonal << "," << notaCienciasSociales << "," << notaFisica << ","
                << notaHistoria << "," << notaHistoriaDelArte << "," << notaQuimica << "," << notaMatematica << ","
                << notaEducacionFisica << endl;
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
            cout << "Notas de " << nombreAlumno << ":\n";
            cout << "Desarrollo personal: " << alumnoEncontrado.notaDesarrolloPersonal << endl;
            cout << "Ciencias sociales: " << alumnoEncontrado.notaCienciasSociales << endl;
            cout << "Física: " << alumnoEncontrado.notaFisica << endl;
            cout << "Historia: " << alumnoEncontrado.notaHistoria << endl;
            cout << "Historia del arte: " << alumnoEncontrado.notaHistoriaDelArte << endl;
            cout << "Química: " << alumnoEncontrado.notaQuimica << endl;
            cout << "Matemática: " << alumnoEncontrado.notaMatematica << endl;
            cout << "Educación física: " << alumnoEncontrado.notaEducacionFisica << endl;
        }
        else {
            cout << "Alumno no encontrado." << endl;
        }
    }

    void mostrarPromedioAlumno(const string& nombreAlumno) {
        Alumno alumnoEncontrado("", 0, "", 0, "", 0, 0, 0, 0, 0, 0, 0, 0);
        if (buscarAlumno(nombreAlumno, alumnoEncontrado)) {
            double promedio = (alumnoEncontrado.notaDesarrolloPersonal + alumnoEncontrado.notaCienciasSociales +
                alumnoEncontrado.notaFisica + alumnoEncontrado.notaHistoria + alumnoEncontrado.notaHistoriaDelArte +
                alumnoEncontrado.notaQuimica + alumnoEncontrado.notaMatematica + alumnoEncontrado.notaEducacionFisica) / 8.0;
            cout << "Promedio de notas de " << nombreAlumno << ": " << promedio << endl;
        }
        else {
            cout << "Alumno no encontrado." << endl;
        }
    }
};

// Clase Nodo para el árbol binario
class Nodo {
public:
    Alumno dato;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(const Alumno& dato) : dato(dato), izquierdo(nullptr), derecho(nullptr) {}
};

// Clase Árbol Binario
class ArbolBinario {
private:
    Nodo* raiz;

    Nodo* insertarNodo(Nodo* nodo, const Alumno& dato) {
        if (nodo == nullptr) {
            return new Nodo(dato);
        }
        if (dato.getEdad() < nodo->dato.getEdad()) {
            nodo->izquierdo = insertarNodo(nodo->izquierdo, dato);
        }
        else {
            nodo->derecho = insertarNodo(nodo->derecho, dato);
        }
        return nodo;
    }

    void enOrden(Nodo* nodo) const {
        if (nodo == nullptr) {
            return;
        }
        enOrden(nodo->izquierdo);
        nodo->dato.mostrarDatos();
        enOrden(nodo->derecho);
    }

    void preOrden(Nodo* nodo) const {
        if (nodo == nullptr) {
            return;
        }
        nodo->dato.mostrarDatos();
        preOrden(nodo->izquierdo);
        preOrden(nodo->derecho);
    }

    void postOrden(Nodo* nodo) const {
        if (nodo == nullptr) {
            return;
        }
        postOrden(nodo->izquierdo);
        postOrden(nodo->derecho);
        nodo->dato.mostrarDatos();
    }

    int altura(Nodo* nodo) const {
        if (nodo == nullptr) {
            return 0;
        }
        return 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));
    }

public:
    ArbolBinario() : raiz(nullptr) {}

    void insertar(const Alumno& dato) {
        raiz = insertarNodo(raiz, dato);
    }

    void enOrden() const {
        enOrden(raiz);
    }

    void preOrden() const {
        preOrden(raiz);
    }

    void postOrden() const {
        postOrden(raiz);
    }

    int altura() const {
        return altura(raiz);
    }
};

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

void horario()
{
    cout << "Horario de clases: " << endl;
    cout << " 08:30 - 09:30 : Desarrollo personal" << endl;
    cout << " 09:30 - 10:15 : Ciencias sociales" << endl;
    cout << " 10:15 - 10:45 : Recreo" << endl;
    cout << " 10:45 - 11:30 : Historia" << endl;
    cout << " 11:30 - 12:15 : Historia del arte" << endl;
    cout << " 12:15 - 13:00 : Química" << endl;
    cout << " 13:00 - 13:45 : Matemática" << endl;
    cout << " 13:45 - 14:30 : Educación física" << endl;
    cout << endl;
}

int main()
{
    ListaEnlazada<Alumno> listaAlumnos;
    Padre padre;
    vector<string> nombres;
    string nombre;
    int cantidad;

    cout << "¿Cuántos alumnos desea ingresar?" << endl;
    cin >> cantidad;

    cout << "Ingrese los nombres de los alumnos:" << endl;
    cin.ignore();
    for (int i = 0; i < cantidad; ++i) {
        cout << "Nombre del alumno " << (i + 1) << ": ";
        getline(cin, nombre);
        nombres.push_back(nombre);
    }

    listaAlumnos.generarDatos(nombres);

    int opcion = 0;

    while (true) {
        cout << "¿Quién eres?" << endl;
        cout << "1. Alumno      2. Padre      3. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int opcion1;
            cout << "¿Qué deseas ver?" << endl;
            cout << "1. Orden de mérito actual      2. Imprimir datos      3. Ver horario      4. Regresar" << endl;
            cin >> opcion1;

            switch (opcion1) {
            case 1: {
                string nombreAlumno;
                cout << "Ingrese el nombre del alumno: ";
                cin.ignore();
                getline(cin, nombreAlumno);
                listaAlumnos.OrdenMerito(nombreAlumno);

                char volver;
                cout << "¿Desea volver al menú principal? (S / N)" << endl;
                cin >> volver;
                if (volver == 's' || volver == 'S') {
                    system("cls");
                }
                break;
            }
            case 2: {
                int subOpcion;
                cout << "1. Imprimir datos sin ordenar      2. Imprimir datos ordenados por edad" << endl;
                cin >> subOpcion;
                switch (subOpcion) {
                case 1: {
                    cout << "Lista de alumnos:" << endl;
                    listaAlumnos.mostrarDatos();

                    char volver;
                    cout << "¿Desea volver al menú principal? (S / N)" << endl;
                    cin >> volver;
                    if (volver == 's' || volver == 'S') {
                        system("cls");
                    }
                    break;
                }
                case 2: {
                    listaAlumnos.ordenarPorEdad();
                    cout << "\nLista de alumnos ordenada por edad:" << endl << endl;
                    listaAlumnos.mostrarDatos();

                    char volver;
                    cout << "¿Desea volver al menú principal? (S / N)" << endl;
                    cin >> volver;
                    if (volver == 's' || volver == 'S') {
                        system("cls");
                    }
                    break;
                }
                default: {
                    cout << "Opcion no válida." << endl;
                    break;
                }
                }
                break;
            }
            case 3: {
                string nombreAlumno;
                cout << "Ingrese el nombre del alumno para ver su horario: ";
                cin.ignore();
                getline(cin, nombreAlumno);
                horario();

                char volver;
                cout << "Desea volver al menu principal? (S / N)" << endl;
                cin >> volver;
                if (volver == 's' || volver == 'S') {
                    system("cls");
                }
                break;
            }
            case 4: {
                break;
            }
            default: {
                cout << "Opcion no valida." << endl;
                break;
            }
            }
            break;
        }
        case 2: {
            int opcion2;
            cout << "Que deseas hacer?" << endl;
            cout << "1. Matricular alumno 2. Ver notas del alumno 3. Ver promedio de notas 4. Regresar" << endl;
            cin >> opcion2;

            switch (opcion2) {
            case 1: {
                padre.matricularAlumno("alumnos.csv");
                break;
            }
            case 2: {
                padre.verNotasAlumno("notas.csv");
                break;
            }
            case 3: {
                padre.verPromedioNotas("notas.csv");
                break;
            }
            case 4: {
                system("cls");
                break;
            }
            }
            break;
        }
        case 3: {
            return 0;
        }
        default: {
            cout << "Opcion no válida." << endl;
            break;
        }
        }
    }
    return 0;
}
