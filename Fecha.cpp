#include <iostream>
#include <iomanip>
#include "Fecha.h"

using namespace std;

void funcion (){

}

int errorCode = 0;

Fecha::Fecha(){
    Fecha(0,0,0,0,0,0);
}

Fecha::Fecha(int dia, int mes, int ano, int hora, int minuto, int segundo){
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
        this->hora = hora;
        this->minuto = minuto;
        this->segundo = segundo;
}

bool Fecha::leer(void){
    int dia, mes, ano, hora, minuto, segundo;
    char aux;
    cin >> dia >> aux >> mes >> aux >> ano >> hora >> aux >> minuto >> aux >> segundo;
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
    cin.ignore();
    return true;
}

void Fecha::escribir(void){
    cout << this->dia << "/" << this->mes << "/" << this->ano << " " << setfill('0') << setw(2) << this->hora << ":" << setfill('0') << setw(2) << this->minuto << ":" << setfill('0') << setw(2) << this->segundo;
}

bool Fecha::es_menor(Fecha &otra){
    if (this->ano < otra.ano) return true;
    else if (this->ano == otra.ano){
        if (this->mes < otra.mes) return true;
        else if (this->mes==otra.mes){
            if (this->dia < otra.dia) return true;
            else if (this->dia == otra.dia){
                if (this->hora < otra.hora) return true;
                else if (this->hora == otra.hora){
                    if (this->minuto < otra.minuto) return true;
                    else if (this->minuto == otra.minuto){
                        if (this->segundo < otra.segundo) return true;
                        else return false;
                    }
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

bool Fecha::es_igual(Fecha &otra){
    if ((this->ano==otra.ano) && (this->mes==otra.mes) && (this->dia==otra.dia)
        && (this->hora==otra.hora) && (this->minuto==otra.minuto) && (this->segundo==otra.segundo)) return true;
    else return false;
}
