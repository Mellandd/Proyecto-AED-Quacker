// Modulo Diccionario
#ifndef _MODULO_ARBOL
#define _MODULO_ARBOL

#include "Cuac.h"
#include "Fecha.h"
#include <list>

using namespace std;

class Nodo {
    friend class Arbol;
    private:
        Nodo *hijoIzquierdo;
        Nodo *hijoDerecho;
        Fecha fecha;
        list<Cuac*> *lista;
        int altura;
        int alturaNodo();
    public:
        Nodo ();
        ~Nodo () {
            delete hijoIzquierdo;
            delete hijoDerecho;
            delete lista;
        }
        void actualizarAltura();
        int last(int n, int& m);
        void date (Fecha f1, Fecha f2, int& m);
};

class Arbol {
    private:
        Nodo *raiz;
        void insertar (Cuac *ref, Nodo *&nodo);
        void RSI (Nodo *&nodo) const ;
        void RSD (Nodo *&nodo) const ;
        void RDI (Nodo *&nodo) const ;
        void RDD (Nodo *&nodo) const ;
    public:
        Arbol ();
        ~Arbol () {
            delete raiz;
        }
        void rebalance(Nodo *&nodo);
        void insertar (Cuac *ref);
        void last (int N);
        void date (Fecha f1, Fecha f2);
};

#endif
