#include <iostream>
#include "Usuarios.h"
#include "Ejecutivo.h"
#include"Profesor.h"


using namespace std;

class Menu
{
private:
    int O;
public:
    Menu() {};
    ~Menu() {};
    void horario()
    {
        cout << "Lunes - Viernes" << endl;
        cout << "08:00 - 08:45 : Desarrollo personal, ciudadanía y cívica" << endl;
        cout << "08:45 - 09:30 : Ciencias sociales" << endl;
        cout << "09:30 - 10:15 : Fisica" << endl;
        cout << "10:15 - 10:45 : Recreo" << endl;
        cout << "10:45 - 11:30 : Historia" << endl;
        cout << "11:30 - 12:15 : Historia del arte" << endl;
        cout << "12:15 - 13:00 : Historia" << endl;
        cout << "13:00 - 13:45 : Quimica" << endl;
        cout << "13:45 - 14:30 : Matematica" << endl;
        cout << "14:30 - 15:15 : Educacion fisica" << endl;
        cout << endl;
    }
    void menu()
    {
        cout << "                               ######   ######   #        ######   ######     ##     #######" << endl;
        cout << "                               #        #    #   #        #        #                 #     #" << endl;
        cout << "                               #        #    #   #	  #####    ######     ##     #     #" << endl;
        cout << "                               #        #    #   #	  #        #    #     ##     #     #" << endl;
        cout << "                               ######   ######   ######   ######   ######     ##     #######" << endl;
        cout << "========================================================================================================================" << endl;
        cout << "Procesos: " << endl;
        cout << "\n 1. EJECUTIVO             2. PROFESORES             3. USUARIOS" << endl;
        cout << "\nEliga la opcion que desee realizar: " << endl;




        int opcion = 0;
        // ListaEnlazada<Alumno> alumnos;
        Ejecutivo ejecutivo("NombrePreestablecido");
        Profesor objProfesor;
        //Alumno objAlumno;
       //Padre objPadre;

        cin >> opcion;
        switch (opcion) //big 0(1)
        {
        case 1: {
            int option1;
            cout << "¿Qué deseas hacer?" << endl;
            cout << "1. Agregar Docente          2. Regresar a página principal" << endl;
            cin >> option1;
            switch (option1) {
            case 1: {
                cout << "Agregando docentes..." << endl;
                int numDocentes;
                cout << "Ingrese el número de docentes a agregar: ";
                cin >> numDocentes;
                cin.ignore();

                for (int i = 0; i < numDocentes; ++i) {
                    string nombreDocente;
                    cout << "Ingrese el nombre del docente " << i + 1 << ": ";
                    getline(cin, nombreDocente);
                    ejecutivo.agregarDocente(nombreDocente);
                }

                char verPlana;
                cout << "¿Desea ver la plana? (S/N): ";
                cin >> verPlana;
                char volver;
                if (verPlana == 'S' || verPlana == 's') {
                    ejecutivo.mostrarPlana();
                    cout << endl << "Desea volver al menu? (S/N)";
                    cin >> volver;
                    if (volver == 's' || volver == 'S')
                    {
                        system("cls");
                        menu();
                    }
                    else {
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                ejecutivo.mostrarPlana();
                break;
            }
            case 2:
                cout << "Regresando al menú principal..." << endl;
                menu();
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
            }
            break;
        }
        default:
            cout << "Opción no válida." << endl;
            break;

        case 2: //PROFESORES
        {
            system("cls");
            objProfesor.opciones();
            break;
        }

        case 3: //USUARIOS
        {
            ListaEnlazada<Alumno> listaAlumnos;  // Instancia de ListaEnlazada

            vector<string> nombres;
            string nombre;
            int cantidad;

            cout << "¿Cuántos alumnos desea ingresar?" << endl;
            cin >> cantidad;

            cout << "Ingrese los nombres de los alumnos:" << endl;
            cin.ignore();
            for (int i = 0; i < cantidad; ++i)
            {
                cout << "Nombre del alumno " << (i + 1) << ": ";
                getline(cin, nombre);
                nombres.push_back(nombre);
            }

            listaAlumnos.generarDatos(nombres);  // Generar datos con los nombres ingresados

            int opcion = 0;

            while (true) // Bucle principal para mantener el programa corriendo
            {
                cout << "¿Quién eres?" << endl;
                cout << "1. Alumno      2. Padre      3. Salir" << endl;
                cin >> opcion;

                switch (opcion)
                {
                case 1:
                {
                    int opcion1;
                    cout << "¿Qué deseas ver?" << endl;
                    cout << "1. Orden de mérito actual      2. Imprimir datos      3. Ver horario      4. Regresar" << endl;
                    cin >> opcion1;

                    switch (opcion1)
                    {
                    case 1:
                    {
                        string nombreAlumno;
                        cout << "Ingrese el nombre del alumno: ";
                        cin.ignore();
                        getline(cin, nombreAlumno);
                        listaAlumnos.OrdenMerito(nombreAlumno);

                        char volver;
                        cout << "¿Desea volver al menú principal? (S / N)" << endl;
                        cin >> volver;
                        if (volver == 's' || volver == 'S')
                        {
                            system("cls");
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
                            listaAlumnos.mostrarDatos();

                            char volver;
                            cout << "¿Desea volver al menú principal? (S / N)" << endl;
                            cin >> volver;
                            if (volver == 's' || volver == 'S')
                            {
                                system("cls");
                            }
                            break;

                        }
                        case 2:
                        {
                            listaAlumnos.ordenarPorEdad();
                            cout << "\nLista de alumnos ordenada por edad:" << endl << endl;
                            listaAlumnos.mostrarDatos();

                            char volver;
                            cout << "¿Desea volver al menú principal? (S / N)" << endl;
                            cin >> volver;
                            if (volver == 's' || volver == 'S')
                            {
                                system("cls");
                            }
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
                    case 3:
                    {
                        // Mostrar horario
                        string nombreAlumno;
                        cout << "Ingrese el nombre del alumno para ver su horario: ";
                        cin.ignore();
                        getline(cin, nombreAlumno);
                        horario();  // Llama a la función que muestra el horario    

                        char volver;
                        cout << "¿Desea volver al menú principal? (S / N)" << endl;
                        cin >> volver;
                        if (volver == 's' || volver == 'S')
                        {
                            system("cls");
                        }
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
                {
                    // Implementar la opción para el padre si es necesario
                    break;
                }
                case 3:
                {
                    cout << "Saliendo del programa..." << endl;
                    //return 0;
                }
                default:
                {
                    cout << "Opción no válida." << endl;
                    break;
                }
                };
            }
        }
        }

    };
};


//para probar la funcionalidad de usuarios
//#include "Usuarios.h"



