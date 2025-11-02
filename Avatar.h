#ifndef AVATAR_H
#define AVATAR_H
#include "Tablero.h"

/*
===============================================================================
                                CRC - AVATAR
===============================================================================

Clase:
    Avatar

Responsabilidades:
    - Representar al jugador dentro del laberinto.
    - Almacenar y actualizar su posición (x, y).
    - Controlar los movimientos del avatar (arriba, abajo, izquierda, derecha).
    - Validar los movimientos con respecto al Tablero.

Colaboradores:
    - Tablero (usa una referencia constante para validar movimientos).

===============================================================================
*/

class Avatar {
    private:
        int *x = nullptr;
        int *y = nullptr;
    public:
        //Constructor para inicializar la posicion del avatar
        Avatar(int* xinicial = nullptr, int* yinicial = nullptr);

        //Getters para obtener la posicion actual del avatar
        int getX() const;
        int getY() const;

        //Metodos para mover el avatar: retornan true si el movimiento fue exitoso.
        //Reciben el Tablero por referencia (uso de referencias para validar movimiento).
        bool moverArriba(const Tablero& t);
        bool moverAbajo(const Tablero& t);
        bool moverIzquierda(const Tablero& t);
        bool moverDerecha(const Tablero& t);
};
#endif // AVATAR_H