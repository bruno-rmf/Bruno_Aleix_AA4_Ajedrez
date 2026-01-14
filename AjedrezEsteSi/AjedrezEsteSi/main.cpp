#include "funcionalidades.h"
//BLANCOS SON MAYUS negros son minusculas

int main() {
    inicializarTablero();
    while (!reybMuerto && !reynMuerto)
    {
        imprimirTablero();
        escogerFicha();
        coronar();
        reymuerto();
        system("cls");
    }
    return 0;
}