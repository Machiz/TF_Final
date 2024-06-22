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
            /*Notas<Punto*>* nota;
            nota = new Notas<Punto*>();
            Punto* elem;
            do {
                elem = nota->quitarNota();
                cout << elem->toString() << endl;
            } while (!nota->esVacia());*/

        }
        else {
            cout << "Alumno no encontrado." << endl;
        }
    }


};

