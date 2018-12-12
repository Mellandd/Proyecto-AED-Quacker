#ifndef _MODULO_TABLAHASH
#define _MODULO_TABLAHASH

#include "Cuac.h"
#include <list>
#include <iostream>

using namespace std;

class Par {
    friend class TablaHash;
    private:
        string nombre;
        list<Cuac*> l;
    public:
        Par(string nombre);
        string getNombre();
};

class TablaHash{
    private:
        list<Par> *T;
        int nElem;
        int M;
    public:
        TablaHash();
        ~TablaHash();
        Cuac* insertar(Cuac* nuevo);
        void consultar(const string& nombre) const;
        int numElem(void) { return nElem; }
        int dispersion(const string& s) const ;
        void reestructurar();
};


#endif
