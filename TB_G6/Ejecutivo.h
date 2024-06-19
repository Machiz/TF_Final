#include <iostream>
#include <string>

using namespace std;

// Definici�n de la clase Ejecutivo
class Ejecutivo {
private:
    string nombre;
    string docentes[10]; // Arreglo est�tico para almacenar docentes
    string cursos[10]; // Arreglo est�tico para almacenar cursos asignados a los docentes
    int numDocentes; // Contador para el n�mero actual de docentes
    string coordinador; // Nombre del coordinador de curso

public:
    // Constructor
    Ejecutivo(string nombreUsuario) {
        nombre = nombreUsuario;
        numDocentes = 0; // Inicializar el contador de docentes
        coordinador = ""; // Inicializar el coordinador como cadena vac�a
    }

    // M�todo para agregar un docente
    void agregarDocente(string nombreDocente) {
        if (numDocentes < 10) { // Verificar si hay espacio en el arreglo
            docentes[numDocentes] = nombreDocente;
            cursos[numDocentes] = ""; // Inicializar el curso del docente como cadena vac�a
            numDocentes++;
        }
        else {
            cout << "No se pueden agregar m�s docentes. L�mite alcanzado." << endl;
        }
    }

    // M�todo para asignar un coordinador
    void asignarCoordinador(string nombreDocente) {
        bool encontrado = false;
        for (int i = 0; i < numDocentes; ++i) {
            if (docentes[i] == nombreDocente) {
                coordinador = nombreDocente;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Docente no encontrado. No se puede asignar como coordinador." << endl;
        }
    }

    // M�todo para asignar un curso a un docente
    void asignarCurso(string nombreDocente, string curso) {
        bool encontrado = false;
        for (int i = 0; i < numDocentes; ++i) {
            if (docentes[i] == nombreDocente) {
                cursos[i] = curso;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Docente no encontrado. No se puede asignar el curso." << endl;
        }
    }

    // M�todo para mostrar la plana de docentes
    void mostrarPlana() {
        cout << "Plana de docentes:" << endl;
        for (int i = 0; i < numDocentes; ++i) {
            cout << i + 1 << ". " << docentes[i];
            if (docentes[i] == coordinador) {
                cout << " (Coordinador)";
            }
            if (!cursos[i].empty()) {
                cout << " - Curso: " << cursos[i];
            }
            cout << endl;
        }
    }
};
