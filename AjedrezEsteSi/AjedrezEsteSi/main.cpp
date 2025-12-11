#include <iostream>
#define ANCHO 8
#define ALTO 8

char tablero[ALTO][ANCHO];
bool gameOver = false;

void imprimirTablero() {
    std::cout << "  1 2 3 4 5 6 7 8 \n";
    std::cout << "1 ";
    tablero[1][1] = 't';
    std::cout << "t ";
    tablero[1][2] = 'h';
    std::cout << "h ";
    tablero[1][3] = 'b';
    std::cout << "b ";
    tablero[1][4] = 'k';
    std::cout << "k ";
    tablero[1][5] = 'q';
    std::cout << "q ";
    tablero[1][6] = 'b';
    std::cout << "b ";
    tablero[1][7] = 'h';
    std::cout << "h ";
    tablero[1][8] = 't';
    std::cout << "t \n";

    std::cout << "2 ";
    for (int i = 0; i < ANCHO; i++)
    {
        tablero[2][i] = 'p';
        std::cout << "p ";
    }
    std::cout << "\n";

    for (int i = 3; i < 7; i++)
    {
        std::cout << i << " ";
        for (int j = 0; j < ANCHO; j++)
        {
            tablero[i][j] == '*';
            std::cout << "* ";
        }
        std::cout << "\n";
    }
    std::cout << "7 ";
    for (int i = 0; i < ANCHO; i++)
    {
        tablero[7][i] = 'P';
        std::cout << "P ";
    }
    std::cout << "\n";

    std::cout << "8 ";
    tablero[8][1] = 'T';
    std::cout << "T ";
    tablero[8][2] = 'H';
    std::cout << "H ";
    tablero[8][3] = 'B';
    std::cout << "B ";
    tablero[8][4] = 'K';
    std::cout << "K ";
    tablero[8][5] = 'Q';
    std::cout << "Q ";
    tablero[8][6] = 'B';
    std::cout << "B ";
    tablero[8][7] = 'H';
    std::cout << "H ";
    tablero[8][8] = 'T';
    std::cout << "T \n";
}


int main() {
    imprimirTablero();
    return 0;
}