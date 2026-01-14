#include <iostream>
#define ANCHO 8
#define ALTO 8

char tablero[ALTO][ANCHO];
bool reybMuerto = false;
bool reynMuerto = false;
int turno = 1;
char pieza;
int fila;
int columna;
bool seleccion = false;
int destinoFila;
int destinoColumna;
bool caminoLibre = false;
int filaCamino;
int columnaCamino;
bool jaqueBlanco = false;
bool jaqueNegro = false;

//BLANCOS SON MAYUS negros son minusculas

//inicializar el tablero cuando empieza la partida
void inicializarTablero() {

    //piezas negras
    tablero[0][0] = 't';
    tablero[0][1] = 'h';
    tablero[0][2] = 'b';
    tablero[0][3] = 'k';
    tablero[0][4] = 'q';
    tablero[0][5] = 'b';
    tablero[0][6] = 'h';
    tablero[0][7] = 't';

    for (int i = 0; i < ANCHO; i++) {
        tablero[1][i] = 'p';
    }

    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            tablero[i][j] = '*';
        }
    }

    for (int i = 0; i < ANCHO; i++) {
        tablero[6][i] = 'P';
    }

    //piezas blancas
    tablero[7][0] = 'T';
    tablero[7][1] = 'H';
    tablero[7][2] = 'B';
    tablero[7][3] = 'Q';
    tablero[7][4] = 'K';
    tablero[7][5] = 'B';
    tablero[7][6] = 'H';
    tablero[7][7] = 'T';
}

//imprimir el tablero
void imprimirTablero() {
    std::cout << "  1 2 3 4 5 6 7 8\n";

    std::cout << "8 ";
    for (int j = 0; j < ANCHO; j++)
        std::cout << tablero[0][j] << " ";
    std::cout << "\n";

    std::cout << "7 ";
    for (int j = 0; j < ANCHO; j++)
        std::cout << tablero[1][j] << " ";
    std::cout << "\n";

    for (int i = 2; i < 6; i++) {
        std::cout << 8 - i << " ";
        for (int j = 0; j < ANCHO; j++)
            std::cout << tablero[i][j] << " ";
        std::cout << "\n";
    }

    std::cout << "2 ";
    for (int j = 0; j < ANCHO; j++)
        std::cout << tablero[6][j] << " ";
    std::cout << "\n";

    std::cout << "1 ";
    for (int j = 0; j < ANCHO; j++)
        std::cout << tablero[7][j] << " ";
    std::cout << "\n";
}

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
            if (destinoFila > fila){
                filaCamino = 1; 
            }
            else if (destinoFila < fila){ 
                filaCamino = -1; 
            }
            else 
            { 
                filaCamino = 0; 
            }

            if (destinoColumna > columna){ 
                columnaCamino = 1; 
            }
            else if (destinoColumna < columna){ 
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
       
//Manera de saber si escoge correctamente la ficha que utilizara en ese movimiento
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
//FALTA COMPROBAR SI FUNCIONA CORRECTAMENTE
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
        if (tablero[ALTO-1][i] == 'p')
        {
            tablero[ALTO-1][i] = 'q';
        }
    }

}

void jaque()
{
    jaqueBlanco = false;
    jaqueNegro = false;

    for (int i = 0; i < ALTO; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            // Rey blanco
            if (tablero[i][j] == 'K')
            {
                // TORRES y REINA mirar las filas
                for (int c = 0; c < ANCHO; c++)
                {
                    if (tablero[i][c] == 't' || tablero[i][c] == 'q')
                    {
                        jaqueBlanco = true;
                    }
                }

                // TORRES y REINA mirar las columnas
                for (int f = 0; f < ALTO; f++)
                {
                    if (tablero[f][j] == 't' || tablero[f][j] == 'q')
                    {
                        jaqueBlanco = true;
                    }
                }

                // PEONES negros
                if (i - 1 >= 0)
                {
                    if (j + 1 < ANCHO)
                    {
                        if (tablero[i - 1][j + 1] == 'p')
                        {
                            jaqueBlanco = true;
                        }
                    }
                    if (j - 1 >= 0)
                    {
                        if (tablero[i - 1][j - 1] == 'p')
                        {
                            jaqueBlanco = true;
                        }
                    }
                }

                // ALFILES y REINA mirar diagonales
                for (int k = 1; i + k < ALTO && j + k < ANCHO; k++)
                {
                    if (tablero[i + k][j + k] == 'a' || tablero[i + k][j + k] == 'q')
                    {
                        jaqueBlanco = true;
                    }
                }

                for (int k = 1; i + k < ALTO && j - k >= 0; k++)
                {
                    if (tablero[i + k][j - k] == 'a' || tablero[i + k][j - k] == 'q')
                    {
                        jaqueBlanco = true;
                    }
                }

                for (int k = 1; i - k >= 0 && j + k < ANCHO; k++)
                {
                    if (tablero[i - k][j + k] == 'a' || tablero[i - k][j + k] == 'q')
                    {
                        jaqueBlanco = true;
                    }
                }

                for (int k = 1; i - k >= 0 && j - k >= 0; k++)
                {
                    if (tablero[i - k][j - k] == 'a' || tablero[i - k][j - k] == 'q')
                    {
                        jaqueBlanco = true;
                    }
                }

                // CABALLOS negros
                if (i + 2 < ALTO && j + 1 < ANCHO)
                {
                    if (tablero[i + 2][j + 1] == 'h')
                    {
                        jaqueBlanco = true;
                    }
                }
                if (i + 2 < ALTO && j - 1 >= 0)
                {
                    if (tablero[i + 2][j - 1] == 'h')
                    {
                        jaqueBlanco = true;
                    }
                }
                if (i - 2 >= 0 && j + 1 < ANCHO)
                {
                    if (tablero[i - 2][j + 1] == 'h')
                    {
                        jaqueBlanco = true;
                    }
                }
                if (i - 2 >= 0 && j - 1 >= 0)
                {
                    if (tablero[i - 2][j - 1] == 'h')
                    {
                        jaqueBlanco = true;
                    }
                }

                if (i + 1 < ALTO && j + 2 < ANCHO)
                {
                    if (tablero[i + 1][j + 2] == 'h')
                    {
                        jaqueBlanco = true;
                    }
                }
                if (i + 1 < ALTO && j - 2 >= 0)
                {
                    if (tablero[i + 1][j - 2] == 'h')
                    {
                        jaqueBlanco = true;
                    }
                }
                if (i - 1 >= 0 && j + 2 < ANCHO)
                {
                    if (tablero[i - 1][j + 2] == 'h')
                    {
                        jaqueBlanco = true;
                    }
                }
                if (i - 1 >= 0 && j - 2 >= 0)
                {
                    if (tablero[i - 1][j - 2] == 'h')
                    {
                        jaqueBlanco = true;
                    }
                }
            }

            // Rey negro
            if (tablero[i][j] == 'k')
            {
                // TORRES y REINA mirar filas
                for (int c = 0; c < ANCHO; c++)
                {
                    if (tablero[i][c] == 'T' || tablero[i][c] == 'Q')
                    {
                        jaqueNegro = true;
                    }
                }

                // TORRES y REINA mirar columnas
                for (int f = 0; f < ALTO; f++)
                {
                    if (tablero[f][j] == 'T' || tablero[f][j] == 'Q')
                    {
                        jaqueNegro = true;
                    }
                }

                // PEONES blancos
                if (i + 1 < ALTO)
                {
                    if (j + 1 < ANCHO)
                    {
                        if (tablero[i + 1][j + 1] == 'P')
                        {
                            jaqueNegro = true;
                        }
                    }
                    if (j - 1 >= 0)
                    {
                        if (tablero[i + 1][j - 1] == 'P')
                        {
                            jaqueNegro = true;
                        }
                    }
                }

                // ALFILES y REINA mirar diagonales
                for (int k = 1; i + k < ALTO && j + k < ANCHO; k++)
                {
                    if (tablero[i + k][j + k] == 'A' || tablero[i + k][j + k] == 'Q')
                    {
                        jaqueNegro = true;
                    }
                }

                for (int k = 1; i + k < ALTO && j - k >= 0; k++)
                {
                    if (tablero[i + k][j - k] == 'A' || tablero[i + k][j - k] == 'Q')
                    {
                        jaqueNegro = true;
                    }
                }

                for (int k = 1; i - k >= 0 && j + k < ANCHO; k++)
                {
                    if (tablero[i - k][j + k] == 'A' || tablero[i - k][j + k] == 'Q')
                    {
                        jaqueNegro = true;
                    }
                }

                for (int k = 1; i - k >= 0 && j - k >= 0; k++)
                {
                    if (tablero[i - k][j - k] == 'A' || tablero[i - k][j - k] == 'Q')
                    {
                        jaqueNegro = true;
                    }
                }

                // CABALLOS blancos
                if (i + 2 < ALTO && j + 1 < ANCHO)
                {
                    if (tablero[i + 2][j + 1] == 'H')
                    {
                        jaqueNegro = true;
                    }
                }
                if (i + 2 < ALTO && j - 1 >= 0)
                {
                    if (tablero[i + 2][j - 1] == 'H')
                    {
                        jaqueNegro = true;
                    }
                }
                if (i - 2 >= 0 && j + 1 < ANCHO)
                {
                    if (tablero[i - 2][j + 1] == 'H')
                    {
                        jaqueNegro = true;
                    }
                }
                if (i - 2 >= 0 && j - 1 >= 0)
                {
                    if (tablero[i - 2][j - 1] == 'H')
                    {
                        jaqueNegro = true;
                    }
                }

                if (i + 1 < ALTO && j + 2 < ANCHO)
                {
                    if (tablero[i + 1][j + 2] == 'H')
                    {
                        jaqueNegro = true;
                    }
                }
                if (i + 1 < ALTO && j - 2 >= 0)
                {
                    if (tablero[i + 1][j - 2] == 'H')
                    {
                        jaqueNegro = true;
                    }
                }
                if (i - 1 >= 0 && j + 2 < ANCHO)
                {
                    if (tablero[i - 1][j + 2] == 'H')
                    {
                        jaqueNegro = true;
                    }
                }
                if (i - 1 >= 0 && j - 2 >= 0)
                {
                    if (tablero[i - 1][j - 2] == 'H')
                    {
                        jaqueNegro = true;
                    }
                }
            }
        }
    }

    if (jaqueBlanco)
    {
        std::cout << "JAQUE al rey BLANCO\n";
    }

    if (jaqueNegro)
    {
        std::cout << "JAQUE al rey NEGRO\n";
    }
}

void jaqueMate()
{
    jaque(); // primero detectamos si hay jaque

    char reyes[2] = { 'K', 'k' };
    bool jaques[2] = { jaqueBlanco, jaqueNegro };
    std::string nombres[2] = { "BLANCO", "NEGRO" };

    for (int t = 0; t < 2; t++)
    {
        if (jaques[t] == true)
        {
            for (int i = 0; i < ALTO; i++)
            {
                for (int j = 0; j < ANCHO; j++)
                {
                    if (tablero[i][j] == reyes[t])
                    {
                        bool tieneSalida = false;

                        int nFila, nColumna;

                        nFila = i - 1; nColumna = j - 1;
                        if (nFila >= 0 && nColumna >= 0)
                        {
                            if (tablero[nFila][nColumna] == '*')
                            {
                                tieneSalida = true;
                            }
                        }

                        nFila = i - 1; nColumna = j;
                        if (nFila >= 0)
                        {
                            if (tablero[nFila][nColumna] == '*')
                            {
                                tieneSalida = true;
                            }
                        }

                        nFila = i - 1; nColumna = j + 1;
                        if (nFila >= 0 && nColumna < ANCHO)
                        {
                            if (tablero[nFila][nColumna] == '*')
                            {
                                tieneSalida = true;
                            }
                        }

                        nFila = i; nColumna = j - 1;
                        if (nFila >= 0)
                        {
                            if (tablero[nFila][nColumna] == '*')
                            {
                                tieneSalida = true;
                            }
                        }

                        nFila = i; nColumna = j + 1;
                        if (nFila < ANCHO)
                        {
                            if (tablero[nFila][nColumna] == '*')
                            {
                                tieneSalida = true;
                            }
                        }

                        nFila = i + 1; nColumna = j - 1;
                        if (nFila < ALTO && nFila >= 0)
                        {
                            if (tablero[nFila][nColumna] == '*')
                            {
                                tieneSalida = true;
                            }
                        }

                        nFila = i + 1; nColumna = j;
                        if (nFila < ALTO)
                        {
                            if (tablero[nFila][nColumna] == '*')
                            {
                                tieneSalida = true;
                            }
                        }

                        nFila = i + 1; nColumna = j + 1;
                        if (nFila < ALTO && nColumna < ANCHO)
                        {
                            if (tablero[nFila][nColumna] == '*')
                            {
                                tieneSalida = true;
                            }
                        }

                        if (tieneSalida == false)
                        {
                            std::cout << "JAQUE MATE al rey " << nombres[t] << "\n";
                        }
                    }
                }
            }
        }
    }
}

int main() {
    inicializarTablero();
    while (!reybMuerto && !reynMuerto)
    {
        imprimirTablero();
        escogerFicha();
        coronar();
        jaque();
        jaqueMate();
        system("cls");
    }
    return 0;
}