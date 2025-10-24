#ifndef ARBOLGENEALOGICO_HPP
#define ARBOLGENEALOGICO_HPP

#include "Persona.hpp"
#include <string>
#include <vector>
using namespace std;

class ArbolGenealogico
    {
        private:
        vector<Persona*> personas;

        Persona* buscarRecursivo (Persona* actual, const string& nombre);
        void mostrarAscendenciaRec (Persona* persona, int nivel);
        void mostrarDescendenciaRec (Persona* persona, int nivel);
        void eliminarSubarbolRec (Persona* persona);

        public:
        ArbolGenealogico();
        ArbolGenealogico();

        void insertPersona 
        (const string& nombre,
        const string& fecha,
        const string& nombrePadre,
        const string& nombreMadre);
        
        Persona* buscarPersona(const string& nombre);
        void mostrarAscendencia (const string& nombre);
        void mostrarDescendencia (const string& nombre);
        void eliminarSubarbol(const string& nombre);
    };
#endif