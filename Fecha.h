// Modulo Fecha
#ifndef _MODULO_FECHA
#define _MODULO_FECHA

void funcion();

extern int errorCode;

class Fecha{
        private:
            int dia, mes, ano;
            int hora, minuto, segundo;
        public:
            Fecha();
            Fecha(int dia, int mes, int ano, int hora, int minuto, int segundo);
            bool leer();
            void escribir(void);
            bool es_menor(Fecha &otra);
            bool es_igual(Fecha &otra);
};

#endif
