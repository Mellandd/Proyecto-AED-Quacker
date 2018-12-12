#include "Cuac.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_TEXTOS= 30;
string Textos[MAX_TEXTOS]={
"Afirmativo.",
"Negativo.",
"Estoy de viaje en el extranjero.",
"Muchas gracias a todos mis seguidores por vuestro apoyo.",
"Enhorabuena, campeones!",
"Ver las novedades en mi pagina web.",
"Estad atentos a la gran exclusiva del siglo.",
"La inteligencia me persigue pero yo soy mas rapido.",
"Si no puedes convencerlos, confundelos.",
"La politica es el arte de crear problemas.",
"Donde estan las llaves, matarile, rile, rile...",
"Si no te gustan mis principios, puedo cambiarlos por otros.",
"Un dia lei que fumar era malo y deje de fumar.",
"Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi.",
"Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.",
"Mi vida no es tan glamurosa como mi pagina web aparenta.",
"Todo tiempo pasado fue anterior.",
"El azucar no engorda... engorda el que se la toma.",
"Solo los genios somos modestos.",
"Nadie sabe escribir tambien como yo.",
"Si le molesta el mas alla, pongase mas aca.",
"Me gustaria ser valiente. Mi dentista asegura que no lo soy.",
"Si el dinero pudiera hablar, me diria adios.",
"Hoy me ha pasado una cosa tan increible que es mentira.",
"Si no tienes nada que hacer, por favor no lo hagas en clase.",
"Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza.",
"Me despido hasta la proxima. Buen viaje!",
"Cualquiera se puede equivocar, inclusivo yo.",
"Estoy en Egipto. Nunca habia visto las piramides tan solas.",
"El que quiera saber mas, que se vaya a Salamanca."
};


string convertirNumero (int numero){
    return Textos[numero-1];
};

int convertirTexto(string s){
    int i = 0;
    while ((Textos[i] != s) && (i<30)){
        i++;
    }
    return i+1;
}

string Cuac::getUsuario(){
    return usuario;
}

Fecha Cuac::getFecha(){
    return fecha;
}

bool Cuac::leer_mcuac(){
    string texto;
    cin >> this->usuario;
    cin.ignore();
    fecha.leer();
    getline(cin, texto);
    this->texto = texto;
    return true;
}

bool Cuac::leer_pcuac(){
    int numero;
    cin >> this->usuario;
    cin.ignore();
    fecha.leer();
    cin >> numero;
    cin.ignore();
    this->texto = convertirNumero(numero);
    return true;
}

void Cuac::escribir(){
    cout << usuario << " ";
    fecha.escribir();
    cout << endl << "   " << texto << endl;
}

bool Cuac::es_anterior(Cuac &otro){
    if (this->fecha.es_menor(otro.fecha)) return false;
    else if (this->fecha.es_igual(otro.fecha)){
        if (this->texto < otro.texto) return true;
        else if (this->texto == otro.texto){
            if (this->usuario < otro.usuario) return true;
            else return false;
        }
        else return false;
    }
    else return true;
}
