#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <string>
#include <vector>
using namespace std;

class Persona {
public:
    string nombre;
    string fechaNacimiento;
    Persona* padre;
    Persona* madre;
    vector<Persona*> hijos;

    Persona(string n, string f) {
        nombre = n;
        fechaNacimiento = f;
        padre = nullptr;
        madre = nullptr;
    }
};

#endif
