#include "funcionalidades.h"
//En caso de que el PEÓN LLEGUE A LA ULTIMA FILA CAMBIA A SER REINA
void coronar() {
    for (int i = 0; i < ALTO; i++)
    {
        if (tablero[0][i] == 'P')
        {
            tablero[0][i] = 'Q';
        }
    }
    for (int i = 0; i < ALTO; i++)
    {
        if (tablero[ALTO - 1][i] == 'p')
        {
            tablero[ALTO - 1][i] = 'q';
        }
    }

}