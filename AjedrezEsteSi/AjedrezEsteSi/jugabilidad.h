#pragma once
#include "tablero.h"
extern bool caminoLibre;
extern bool seleccion;
extern bool reybMuerto;
extern bool reynMuerto;
extern int filaCamino;
extern int columnaCamino;
extern char pieza;
extern int fila;
extern int columna;
extern int destinoFila;
extern int destinoColumna;
extern int turno;
void escogerPosicion();
void escogerDestino();
void movimientos();
void escogerFicha();
void reymuerto();