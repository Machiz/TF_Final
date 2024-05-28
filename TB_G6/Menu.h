#include <iostream>
#include "Alumno.h"
#include "Ejecutivo.h"
#include"Profesor.h"
#include "Padre.h"

using namespace std;

class Menu
{
private:
    int O; 
public:
    Menu() {};
    ~Menu() {};

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
        Alumno objAlumno;
       Padre objPadre;

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
            int opcion1;
            cout << "¿Quién eres?" << endl;
            cout << "1. Alumno      2. Padre      3. Regresar a página principal" << endl;
            cin >> opcion1;

            switch (opcion1)
            {
            case 1:
            {
                int opcion2;
                cout << "¿Qué deseas ver?" << endl;
                cout << "1. Orden de mérito actual      2. Regresar" << endl;
                cin >> opcion2;

                switch (opcion2)
                {
                case 1:
                {
                    char volver;
                    objAlumno.OrdenMerito();
                    cout << "Desea volver al Menu Principal? (S / N)"<<endl;
                    cin >> volver;
                    if (volver == 's' || volver == 'S')
                    {
                        system("cls");
                        menu();
                    }
                    else {
                        break;
                    }
                    break;                                
                }
                break;
                case 2:
                {
                    cout << "Regresando al menú principal..." << endl;
                    system("cls");
                    menu();
                    break;                                 
                }                                  
                default:
                    cout << "Opción no válida." << endl;
                    break;
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
    };
};