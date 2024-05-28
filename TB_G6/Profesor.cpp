#include "Profesor.h"
#include <fstream>
#include "Alumno.h"
#include "ListaEnlazada.h"
Profesor::Profesor()
{

}
void Profesor::opciones()
{
	int a;
	cout << "Seleccione que quiere hacer: " << endl;
	cout << "1. Poner nota a un alumno " << "		2. Ver Notas colocadas " << "		3. Salir" << endl;
	cin >> a;
	switch (a)
	{
	case 1:
		system("cls");
		ponerNota();
		break;
	case 2:
		system("cls");
		verNotas();
		break;
	case 3:
		system("cls");

		break;
	default:
		opciones();
		break;
	}
}

void Profesor::ponerNota()
{
    int n;
    Notas<Punto*>* nota;
    nota = new Notas<Punto*>();
    int i = 0;
    int totalNotas = 0;
    string cursos[] = { "Matematica", "Ingles", "Comunicacion", "Ciencia", "Historia" };

    while (i <= 4)//log n
    {
        cout << "inserte la nota del curso " << cursos[i] << ": ";
        cin >> n;
        nota->agregarNota(new Punto(n));
        totalNotas += n; 
        i++;
    }

    double promedio = totalNotas / 5.0; 

    cout << "notas guardadas" << endl;
    cout << "El promedio de las notas es: " << promedio << endl;

    // Guardar el promedio en un archivo CSV.
    ofstream archivo("promedio_notas.csv", ios::app); 
    if (archivo.is_open())
    {
        archivo << promedio << endl; 
        archivo.close(); 
        cout << "Promedio guardado en el archivo promedio_notas.csv" << endl;
    }
    else
    {
        cout << "Error al abrir el archivo para guardar el promedio." << endl;
    }

    int o; // opciones
    cout << "Que desea hacer? " << endl;
    cout << "1. poner nota al siguiente alumno\t2. Regresar al Menu de opciones\t3. Cerrar el programa" << endl;
    cin >> o;
    switch (o)
    {
    case 1:
        ponerNota(); // Recursividad
        break;
    case 2:
        opciones();
        break;
    case 3:
        break;
    }
}

void Profesor::verNotas()
{
	Notas<Punto*>* nota;
	nota = new Notas<Punto*>();
	Punto* elem;
	do {
		elem = nota->quitarNota();
		if (elem != NULL) cout << elem->toString() << endl;
	} while (elem != NULL);
}
