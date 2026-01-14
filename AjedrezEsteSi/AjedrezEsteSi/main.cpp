#include "funcionalidades.h"
//BLANCOS SON MAYUS negros son minusculas
bool reybMuerto = false;
bool reynMuerto = false;
int main() {
    inicializarTablero();
    while (!reybMuerto && !reynMuerto)
    {
        imprimirTablero();
        escogerFicha();
        coronar();
        jaqueMate();
        system("cls");
    }
    return 0;
}