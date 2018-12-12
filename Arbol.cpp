#include "Arbol.h"
#include "Cuac.h"
#include <algorithm>
#include <iostream>

using namespace std;

Nodo::Nodo() {
    hijoIzquierdo = nullptr;
    hijoDerecho = nullptr;
    lista = new list<Cuac*>();
    altura = 0;
}

int Nodo::alturaNodo() {


}

void Nodo::actualizarAltura() {
    this->altura = 1 + max(hijoDerecho->altura, hijoIzquierdo->altura);

    if(hijoDerecho == nullptr && hijoIzquierdo == nullptr) this->altura = 0;
    else {
      if(hijoDerecho != nullptr && hijoIzquierdo != nullptr) {
        this->altura = 1 + max(hijoDerecho->altura, hijoIzquierdo->altura);
      }
      else if (hijoDerecho == nullptr) {
        this->altura = 1 + hijoIzquierdo->altura;
      } else {
        this->altura = 1 + hijoDerecho->altura;
      }
    }
}

void Arbol::RSI(Nodo *&nodo)const {
    Nodo* aux = nodo->hijoIzquierdo;
    nodo->hijoIzquierdo = aux->hijoDerecho;
    aux->hijoDerecho = nodo;
    nodo = aux;
    nodo->hijoDerecho->actualizarAltura();
    nodo->actualizarAltura();
}

void Arbol::RSD(Nodo *&nodo)const {
    Nodo* aux = nodo->hijoDerecho;
    nodo->hijoDerecho = aux->hijoIzquierdo;
    aux->hijoIzquierdo = nodo;
    nodo = aux;
    nodo->hijoIzquierdo->actualizarAltura();
    nodo->actualizarAltura();
}

void Arbol::RDI(Nodo *&nodo)const {
    RSD(nodo->hijoIzquierdo);
    return RSI(nodo);
    nodo->hijoDerecho->actualizarAltura();
    nodo->hijoIzquierdo->actualizarAltura();
    nodo->actualizarAltura();
}

void Arbol::RDD(Nodo *&nodo)const {
    RSI(nodo->hijoDerecho);
    RSD(nodo);
    nodo->hijoDerecho->actualizarAltura();
    nodo->hijoIzquierdo->actualizarAltura();
    nodo->actualizarAltura();
}

int Nodo::last(int n, int& m) {
    if (n==0) return n;
    if (this->hijoDerecho != nullptr) {
        n = this->hijoDerecho->last(n,m);
    }
    if (n!=0)
    {
        list<Cuac*>::iterator itL = this->lista->begin();
        while(n!=0 && itL != this->lista->end()) {
            cout << m <<". ";
            (*itL)->escribir();
            m++;
            n--;
            itL++;
        }
    }
    if (n!=0 && this->hijoIzquierdo != nullptr) {
        n = this->hijoIzquierdo->last(n,m);
    }
    return n;
}

Arbol::Arbol(){
    raiz = nullptr;
}


void Arbol::rebalance(Nodo *&nodo) {
    int diff = alturaNodo(nodo->hijoIzquierdo) - alturaNodo(nodo->hijoDerecho);
    if (diff > 1) {
      if((alturaNodo(nodo->hijoIzquierdo->hijoIzquierdo) - alturaNodo(nodo->hijoIzquierdo->hijoDerecho)) > 0) {
        RSI(nodo);
      } else {
        RDI(nodo);
      }
    } else if (diff < -1) {
      if ((alturaNodo(nodo->hijoDerecho->hijoIzquierdo) - alturaNodo(nodo->hijoDerecho->hijoDerecho)) < 0) {
        RSD(nodo);
      } else {
        RDD(nodo);
      }
    }
}

void Arbol::insertar(Cuac* ref) {
    insertar(ref, raiz);
}


void Arbol::insertar(Cuac* ref, Nodo *&nodo){
    if (nodo == nullptr) {
      nodo = new Nodo();
      nodo->lista->push_back(ref);
      nodo->fecha = ref->getFecha();
    } else {
        if (ref->getFecha().es_igual(nodo->fecha)){
            list<Cuac*>::iterator itL = nodo->lista->begin();
            while (itL != nodo->lista->end() && (*itL)->es_anterior(*ref)) itL++;
            if (itL == nodo->lista->end()) nodo->lista->push_back(ref);
            else nodo->lista->insert(itL, ref);
        }
        else if (ref->getFecha().es_menor(nodo->fecha)) {
            insertar(ref, nodo->hijoIzquierdo);
            nodo->actualizarAltura();
            rebalance(nodo);
        } else {
            insertar(ref, nodo->hijoDerecho);
            nodo->actualizarAltura();
            rebalance(nodo);
        }
    }
}

void Arbol::last(int n) {
    if (raiz == nullptr ) {
        cout << "Total: " << 0 << " cuac" << endl;
    }
    else {
    int m = 1;
    int aux = raiz->last(n,m);
    cout << "Total: " << n - aux << " cuac" << endl;
    }
}

void Arbol::date(Fecha f1, Fecha f2) {
    int m = 0;
    if (raiz == nullptr) cout << "Total: 0 cuac" << endl;
    else {
        raiz->date(f1,f2,m);
        cout << "Total: " << m << " cuac" << endl;
    }
}

void Nodo::date(Fecha f1, Fecha f2, int& m){
    if (this->hijoDerecho != nullptr && this->fecha.es_menor(f1)) {
      this->hijoDerecho->date(f1,f2,m);
    }
    if ((f1.es_menor(this->fecha) || f1.es_igual(this->fecha)) && ( this->fecha.es_menor(f2) || this->fecha.es_igual(f2))) {
      if (this->hijoDerecho != nullptr) this->hijoDerecho->date(f1,f2,m);
      list<Cuac*>::iterator itL = this->lista->begin();
      while(itL != this->lista->end()) {
          m++;
          cout << m <<". ";
          (*itL)->escribir();
          itL++;
      }
      if (this->hijoIzquierdo!= nullptr) this->hijoIzquierdo->date(f1,f2,m);
    }
    if (this->hijoIzquierdo != nullptr && f2.es_menor(this->fecha)) {
      this->hijoIzquierdo->date(f1,f2,m);
    }
}
