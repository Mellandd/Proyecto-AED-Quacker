#include "TablaHash.h"
#include <cmath>

using namespace std;

Par::Par(string nombre) {
    this->nombre = nombre;
}

string Par::getNombre() {
    return nombre;
}

TablaHash::TablaHash(){
    nElem = 0;
    M = 8009; //numero primo
    T = new list<Par>[M];
}

TablaHash::~TablaHash(){
    delete[] T;
}

Cuac* TablaHash::insertar(Cuac* nuevo){
    int d = dispersion(nuevo->getUsuario());
    list<Par>::iterator itLista = T[d].begin();
    while ((itLista != T[d].end()) && (*itLista).getNombre() != nuevo->getUsuario()) ++itLista;
    if (itLista==T[d].end()){ //entonces creamos un nuevo par y lo añadimos.
        Par p(nuevo->getUsuario());
        T[d].push_back(p);
        itLista--; //porque si llega al final, "se ha salido" de la lista, y necesitamos retrocederla para que esté dentro de nuevo
    }
    list<Cuac*>::iterator itListaCuac = (*itLista).l.begin();
    while((itListaCuac != (*itLista).l.end()) && (*itListaCuac)->es_anterior(*nuevo)) ++itListaCuac;
    nElem++;
    (*itLista).l.insert(itListaCuac, nuevo);
    itListaCuac--;
    cout << numElem() << " cuac" << endl;
    if (nElem > 2*M) reestructurar();
    return *itListaCuac;
}

void TablaHash::consultar(const string& nombre) const {
    int d = dispersion(nombre);
    list<Par>::iterator itLista = T[d].begin();
    int contador = 0;
    while (itLista != T[d].end() && (*itLista).getNombre() != nombre) ++itLista;
    if (itLista != T[d].end()){
        list<Cuac*>::iterator itListaCuac = (*itLista).l.begin();
        while(itListaCuac != (*itLista).l.end()){
            contador++;
            cout << contador << ". ";
            (*itListaCuac)->escribir();
            itListaCuac++;
        }
    }
    cout << "Total: " << contador << " cuac" << endl;
}

int TablaHash::dispersion(const string& s) const {
    int suma = 0;
    int size = s.size();
    for(int i=1; i<=size+1; i++){
        suma += abs(i*s[i-1]);
    }
  return suma%M;
}

void TablaHash::reestructurar() {
    int m = M;
    int i, j;
    M = 2*M;
    list<Par>* aux = new list<Par>[M];
    for (i = 0; i < m; i++) {
        list<Par>::iterator itL = T[i].begin();
        while(itL != T[i].end()) {
          j = dispersion(itL->getNombre());
          list<Par>::iterator itL2 = aux[j].begin();
          while (itL2 != aux[j].end() && itL2->getNombre() > itL->getNombre()) itL2++;
          aux[j].insert(itL2, *itL);
          itL++;
        }
    }
    delete[]T;
    T = aux;
}
