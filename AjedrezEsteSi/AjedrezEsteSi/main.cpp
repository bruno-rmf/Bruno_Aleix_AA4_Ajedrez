#include <iostream>
#define ANCHO 8
#define ALTO 8

char tablero[ALTO][ANCHO];
bool gameOver = false;
bool turno = false;

//BLANCOS SON MAYUS negros son minusculas

//falta acabar movimiento de peon
//USA: (pieza >= 'a' && pieza <= 'z') para ver si es negra y con MAYS lo mismo

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

//movimientos de cada pieza
void movimientoPieza(char pieza, int columna, int fila) {
    //un case para cada tipo de pieza separar MAYS y min
    //cada pieza a de tener matar, movimiento y limites
    switch (pieza)
    {
        //movimiento de peon negro
    case 'p':
        
        if (fila + 1 < ALTO && tablero[fila + 1][columna] == '*') {
            //si es el primer movimiento
            if (fila == 1)
            {
                int opcion;
                std::cout << "Quieres mover una casilla o dos? ";
                std::cin >> opcion;
                //mover una posicion
                if (opcion == 1)
                {
                    tablero[fila][columna] = '*';
                    tablero[fila + 1][columna] = 'p';
                }
                //mover dos posiciones
                else if (opcion == 2)
                {
                    tablero[fila][columna] = '*';
                    tablero[fila + 2][columna] = 'p';
                }
            }
            else
            {
                tablero[fila][columna] = '*';
                tablero[fila + 1][columna] = 'p';
            }
        }
        //sistema de diagonal para matar (falta)
        else if(fila + 1 < ALTO && tablero[fila + 1][columna + 1] >= 'A' && fila + 1 < ALTO && tablero[fila + 1][columna + 1] <= 'Z')
        {

        }
        break;

        //movimeitno peon blanco
    case 'P':
        //mira si la de delante no hay nadie que se mueva
        if (fila - 1 < ALTO && tablero[fila - 1][columna] == '*') {
            //si es el primer movimiento
            if (fila == 6)
            {
                int opcion;
                std::cout << "Quieres mover una casilla o dos? ";
                std::cin >> opcion;
                //mover una posicion
                if (opcion == 1)
                {
                    tablero[fila][columna] = '*';
                    tablero[fila - 1][columna] = 'P';
                }
                //mover dos posiciones
                else if (opcion == 2)
                {
                    tablero[fila][columna] = '*';
                    tablero[fila - 2][columna] = 'P';
                }
            }
            else
            {
                tablero[fila][columna] = '*';
                tablero[fila - 1][columna] = 'P';
            }
        }
        break;

    default:
        break;
    }
}

//turnos del juego si es false es jugador 1
void turnoJugador() {
    int columna, fila;
    char pieza;

    std::cout << "Dime la columna que esta la pieza: ";
    std::cin >> columna;
    std::cout << "Dime la fila en la que esta la pieza: ";
    std::cin >> fila;
    
    //restar 1 para que este de acorde con el array
    columna--;
    fila = ALTO - fila;

    //Turno Jugador 1
    if (!turno)
    {
        pieza = tablero[fila][columna];
        //comprueba si la ficha es suya sino vuelve a tirar
        if (pieza >= 'A' && pieza <= 'Z') {
            movimientoPieza(pieza, columna, fila);
            turno = true;
        }
        else {
            std::cout << "No es tu pieza. Vuelve a tirar.";
            turnoJugador();
        }

    }
    //turno jugador 2
    else {
        pieza = tablero[fila][columna];
        //comprueba si la ficha es suya sino vuelve a tirar
        if (pieza >= 'a' && pieza <= 'z') {
            movimientoPieza(pieza, columna, fila);
            turno = false;
        }
        else {
            std::cout << "No es tu pieza. Vuelve a tirar.";
            turnoJugador();
        }
    }
    
}

int main() {
    inicializarTablero();
    while (!gameOver)
    {
        imprimirTablero();
        turnoJugador();
        
        //añadir framerate
        system("cls");
    }

    return 0;
}
