#include <iostream>
#include "Notas.h"
#include "Punto.h"
#include <string>
#include <fstream>
using namespace std;

class Profesor
{
private:
	/*string user;
	string password;*/
	string nombreArchivo;
public:
	Profesor();
	void opciones();
	void ponerNota();
	void verNotas();
	void quitarNotas();
	void mostrarCSV(string nombreArchivo);
	void agregarEnCSV(string nombreArchivo);
};


