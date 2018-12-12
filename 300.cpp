#include <iostream>
#include "Fecha.h"
#include "Cuac.h"
#include "DiccionarioCuacs.h"
#include "Arbol.h"

using namespace std;

DiccionarioCuacs dic;

void procesar_pcuac(void){
    Cuac* nuevo = new Cuac();
    nuevo->leer_pcuac();
    dic.insertar(nuevo);
}

void procesar_mcuac(void){
    Cuac* nuevo = new Cuac();
    nuevo->leer_mcuac();
    dic.insertar(nuevo);
}

void procesar_last(void){
    int n;
    cin >> n;
    cout << "last " << n << endl;
    dic.last(n);
}

void procesar_follow(void){
    string nombre;
    cin >> nombre;
    cout << "follow " << nombre << endl;
    dic.follow(nombre);
}

void procesar_date(void){
    Fecha f1,f2;
    f1.leer();
    f2.leer();
    cout << "date ";
    f1.escribir();
    cout << " ";
    f2.escribir();
    cout << endl;
    dic.date(f1,f2);
}

void Interprete (string comando){
    if (comando=="pcuac") procesar_pcuac();
    else if (comando=="mcuac") procesar_mcuac();
    else if (comando=="last") procesar_last();
    else if (comando=="follow") procesar_follow();
    else if (comando=="date") procesar_date();
}

int main(int argc, char const *argv[]){
        string comando;
        while (cin >> comando && comando!="exit") {
            Interprete(comando);
        }
    return 0;
}
