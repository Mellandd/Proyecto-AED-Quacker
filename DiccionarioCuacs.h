// Modulo Diccionario
#ifndef _MODULO_DICCIONARIO
#define _MODULO_DICCIONARIO
#include <list>
#include <iostream>
#include "Cuac.h"
#include "TablaHash.h"
#include "Arbol.h"

using namespace std;

class DiccionarioCuacs{
    private:
        TablaHash tabla;
        Arbol arbol;
    public:
        void insertar(Cuac* nuevo)
            {   Cuac *ref = tabla.insertar(nuevo);
                arbol.insertar(ref);}
        void last(int N)
            { arbol.last(N); }
        void follow(const string& nombre)const {
            tabla.consultar(nombre);}
        void date(Fecha f1, Fecha f2)
            { arbol.date(f1, f2); }
        int numElem()
            {return tabla.numElem();}
};

#endif
