// Modulo Cuac
#ifndef _MODULO_CUAC
#define _MODULO_CUAC
#include "Fecha.h"
#include <list>
#include <string>

using namespace std;

class Cuac{
        private:
            Fecha fecha;
            string usuario;
            string texto;
        public:
            Cuac(){}
            string getUsuario();
            Fecha getFecha();
            bool leer_mcuac();
            bool leer_pcuac();
            void escribir();
            bool es_anterior(Cuac &otro);
};

#endif
