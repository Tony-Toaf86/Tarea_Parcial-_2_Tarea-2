#include "Persona.hpp"
#include "ArbolGenealogico.hpp"
#include <iostream>
using namespace std;

int main ()
    {
    ArbolGenealogico arbol;
    int opcion;
    string nombre, fecha, madre, padre;
    do
        {
        cout << "\n===== MENU ======\n";
        cout << "1. Ingresar persona\n";
        cout << "2. Mostrar ascendencia\n";
        cout << "3. Motrar descendencia\n";
        cout << "4. Eliminar subarlbol\n";
        cout << "5. SALIR\n";
        cout << "Seleccione una opcion:";
        cin >> opcion;
        cin.ignore();
        
        switch (opcion)
            {
            case 1:
            cout<<"Nombre: ";
            getline(cin, nombre);
            cout<<"Fecha de nacimiento: ";
            getline(cin, fecha);
            cout<<"Nombre del padre: ";
            getline(cin, padre);            
            cout<<"Nombre del madre: ";
            getline(cin, madre);   
            arbol.insertPersona(nombre, fecha, padre, madre);
            break;

             case 2:
             cout<<"Ingrese el nombre para mostrar ascendencia: ";
             getline(cin, nombre);
             arbol.mostrarAscendencia(nombre);
             break;

             case 3:
             cout<<"Ingrese el nombre para mostrar descendencia: ";
             getline(cin, nombre);
             arbol.mostrarDescendencia(nombre);
             break;             
          
             case 4:
             cout<<"Ingrese el nombre a eliminar: ";
             getline(cin, nombre);
             arbol.eliminarSubarbol(nombre);
             break;                      
          
             case 5:
             cout<<"Adios: ";
             break;

             default:
             cout<<"No seleciono una opcion valida";
            }

        } while (opcion != 5);
    }