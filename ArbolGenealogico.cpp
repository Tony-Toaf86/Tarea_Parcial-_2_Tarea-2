#include "ArbolGenealogico.hpp"
#include <iostream>
using namespace std;

ArbolGenealogico::ArbolGenealogico() {}

ArbolGenealogico::~ArbolGenealogico() {
    for (auto p : personas)
        delete p;
}

Persona* ArbolGenealogico::buscarRec(Persona* actual, string nombre) {
    if (!actual) return nullptr;
    if (actual->nombre == nombre) return actual;
    for (auto hijo : actual->hijos) {
        Persona* encontrado = buscarRec(hijo, nombre);
        if (encontrado) return encontrado;
    }
    return nullptr;
}

void ArbolGenealogico::mostrarAscRec(Persona* persona, int nivel) {
    if (!persona) return;
    for (int i = 0; i < nivel; i++) cout << "  ";
    cout << "-> " << persona->nombre << " (" << persona->fechaNacimiento << ")" << endl;
    mostrarAscRec(persona->padre, nivel + 1);
    mostrarAscRec(persona->madre, nivel + 1);
}

void ArbolGenealogico::mostrarDescRec(Persona* persona, int nivel) {
    if (!persona) return;
    for (int i = 0; i < nivel; i++) cout << "  ";
    cout << "-> " << persona->nombre << " (" << persona->fechaNacimiento << ")" << endl;
    for (auto hijo : persona->hijos)
        mostrarDescRec(hijo, nivel + 1);
}

void ArbolGenealogico::eliminarRec(Persona* persona) {
    if (!persona) return;
    for (auto hijo : persona->hijos)
        eliminarRec(hijo);
    persona->hijos.clear();
    delete persona;
}

void ArbolGenealogico::insertar(string nombre, string fecha, string nombrePadre, string nombreMadre) {
    Persona* nueva = new Persona(nombre, fecha);
    personas.push_back(nueva);

    Persona* p = buscar(nombrePadre);
    Persona* m = buscar(nombreMadre);

    if (p) {
        nueva->padre = p;
        p->hijos.push_back(nueva);
    }
    if (m) {
        nueva->madre = m;
        m->hijos.push_back(nueva);
    }

    cout << "Persona agregada exitosamente!" << endl;
}

Persona* ArbolGenealogico::buscar(string nombre) {
    for (auto p : personas)
        if (p->nombre == nombre) return p;
    for (auto p : personas) {
        Persona* encontrada = buscarRec(p, nombre);
        if (encontrada) return encontrada;
    }
    return nullptr;
}

void ArbolGenealogico::mostrarAscendencia(string nombre) {
    Persona* p = buscar(nombre);
    if (!p) {
        cout << "Persona no encontrada" << endl;
        return;
    }
    cout << "Ascendencia de " << nombre << ":" << endl;
    mostrarAscRec(p, 0);
}

void ArbolGenealogico::mostrarDescendencia(string nombre) {
    Persona* p = buscar(nombre);
    if (!p) {
        cout << "Persona no encontrada" << endl;
        return;
    }
    cout << "Descendencia de " << nombre << ":" << endl;
    mostrarDescRec(p, 0);
}

void ArbolGenealogico::eliminarSubarbol(string nombre) {
    Persona* p = buscar(nombre);
    if (!p) {
        cout << "Persona no encontrada" << endl;
        return;
    }

    // Eliminar del vector principal
    auto it = personas.begin();
    while (it != personas.end()) {
        if (*it == p) it = personas.erase(it);
        else ++it;
    }

    eliminarRec(p);
    cout << "Subarbol eliminado correctamente" << endl;
}

void ArbolGenealogico::menu() {
    int opcion;
    string nombre, fecha, padre, madre;

    do {
        cout << "\n===== MENU GENEALOGICO =====\n";
        cout << "1. Ingresar persona\n";
        cout << "2. Mostrar ascendencia\n";
        cout << "3. Mostrar descendencia\n";
        cout << "4. Eliminar subarbol\n";
        cout << "5. SALIR\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Fecha de nacimiento: ";
            getline(cin, fecha);
            cout << "Nombre del padre: ";
            getline(cin, padre);
            cout << "Nombre de la madre: ";
            getline(cin, madre);
            insertar(nombre, fecha, padre, madre);
            break;

        case 2:
            cout << "Ingrese el nombre para mostrar ascendencia: ";
            getline(cin, nombre);
            mostrarAscendencia(nombre);
            break;

        case 3:
            cout << "Ingrese el nombre para mostrar descendencia: ";
            getline(cin, nombre);
            mostrarDescendencia(nombre);
            break;

        case 4:
            cout << "Ingrese el nombre a eliminar: ";
            getline(cin, nombre);
            eliminarSubarbol(nombre);
            break;

        case 5:
            cout << "Programa finalizado" << endl;
            break;

        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcion != 5);
}
