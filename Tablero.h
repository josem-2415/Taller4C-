#ifndef TABLERO_H
#define TABLERO_H
#include <vector>

/*
===============================================================================
                                CRC - TABLERO
===============================================================================

Clase:
    Tablero

Responsabilidades:
    - Representar el laberinto como una matriz de celdas.
    - Generar un camino aleatorio garantizado hacia la salida.
    - Validar si una celda es transitable o no.
    - Mostrar el laberinto en consola.

Colaboradores:
    - Avatar (usa el Tablero para validar movimientos).
    - Game (coordina la interacción con el Tablero).

===============================================================================
*/

class Tablero {
    private:
        static const int filas = 10;
        static const int columnas = 10;
        int tablero[filas][columnas];

    public:
        static const int salidaX;
        static const int salidaY;

        // Constructor por defecto que genera un laberinto con camino garantizado
        Tablero();
        
        // Métodos públicos
        void mostrarTablero(int ax = -1, int ay = -1) const;
        bool celdaValida(int x, int y) const;
        void getRandomCeldaValida(int &outX, int &outY) const;
};

#endif //TABLERO_H
