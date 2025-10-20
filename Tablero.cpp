#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tablero.h"
using namespace std;

const int Tablero::salidaX = columnas - 1;
const int Tablero::salidaY = filas - 1;

Tablero::Tablero() {
    srand(time(0));

    // Inicializar tablero con celdas bloqueadas (0)
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            tablero[i][j] = 0;

    // Crear un camino garantizado desde [0][0] hasta [9][9]
    int x = 0, y = 0;
    tablero[y][x] = 1;

    while (x < columnas - 1 || y < filas - 1) {
        // aleatoriamente mover derecha o abajo (si se puede)
        if ((rand() % 2 == 0 && x < columnas - 1) || y == filas - 1)
            x++;
        else if (y < filas - 1)
            y++;

        tablero[y][x] = 1;
    }

    // Rellenar aleatoriamente el resto de celdas (sin borrar el camino)
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (tablero[i][j] == 0 && rand() % 100 < 20)
                tablero[i][j] = 1;
        }
    }

    // Aseguramos inicio y salida
    tablero[0][0] = 1;
    tablero[salidaY][salidaX] = 1;
}

void Tablero::mostrarTablero(int ax, int ay) const {
    for (int y = 0; y < filas; y++) {
        for (int x = 0; x < columnas; x++) {
            if (x == ax && y == ay)
                cout << 'A';        // Avatar
            else if (x == salidaX && y == salidaY)
                cout << 'X';        // Salida
            else
                cout << (tablero[y][x] ? '.' : '#');
            cout << "\t";
        }
        cout << "\n";
    }
}

bool Tablero::celdaValida(int x, int y) const {
    return (x >= 0 && x < columnas && y >= 0 && y < filas && tablero[y][x] == 1);
}

void Tablero::getRandomCeldaValida(int &outX, int &outY) const {
    do {
        outX = rand() % columnas;
        outY = rand() % filas;
    } while (!celdaValida(outX, outY));
}
