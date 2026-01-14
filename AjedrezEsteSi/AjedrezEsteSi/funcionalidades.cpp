#include "funcionalidades.h"
bool jaqueBlanco = false;
bool jaqueNegro = false;
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