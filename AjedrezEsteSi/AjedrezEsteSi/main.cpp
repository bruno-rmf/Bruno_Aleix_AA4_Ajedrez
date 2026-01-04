#include <iostream>
#define ANCHO 8
#define ALTO 8

char tablero[ALTO][ANCHO];
bool reybMuerto = false;
bool reynMuerto = false;
int turno = 1;
int casillaMovimiento;
char pieza;
int fila;
int columna;
bool seleccion = false;
int destinoFila, destinoColumna;
bool movimentoValido = false;
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
    tablero[7][3] = 'K';
    tablero[7][4] = 'Q';
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
void movimientos() {
    std::cout << "Escoje el destino \n";
    escogerDestino();
    //Mediante la pieza se escoge que moviemiento utilizar
    switch (pieza)
    {
        //PEONES
    case 'p':
        // Movimiento 1
        if (destinoFila == fila + 1 && destinoColumna == columna && tablero[destinoFila][destinoColumna] == '*')
        {
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'p';
        }
        //Dos Moviments
        else if (fila == 1 && destinoFila == fila + 2 && destinoColumna == columna && tablero[fila + 1][columna] == '*' && tablero[destinoFila][destinoColumna] == '*')
        {
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'p';
        }
        //Muerte en diagonal
        else if (destinoFila == fila + 1 && (destinoColumna == columna - 1 || destinoColumna == columna + 1) && tablero[destinoFila][destinoColumna] >= 'A' && tablero[destinoFila][destinoColumna] <= 'Z')
        {
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'p';
        }
        else
        {
            std::cout << "Movimiento invalido\n";
        }
        break;


    case 'P':
        // Movimiento 1
        if (destinoFila == fila - 1 && destinoColumna == columna && tablero[destinoFila][destinoColumna] == '*')
        {
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'P';
        }
        // Movimiento 2
        else if (fila == 6 && destinoFila == fila - 2 && destinoColumna == columna && tablero[fila - 1][columna] == '*' && tablero[destinoFila][destinoColumna] == '*')
        {
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'P';
        }
        //Muerte en diagonl
        else if (destinoFila == fila - 1 && (destinoColumna == columna - 1 || destinoColumna == columna + 1) && tablero[destinoFila][destinoColumna] >= 'a' && tablero[destinoFila][destinoColumna] <= 'z')
        {
            tablero[fila][columna] = '*';
            tablero[destinoFila][destinoColumna] = 'P';
        }
        else
        {
            std::cout << "Movimiento invalido\n";
        }
        break;

        //TORRES
    case 't':
        break;
    case 'T':
        break;

        //CABALLOS
    case 'c':
        break;
    case 'C':
        break;

        //ALFILES
    case 'a':
        break;
    case 'A':
        break;

        //REINAS
    case 'q':
        break;
    case 'Q':

        //REYES 
        break;
    case 'r':
        break;
    case 'R':
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

int main() {
    inicializarTablero();
    while (!reybMuerto || !reynMuerto)
    {
        imprimirTablero();
        escogerFicha();
        system("cls");
    }

    return 0;
}