#include <iostream>
#define ANCHO 8
#define ALTO 8

char tablero[ALTO][ANCHO];
bool gameOver = false;


//inicializar el tablero cuando empieza la partida
void inicializarTablero() {
    
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
void movimientoPieza() {

}

int main() {
    inicializarTablero();
    while (!gameOver)
    {
        imprimirTablero();
        //añadir framerate
        system("cls");
    }

    return 0;
}
