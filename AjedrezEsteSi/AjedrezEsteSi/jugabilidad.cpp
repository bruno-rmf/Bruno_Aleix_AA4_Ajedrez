#include "jugabilidad.h"
bool caminoLibre = false;
bool seleccion = false;
int filaCamino;
int columnaCamino;
char pieza;
int fila;
int columna; 
int destinoFila;
int destinoColumna;
int turno = 1;
//Optimizar el hecho de escoger la posicion donde queremos mover la ficha o la seleccion de ficha
void escogerPosicion() {
    std::cout << "Fila: ";
    std::cin >> fila;
    std::cout << "Columna: ";
    std::cin >> columna;
    fila = ALTO - fila;
    columna--;
}

void escogerDestino() {
    std::cout << "Fila: ";
    std::cin >> destinoFila;
    std::cout << "Columna: ";
    std::cin >> destinoColumna;
    destinoFila = ALTO - destinoFila;
    destinoColumna--;
}
//Movimientos de las piezas 
void movimientos()
{
    std::cout << "Escoje el destino \n";
    escogerDestino();
    caminoLibre = true;

    switch (pieza)
    {
        //PEONES
    case 'p':
        //Peón NEGRO
        if (destinoFila == fila + 1 && destinoColumna == columna && tablero[destinoFila][destinoColumna] == '*')
        {
            //Movimiento normal de 1 casilla hacia adelante si está vacío
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'p';
        }
        else if (fila == 1 && destinoFila == fila + 2 && destinoColumna == columna && tablero[fila + 1][columna] == '*' && tablero[destinoFila][destinoColumna] == '*')
        {
            //Movimiento inicial de 2 casillas
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'p';
        }
        else if (destinoFila == fila + 1 && (destinoColumna == columna - 1 || destinoColumna == columna + 1) && tablero[destinoFila][destinoColumna] >= 'A' && tablero[destinoFila][destinoColumna] <= 'Z')
        {
            //Captura en diagonal: debe haber una pieza BLANCA (A-Z)
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'p';
        }
        else
        {
            std::cout << "Movimiento invalido para el peon negro \n";
            movimientos();
        }
        break;

    case 'P':
        //Peón BLANCO
        if (destinoFila == fila - 1 && destinoColumna == columna && tablero[destinoFila][destinoColumna] == '*')
        {
            //Adelante 1 casilla
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'P';
        }
        else if (fila == 6 && destinoFila == fila - 2 && destinoColumna == columna && tablero[fila - 1][columna] == '*' && tablero[destinoFila][destinoColumna] == '*')
        {
            //Adelante 2 casillas
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'P';
        }
        else if (destinoFila == fila - 1 && (destinoColumna == columna - 1 || destinoColumna == columna + 1) && tablero[destinoFila][destinoColumna] >= 'a' && tablero[destinoFila][destinoColumna] <= 'z')
        {
            //Captura en diagonal: debe haber una pieza NEGRA (a-z)
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'P';
        }
        else
        {
            std::cout << "Movimiento invalido para el peon blanco \n";
            movimientos();
        }
        break;

        //TORRES
    case 't': case 'T':
        //La torre solo se mueve si la fila es igual o la columna es igual (línea recta)
        if (destinoFila == fila || destinoColumna == columna)
        {
            // Determinamos hacia dónde avanza
            if (destinoFila > fila) {
                filaCamino = 1;
            }
            else if (destinoFila < fila) {
                filaCamino = -1;
            }
            else
            {
                filaCamino = 0;
            }

            if (destinoColumna > columna) {
                columnaCamino = 1;
            }
            else if (destinoColumna < columna) {
                columnaCamino = -1;
            }
            else
            {
                columnaCamino = 0;
            }
            //Revisa cada casilla hasta el destino
            for (int f = fila + filaCamino, c = columna + columnaCamino; f != destinoFila || c != destinoColumna; f = f + filaCamino, c = c + columnaCamino)
            {
                //Si encontramos algo que no sea vacío (*), el camino está bloqueado
                if (tablero[f][c] != '*')
                {
                    caminoLibre = false;
                }
            }
            if (caminoLibre == true)
            {
                //Si el camino está despejado, comprobamos el bando de la pieza
                if (pieza == 'T')
                {
                    //La blanca no puede caer sobre otra blanca (A-Z)
                    if (!(tablero[destinoFila][destinoColumna] >= 'A' && tablero[destinoFila][destinoColumna] <= 'Z'))
                    {
                        tablero[fila][columna] = '*';
                        tablero[destinoFila][destinoColumna] = 'T';
                    }
                    else
                    {
                        std::cout << "No puedes mover encima de tus propias fichas \n";
                        movimientos();
                    }
                }
                else if (pieza == 't')
                {
                    //La negra no puede caer sobre otra negra (a-z)
                    if (!(tablero[destinoFila][destinoColumna] >= 'a' && tablero[destinoFila][destinoColumna] <= 'z'))
                    {
                        tablero[fila][columna] = '*';
                        tablero[destinoFila][destinoColumna] = 't';
                    }

                    else
                    {
                        std::cout << "No puedes mover encima de tus propias fichas \n";
                        movimientos();
                    }
                }
            }
            else
            {
                std::cout << "El camino de la torre esta obstruido \n";
                movimientos();
            }
        }
        else
        {
            std::cout << "La torre solo se mueve en linea recta \n";
            movimientos();
        }
        break;
        //CABALLOS
    case 'h': case 'H':
        //Calculamos la distancia recorrida
        filaCamino = destinoFila - fila;
        if (filaCamino < 0)
        {
            filaCamino = -filaCamino;
        }
        columnaCamino = destinoColumna - columna;
        if (columnaCamino < 0)
        {
            columnaCamino = -columnaCamino;
        }
        //El caballo se mueve en "L"
        if ((filaCamino == 2 && columnaCamino == 1) || (filaCamino == 1 && columnaCamino == 2))
        {
            if (pieza == 'H')
            {
                // Comprobar que el destino no sea BLANCA
                if (!(tablero[destinoFila][destinoColumna] >= 'A' && tablero[destinoFila][destinoColumna] <= 'Z'))
                {
                    tablero[fila][columna] = '*';
                    tablero[destinoFila][destinoColumna] = 'H';
                }
                else
                {
                    std::cout << "No puedes capturar tu propia ficha \n";
                    movimientos();
                }
            }
            else if (pieza == 'h')
            {
                //Comprobar que el destino no sea NEGRA
                if (!(tablero[destinoFila][destinoColumna] >= 'a' && tablero[destinoFila][destinoColumna] <= 'z'))
                {
                    tablero[fila][columna] = '*';
                    tablero[destinoFila][destinoColumna] = 'h';
                }
                else
                {
                    std::cout << "No puedes capturar tu propia ficha \n";
                    movimientos();
                }
            }
        }
        else
        {
            std::cout << "El caballo debe moverse en L \n";
            movimientos();
        }
        break;

        //ALFILES
    case 'b': case 'B':
        //Validamos diagonal: la distancia en filas debe ser igual a la de columnas
        filaCamino = destinoFila - fila;
        if (filaCamino < 0) { filaCamino = -filaCamino; }
        columnaCamino = destinoColumna - columna;
        if (columnaCamino < 0) { columnaCamino = -columnaCamino; }

        if (filaCamino == columnaCamino)
        {
            //Determinamos si el alfil va hacia arriba, abajo, izquierda o derecha
            int fDir = (destinoFila > fila) ? 1 : -1;
            int cDir = (destinoColumna > columna) ? 1 : -1;

            //Revisamos cada casilla de la diagonal para comprobar si hay obstaculos
            for (int f = fila + fDir, c = columna + cDir; f != destinoFila; f = f + fDir, c = c + cDir)
            {
                if (tablero[f][c] != '*')
                {
                    caminoLibre = false;
                }
            }

            if (caminoLibre == true)
            {
                if (pieza == 'B')
                {
                    if (!(tablero[destinoFila][destinoColumna] >= 'A' && tablero[destinoFila][destinoColumna] <= 'Z'))
                    {
                        tablero[fila][columna] = '*';
                        tablero[destinoFila][destinoColumna] = 'B';
                    }

                    else
                    {
                        std::cout << "No puedes mover encima de tus propias fichas \n";
                        movimientos();
                    }
                }

                else if (pieza == 'b')
                {
                    if (!(tablero[destinoFila][destinoColumna] >= 'a' && tablero[destinoFila][destinoColumna] <= 'z'))
                    {
                        tablero[fila][columna] = '*';
                        tablero[destinoFila][destinoColumna] = 'b';
                    }

                    else
                    {
                        std::cout << "No puedes mover encima de tus propias fichas \n";
                        movimientos();
                    }
                }
            }

            else
            {
                std::cout << "El camino del alfil esta obstruido \n";
                movimientos();
            }
        }

        else
        {
            std::cout << "El alfil solo se mueve en diagonal \n";
            movimientos();
        }
        break;

        //REINAS
    case 'q': case 'Q':
        // La reina combina el movimiento de la torre y el alfil
        filaCamino = destinoFila - fila;
        if (filaCamino < 0)
        {
            filaCamino = -filaCamino;
        }
        columnaCamino = destinoColumna - columna;
        if (columnaCamino < 0)
        {
            columnaCamino = -columnaCamino;
        }

        if (destinoFila == fila || destinoColumna == columna || filaCamino == columnaCamino)
        {

            int fStep = (destinoFila > fila) ? 1 : (destinoFila < fila ? -1 : 0);
            int cStep = (destinoColumna > columna) ? 1 : (destinoColumna < columna ? -1 : 0);

            //Recorremos el camino para ver si hay algun obstaculo
            for (int f = fila + fStep, c = columna + cStep; f != destinoFila || c != destinoColumna; f = f + fStep, c = c + cStep)
            {
                if (tablero[f][c] != '*')
                {
                    caminoLibre = false;
                }
            }

            if (caminoLibre == true)
            {
                if (pieza == 'Q')
                {
                    if (!(tablero[destinoFila][destinoColumna] >= 'A' && tablero[destinoFila][destinoColumna] <= 'Z'))
                    {
                        tablero[fila][columna] = '*';
                        tablero[destinoFila][destinoColumna] = 'Q';
                    }
                    else
                    {
                        std::cout << "No puedes mover encima de tus propias fichas \n";
                        movimientos();
                    }
                }
                else if (pieza == 'q')
                {
                    if (!(tablero[destinoFila][destinoColumna] >= 'a' && tablero[destinoFila][destinoColumna] <= 'z'))
                    {
                        tablero[fila][columna] = '*';
                        tablero[destinoFila][destinoColumna] = 'q';
                    }
                    else
                    {
                        std::cout << "No puedes mover encima de tus propias fichas \n";
                        movimientos();
                    }
                }
            }
            else
            {
                std::cout << "El camino de la reina esta obstruido \n";
                movimientos();
            }
        }
        else
        {
            std::cout << "Movimiento de reina no permitido \n";
            movimientos();
        }
        break;

        //REYES
    case 'k': case 'K':
        //El rey puede moverse a cualquier casilla (distancia máxima 1)
        filaCamino = destinoFila - fila;
        if (filaCamino < 0) { filaCamino = -filaCamino; }

        columnaCamino = destinoColumna - columna;
        if (columnaCamino < 0) { columnaCamino = -columnaCamino; }

        //Validamos que no se mueva más de 1 casilla
        if (filaCamino <= 1 && columnaCamino <= 1 && !(destinoFila == fila && destinoColumna == columna))
        {
            if (pieza == 'K')
            {
                if (!(tablero[destinoFila][destinoColumna] >= 'A' && tablero[destinoFila][destinoColumna] <= 'Z'))
                {
                    tablero[fila][columna] = '*';
                    tablero[destinoFila][destinoColumna] = 'K';
                }
                else
                {
                    std::cout << "No puedes mover encima de tus propias fichas \n";
                    movimientos();
                }
            }
            else if (pieza == 'k')
            {
                if (!(tablero[destinoFila][destinoColumna] >= 'a' && tablero[destinoFila][destinoColumna] <= 'z'))
                {
                    tablero[fila][columna] = '*';
                    tablero[destinoFila][destinoColumna] = 'k';
                }
                else
                {
                    std::cout << "No puedes mover encima de tus propias fichas \n";
                    movimientos();
                }
            }
        }
        else
        {
            std::cout << "El rey solo se mueve una casilla en cualquier direccion \n";
            movimientos();
        }
        break;
    default:
        break;
    }
}

void escogerFicha() {
    if (turno == 1)
    {
        //Si la seleccion no es correcta se forma un bucle hasta que la seleccione correctamente
        while (!seleccion)
        {
            std::cout << "Jugador BLANCAS escoge la ficha que quieres mover  \n";
            escogerPosicion();
            //Comprueba si la ficha es blanca
            if (tablero[fila][columna] >= 'A' && tablero[fila][columna] <= 'Z')
            {
                std::cout << "Seleccion correcta  \n";
                pieza = tablero[fila][columna];
                seleccion = true;
            }
        }
        movimientos();
        seleccion = false;
        turno++;
    }
    else
    {
        //Si la seleccion no es correcta se forma un bucle hasta que la seleccione correctamente
        while (!seleccion)
        {
            std::cout << "Jugador NEGRAS escoge la ficha que quieres mover  \n";
            escogerPosicion();
            //Comprueba si la ficha es negra
            if (tablero[fila][columna] >= 'a' && tablero[fila][columna] <= 'z')
            {
                std::cout << "Seleccion correcta  \n";
                pieza = tablero[fila][columna];
                seleccion = true;
            }
        }
        movimientos();
        seleccion = false;
        turno--;
    }
}