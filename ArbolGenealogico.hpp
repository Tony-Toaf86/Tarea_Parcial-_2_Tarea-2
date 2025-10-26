#ifndef ARBOLGENEALOGICO_HPP
#define ARBOLGENEALOGICO_HPP

#include "Persona.hpp"
#include <string>
#include <vector>
using namespace std;

class ArbolGenealogico {
private:
    vector<Persona*> personas;

    Persona* buscarRec(Persona* actual, string nombre);
    void mostrarAscRec(Persona* persona, int nivel);
    void mostrarDescRec(Persona* persona, int nivel);
    void eliminarRec(Persona* persona);

public:
    ArbolGenealogico();
    ~ArbolGenealogico();

    void insertar(string nombre, string fecha, string nombrePadre, string nombreMadre);
    Persona* buscar(string nombre);
    void mostrarAscendencia(string nombre);
    void mostrarDescendencia(string nombre);
    void eliminarSubarbol(string nombre);
    void menu();
};

#endif
